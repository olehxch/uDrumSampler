/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_46619F8651A80C50__
#define __JUCE_HEADER_46619F8651A80C50__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "ResourceComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DrumPadComponent  : public Component,
                          public ButtonListener
{
public:
    //==============================================================================
    DrumPadComponent ();
    ~DrumPadComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void setColor(Colour c);
	void setText(juce::String text);
	void setAudioSample(char* sample, int len);
	void setAudioPath(juce::String path);

	AudioTransportSource& getAudioSource();
	void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill);
	void prepareToPlay(int samplesPerBlockExpected, double sampleRate);

	void play();
	void setVolume(float volume);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Colour m_color;
	juce::String m_text;

	char* m_sample;
	int m_len;

	// audio player
	AudioFormatManager formatManager;
	ScopedPointer<AudioFormatReaderSource> readerSource;
	AudioTransportSource transportSource;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ImageButton> imageButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrumPadComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_46619F8651A80C50__
