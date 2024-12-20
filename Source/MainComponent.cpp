#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    juce::LookAndFeel::setDefaultLookAndFeel(&myCustomLNF);
    
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
    
    g.fillAll (juce::Colours::grey);
    
    
}

void MainComponent::resized()
{
    mySlider.setBounds(getWidth() / 2 - 100, getHeight() / 2 - 100, 200, 200);
}
