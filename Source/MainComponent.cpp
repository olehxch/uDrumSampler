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
        setSize (500, 400);
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
    }

    void releaseResources() override
    {
    }

	bool keyPressed(const KeyPress & key, Component* originatingComponent)
	{
		char pressedKey = key.getTextCharacter();

		switch (key.getTextCharacter()) {
			case 'a': { drumSet.play("pad1"); break; }
			case 's': { drumSet.play("pad2"); break; }
			case 'd': { drumSet.play("pad3"); break; }
			case 'f': { drumSet.play("pad4"); break; }

			case 'z': { drumSet.play("pad5"); break; }
			case 'x': { drumSet.play("pad6"); break; }
			case 'c': { drumSet.play("pad7"); break; }
			case 'v': { drumSet.play("pad8"); break; }
			default: break;
		}
		return true;
	}

    //==============================================================================
    void paint (Graphics& g) override
    {
        g.fillAll (Colours::grey);
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

    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
