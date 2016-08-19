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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "DrumSetComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DrumSetComponent::DrumSetComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
	addAndMakeVisible(pad1);
	addAndMakeVisible(pad2);
	addAndMakeVisible(pad3);
	addAndMakeVisible(pad4);
	
	addAndMakeVisible(pad5);
	addAndMakeVisible(pad6);
	addAndMakeVisible(pad7);
	addAndMakeVisible(pad8);

    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 400);


    //[Constructor] You can add your own custom stuff here..
	// first line
	pad1.setText("Kick");
	pad1.setAudioPath(R"(C:\AudioProgramming\uDrumSampler\Audio\kick.wav)");
	pad1.setColor(Colours::red);

	pad2.setText("Snare");
	pad2.setAudioPath(R"(C:\AudioProgramming\uDrumSampler\Audio\snare.wav)");
	pad2.setColor(Colours::green);

	pad3.setText("Hi Hat 1");
	pad3.setAudioPath(R"(C:\AudioProgramming\uDrumSampler\Audio\hihatopen.wav)");
	pad3.setColor(Colours::blue);

	pad4.setText("Hi Hat 2");
	pad4.setAudioPath(R"(C:\AudioProgramming\uDrumSampler\Audio\hihatclosed.wav)");
	pad4.setColor(Colours::yellow);

	// second line
	pad5.setText("Crash 1");
	pad5.setAudioPath(R"(C:\AudioProgramming\uDrumSampler\Audio\Crash1.wav)");
	pad5.setColor(Colours::cyan);

	pad6.setText("Crash 2");
	pad6.setAudioPath(R"(C:\AudioProgramming\uDrumSampler\Audio\Crash2.wav)");
	pad6.setColor(Colours::darkcyan);

	pad7.setText("Tom 1");
	pad7.setAudioPath(R"(C:\AudioProgramming\uDrumSampler\Audio\tom10.wav)");
	pad7.setColor(Colours::gold);

	pad8.setText("Tom 2");
	pad8.setAudioPath(R"(C:\AudioProgramming\uDrumSampler\Audio\tom12.wav)");
	pad8.setColor(Colours::goldenrod);
    //[/Constructor]
}

DrumSetComponent::~DrumSetComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]
	

	
    //[Destructor]. You can add your own custom destruction code here..
	mixer.releaseResources();
    //[/Destructor]
}

//==============================================================================
void DrumSetComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::grey);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DrumSetComponent::resized()
{
	int stride = pad1.getWidth();

    //[UserPreResize] Add your own custom resize code here..
	pad1.setBounds(0, 0, pad1.getWidth(), pad1.getHeight());
	pad2.setBounds(stride, 0, pad2.getWidth(), pad2.getHeight());
	pad3.setBounds(stride * 2, 0, pad3.getWidth(), pad3.getHeight());
	pad4.setBounds(stride * 3, 0, pad4.getWidth(), pad4.getHeight());
	
	pad5.setBounds(0, stride, pad5.getWidth(), pad5.getHeight());
	pad6.setBounds(stride, stride, pad6.getWidth(), pad6.getHeight());
	pad7.setBounds(stride * 2, stride, pad7.getWidth(), pad7.getHeight());
	pad8.setBounds(stride * 3, stride, pad8.getWidth(), pad8.getHeight());
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void DrumSetComponent::getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill)
{
	mixer.getNextAudioBlock(bufferToFill);
}

void DrumSetComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
	mixer.prepareToPlay(samplesPerBlockExpected, sampleRate);

	pad1.prepareToPlay(samplesPerBlockExpected, sampleRate);
	pad2.prepareToPlay(samplesPerBlockExpected, sampleRate);
	pad3.prepareToPlay(samplesPerBlockExpected, sampleRate);
	pad4.prepareToPlay(samplesPerBlockExpected, sampleRate);

	pad5.prepareToPlay(samplesPerBlockExpected, sampleRate);
	pad6.prepareToPlay(samplesPerBlockExpected, sampleRate);
	pad7.prepareToPlay(samplesPerBlockExpected, sampleRate);
	pad8.prepareToPlay(samplesPerBlockExpected, sampleRate);

	// add to mixer
	mixer.addInputSource(&pad1.getAudioSource(), false);
	mixer.addInputSource(&pad2.getAudioSource(), false);
	mixer.addInputSource(&pad3.getAudioSource(), false);
	mixer.addInputSource(&pad4.getAudioSource(), false);

	mixer.addInputSource(&pad5.getAudioSource(), false);
	mixer.addInputSource(&pad6.getAudioSource(), false);
	mixer.addInputSource(&pad7.getAudioSource(), false);
	mixer.addInputSource(&pad8.getAudioSource(), false);
}

void DrumSetComponent::play(juce::String kitname)
{
	if (kitname == "pad1") pad1.play();
	if (kitname == "pad2") pad2.play();
	if (kitname == "pad3") pad3.play();
	if (kitname == "pad4") pad4.play();

	if (kitname == "pad5") pad5.play();
	if (kitname == "pad6") pad6.play();
	if (kitname == "pad7") pad7.play();
	if (kitname == "pad8") pad8.play();

}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DrumSetComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="800" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
