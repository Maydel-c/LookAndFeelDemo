/*
  ==============================================================================

    StyleSheet.h
    Created: 9 Nov 2024 2:51:02am
    Author:  Abhinav

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace juce
{

    class CustomLNF : public juce::LookAndFeel_V4
    {
        void drawRotarySlider (Graphics&, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider&);
    };

}
