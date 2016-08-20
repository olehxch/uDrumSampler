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
    sliderMaster->addListener (this);

    addAndMakeVisible (masterMeter = new Slider ("Master Meter"));
    masterMeter->setRange (0, 1, 0);
    masterMeter->setSliderStyle (Slider::LinearBarVertical);
    masterMeter->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    masterMeter->setColour (Slider::backgroundColourId, Colour (0xfff2f2f2));
    masterMeter->setColour (Slider::thumbColourId, Colours::red);
    masterMeter->setColour (Slider::rotarySliderOutlineColourId, Colour (0x99ff0404));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (100, 400);


    //[Constructor] You can add your own custom stuff here..
	sliderMaster->setValue(MathHelper::linearToDb(0.8));
	sliderMaster->setTextValueSuffix(" dB");
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

    g.fillAll (Colours::grey);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MasterLevelMeter::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    sliderMaster->setBounds (16, 304, 70, 80);
    masterMeter->setBounds (16, 16, 70, 270);
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
void MasterLevelMeter::setValue(double value)
{
	//m_levelMeter = value;
	//masterMeter->setValue(value);
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
                 fixedSize="1" initialWidth="100" initialHeight="400">
  <BACKGROUND backgroundColour="ff808080"/>
  <SLIDER name="slider Master" id="de9d1168bd238e19" memberName="sliderMaster"
          virtualName="" explicitFocusOrder="0" pos="16 304 70 80" min="-50"
          max="6" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Master Meter" id="8ee0c0f1b0343cbf" memberName="masterMeter"
          virtualName="" explicitFocusOrder="0" pos="16 16 70 270" bkgcol="fff2f2f2"
          thumbcol="ffff0000" rotaryslideroutline="99ff0404" min="0" max="1"
          int="0" style="LinearBarVertical" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
