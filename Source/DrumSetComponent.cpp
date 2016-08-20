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
struct PadInfo {
	juce::String name;
	juce::String path;
	juce::Colour color;
};



//[/MiscUserDefs]

//==============================================================================
DrumSetComponent::DrumSetComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
	juce::String absPath = File::getSpecialLocation(File::currentExecutableFile).getParentDirectory().getFullPathName();

	
	// we initialize here because static initializers for colors are initialized here
	PadInfo padInfo[16] = {
		{ "Kick", absPath + "\\Audio\\kick.wav", Colour(0xFFFF5947) },
		{ "Snare", absPath + "\\Audio\\snare.wav", Colour(0xFFFF3621) },
		{ "Hi Hat Open", absPath + "\\Audio\\hihatopen.wav", Colour(0xFFFF1800) },
		{ "Hi Hat Closed", absPath + "\\Audio\\hihatclosed.wav", Colour(0xFFE91600) },

		{ "Crash 1", absPath + "\\Audio\\Crash1.wav", Colour(0xFFDCFB47) },
		{ "Crash 2", absPath + "\\Audio\\Crash2.wav", Colour(0xFFD4FA1D) },
		{ "Rim Shot 1", absPath + "\\Audio\\rim1.wav", Colour(0xFFCFF900) },
		{ "Rim Shot 2", absPath + "\\Audio\\rim2.wav", Colour(0xFFA9CC00) },

		{ "Tom 1", absPath + "\\Audio\\tom10.wav", Colour(0xFF7AAEEC) },
		{ "Tom 2", absPath + "\\Audio\\tom12.wav", Colour(0xFF5494E1) },
		{ "Tom 3", absPath + "\\Audio\\tom16.wav", Colour(0xFF337CD4) },
		{ "Tom 4", absPath + "\\Audio\\tom20.wav", Colour(0xFF1061C3) },

		{ "Sample 13", absPath + "\\Audio\\", Colour(0xFFFFCB79) },
		{ "Sample 14", absPath + "\\Audio\\", Colour(0xFFFFBB51) },
		{ "Sample 15", absPath + "\\Audio\\", Colour(0xFFFFAD2C) },
		{ "Sample 16", absPath + "\\Audio\\", Colour(0xFFFF9C00) },
	};

	pads.resize(16);
	for (int i = 0; i < pads.size(); i++) {
		auto info = padInfo[i];

		pads.getReference(i) = new DrumPadComponent(info.name, info.color, info.path);
		addAndMakeVisible(pads[i]);
	}

    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (512, 512);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

DrumSetComponent::~DrumSetComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]
	

	
    //[Destructor]. You can add your own custom destruction code here..
	mixer.releaseResources();

	for (auto& pad : pads) delete pad;
	pads.removeRange(0, pads.size());
    //[/Destructor]
}

//==============================================================================
void DrumSetComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour(0xFF21212A));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DrumSetComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
	int size = pads.getFirst()->getWidth();		// all pads should have equal width and height
	int freeSpace = 0;	// 10px between pads

	int col = 0;
	for (int i = 0; i < pads.size(); i++) {
		int row = i % 4;
		if (i != 0 && i % 4 == 0) {
			col++;
		}
		pads[i]->setBounds(row * size + freeSpace, col * size + freeSpace, size, size);

	}
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

	for (auto& pad : pads) {
		pad->prepareToPlay(samplesPerBlockExpected, sampleRate);
		mixer.addInputSource(&pad->getAudioSource(), false);
	}
}

void DrumSetComponent::play(int padNumber)
{
	pads[padNumber]->play();
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
