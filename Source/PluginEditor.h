/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "LookAndFeel/CustomLookAndFeel.h"
#include "Components/RotarySlider.h"
#include "Components/NameLabel.h"

//==============================================================================
/**
*/
class SimpleReverbAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SimpleReverbAudioProcessorEditor (SimpleReverbAudioProcessor&, juce::UndoManager& um);
    ~SimpleReverbAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    bool keyPressed (const juce::KeyPress& key) override;

private:
    SimpleReverbAudioProcessor& audioProcessor;

    juce::UndoManager& undoManager;

    NameLabel sizeLabel,
              dampLabel,
              widthLabel,
              dwLabel;

    RotarySlider sizeSlider,
                 dampSlider,
                 widthSlider,
                 dwSlider;

    juce::TextButton freezeButton;

    using APVTS = juce::AudioProcessorValueTreeState;

    APVTS::SliderAttachment sizeSliderAttachment,
                            dampSliderAttachment,
                            widthSliderAttachment,
                            dwSliderAttachment;

    APVTS::ButtonAttachment freezeAttachment;

    CustomLookAndFeel customLookAndFeel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleReverbAudioProcessorEditor)
};
