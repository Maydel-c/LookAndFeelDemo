/*
  ==============================================================================

    StyleSheet.h
    Created: 9  Nov 2024 2:51:02am
    Author:  Abhinav

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace juce
{

class CustomLNF : public juce::LookAndFeel_V4
{
public:
    void drawRotarySlider (Graphics&, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider&);
};

class CustomDial : public Slider
{
public:
    CustomDial()
    {
        auto rotaryParams = getRotaryParameters();
        rotaryParams.startAngleRadians = juce::MathConstants<float>::pi * 1.5f;
        rotaryParams.endAngleRadians = juce::MathConstants<float>::pi * 3.f;
        setRotaryParameters(rotaryParams);
        
        setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        setRange(0.0f, 100.f);
        setValue(25.0f);
        setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 25);
        setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::orange);
        setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colours::orange);
    }
    
private:
    
    
};

}
