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

#ifndef __JUCE_HEADER_39EC166C16D62D2E__
#define __JUCE_HEADER_39EC166C16D62D2E__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "DrumPadComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DrumSetComponent  : public Component
{
public:
    //==============================================================================
    DrumSetComponent ();
    ~DrumSetComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill);
	void DrumSetComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate);

	void play(juce::String name);
	void setVolume(float volume);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	MixerAudioSource mixer;

	DrumPadComponent pad1;
	DrumPadComponent pad2;
	DrumPadComponent pad3;
	DrumPadComponent pad4;
	DrumPadComponent pad5;
	DrumPadComponent pad6;
	DrumPadComponent pad7;
	DrumPadComponent pad8;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrumSetComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_39EC166C16D62D2E__
