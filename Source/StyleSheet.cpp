/*
  ==============================================================================

    StyleSheet.cpp
    Created: 9 Nov 2024 2:51:02am
    Author:  Abhinav

  ==============================================================================
*/

#include "StyleSheet.h"

namespace juce
{

    void CustomLNF::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
    {
        
        
        auto outline = slider.findColour (Slider::rotarySliderOutlineColourId);
        auto fill    = slider.findColour (Slider::rotarySliderFillColourId);

        auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);

        auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
        auto toAngle = rotaryStartAngle + sliderPosProportional * (rotaryEndAngle - rotaryStartAngle);
        auto lineW = jmin (8.0f, radius * 0.5f);
        auto arcRadius = radius - lineW * 0.5f;

        // Dial background path
        Path backgroundArc;
        backgroundArc.addCentredArc (bounds.getCentreX(),
                                     bounds.getCentreY(),
                                     arcRadius,
                                     arcRadius,
                                     0.0f,
                                     rotaryStartAngle,
                                     rotaryEndAngle,
                                     true);

        g.setColour (outline);
        g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));

        if (slider.isEnabled())
        {
            // Dial Fill path
            Path valueArc;
            valueArc.addCentredArc (bounds.getCentreX(),
                                    bounds.getCentreY(),
                                    arcRadius,
                                    arcRadius,
                                    0.0f,
                                    rotaryStartAngle,
                                    toAngle,
                                    true);

            g.setColour (fill);
            g.strokePath (valueArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
        }

        // Line
        Point<float> thumbPoint (bounds.getCentreX() + (arcRadius - 10.f) * std::cos (toAngle - MathConstants<float>::halfPi),
                                 bounds.getCentreY() + (arcRadius - 10.f) * std::sin (toAngle - MathConstants<float>::halfPi));

        g.setColour (slider.findColour (Slider::thumbColourId));
        g.drawLine(backgroundArc.getBounds().getCentreX(),
                   backgroundArc.getBounds().getCentreY(),
                   thumbPoint.getX(),
                   thumbPoint.getY(),
                   lineW);
    }
};
