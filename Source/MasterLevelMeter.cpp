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

#include "MasterLevelMeter.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MasterLevelMeter::MasterLevelMeter ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (sliderMaster = new Slider ("slider Master"));
    sliderMaster->setRange (-50, 6, 0);
    sliderMaster->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sliderMaster->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sliderMaster->setColour (Slider::backgroundColourId, Colour (0x00ffffff));
    sliderMaster->setColour (Slider::trackColourId, Colour (0xff94ff00));
    sliderMaster->setColour (Slider::rotarySliderFillColourId, Colour (0xfff92c50));
    sliderMaster->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff27252b));
    sliderMaster->setColour (Slider::textBoxBackgroundColourId, Colours::white);
    sliderMaster->addListener (this);

    addAndMakeVisible (masterMeter = new Slider ("Master Meter"));
    masterMeter->setRange (-60, 6, 0);
    masterMeter->setSliderStyle (Slider::LinearBarVertical);
    masterMeter->setTextBoxStyle (Slider::NoTextBox, true, 10, 20);
    masterMeter->setColour (Slider::backgroundColourId, Colour (0x3dffffff));
    masterMeter->setColour (Slider::thumbColourId, Colour (0xfff92c50));
    masterMeter->setColour (Slider::trackColourId, Colour (0x7fffffff));
    masterMeter->setColour (Slider::rotarySliderOutlineColourId, Colour (0x99ff0404));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (64, 512);


    //[Constructor] You can add your own custom stuff here..
	sliderMaster->setValue(MathHelper::linearToDb(0.8));
	sliderMaster->setTextValueSuffix(" dB");

	setVolume(MathHelper::linearToDb(0.0));
    //[/Constructor]
}

MasterLevelMeter::~MasterLevelMeter()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sliderMaster = nullptr;
    masterMeter = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MasterLevelMeter::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff21212a));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MasterLevelMeter::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    sliderMaster->setBounds (8, getHeight() - 8 - 80, 48, 80);
    masterMeter->setBounds (8, 16, 48, 400);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MasterLevelMeter::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderMaster)
    {
        //[UserSliderCode_sliderMaster] -- add your slider handling code here..
		masterVolume = MathHelper::DbToLinear(sliderMaster->getValue());
        //[/UserSliderCode_sliderMaster]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MasterLevelMeter::setVolume(float value)
{
	//m_levelMeter = value;
	masterMeter->setValue(value);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MasterLevelMeter" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="64" initialHeight="512">
  <BACKGROUND backgroundColour="ff21212a"/>
  <SLIDER name="slider Master" id="de9d1168bd238e19" memberName="sliderMaster"
          virtualName="" explicitFocusOrder="0" pos="8 8Rr 48 80" bkgcol="ffffff"
          trackcol="ff94ff00" rotarysliderfill="fff92c50" rotaryslideroutline="ff27252b"
          textboxbkgd="ffffffff" min="-50" max="6" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Master Meter" id="8ee0c0f1b0343cbf" memberName="masterMeter"
          virtualName="" explicitFocusOrder="0" pos="8 16 48 400" bkgcol="3dffffff"
          thumbcol="fff92c50" trackcol="7fffffff" rotaryslideroutline="99ff0404"
          min="-60" max="6" int="0" style="LinearBarVertical" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="10" textBoxHeight="20" skewFactor="1"
          needsCallback="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
