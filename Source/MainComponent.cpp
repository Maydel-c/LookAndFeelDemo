#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    juce::LookAndFeel::setDefaultLookAndFeel(&myCustomLNF);
    
    mySlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    mySlider.setRange(0.0f, 100.f);
    mySlider.setValue(25.0f);
    mySlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 25);
    addAndMakeVisible(mySlider);
    
    setSize (400, 400);
}

MainComponent::~MainComponent()
{
    juce::LookAndFeel::setDefaultLookAndFeel(nullptr);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::grey);
}

void MainComponent::resized()
{
    mySlider.setBounds(getWidth() / 2 - 100, getHeight() / 2 - 100, 200, 200);
}
