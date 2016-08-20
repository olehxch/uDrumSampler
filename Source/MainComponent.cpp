/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "DrumSetComponent.h"
#include "MasterLevelMeter.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public AudioAppComponent, public KeyListener
{
public:
    //==============================================================================
	MainContentComponent()
    {
        setSize (576, 512);
        setAudioChannels (0, 2);

		addKeyListener(this);

		addAndMakeVisible(drumSet);
		addAndMakeVisible(masterMeter);
    }

    ~MainContentComponent()
    {
        shutdownAudio();
    }
	
    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
		drumSet.prepareToPlay(samplesPerBlockExpected, sampleRate);
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        bufferToFill.clearActiveBufferRegion();
		drumSet.getNextAudioBlock(bufferToFill);

		bufferToFill.buffer->applyGain(masterMeter.getVolume());

		//masterMeter.setVolume(bufferToFill.buffer->getMagnitude(0, bufferToFill.numSamples));
    }

    void releaseResources() override
    {
    }

	bool keyPressed(const KeyPress & key, Component* originatingComponent)
	{
		char pressedKey = key.getTextCharacter();
		
		for (int i = 0; i < 16; i++) {
			if (mappedKeys[i] == pressedKey) drumSet.play(i);
		}
		
		return true;
	}

    //==============================================================================
    void paint (Graphics& g) override
    {
        g.fillAll (Colour(0xFF21212A));
		//masterMeter.repaint();
    }

    void resized() override
    {
		masterMeter.setBounds(getWidth() - masterMeter.getWidth(), 0, masterMeter.getWidth(), masterMeter.getHeight());
		drumSet.setBounds(0, 0, drumSet.getWidth(), drumSet.getHeight());
    }


private:
    //==============================================================================
	MasterLevelMeter masterMeter;
	DrumSetComponent drumSet;

	const char mappedKeys[16] = {	'1', '2', '3', '4',
									'q', 'w', 'e', 'r',
									'a', 's', 'd', 'f',
									'z', 'x', 'c', 'v'
								};
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
