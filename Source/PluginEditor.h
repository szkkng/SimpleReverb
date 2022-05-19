/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "GUI/MyLookAndFeel.h"
#include "GUI/Dial.h"
#include "GUI/NameLabel.h"
#include "GUI/FreezeButton.h"

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

    Dial sizeDial,
         dampDial,
         widthDial,
         dwDial;

    FreezeButton freezeButton;

    using APVTS = juce::AudioProcessorValueTreeState;

    APVTS::SliderAttachment sizeDialAttachment,
                            dampDialAttachment,
                            widthDialAttachment,
                            dwDialAttachment;

    APVTS::ButtonAttachment freezeButtonAttachment;

    MyLookAndFeel lnf;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleReverbAudioProcessorEditor)
};
