/*
  ==============================================================================

   Copyright 2021, 2022 Suzuki Kengo

   Simple Reverb is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
 
   Simple Reverb is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.
 
   You should have received a copy of the GNU General Public License
   along with Simple Reverb. If not, see <http://www.gnu.org/licenses/>.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SimpleReverbProcessor.h"
#include "GUI/Dial.h"
#include "GUI/FreezeButton.h"

class EditorContent  : public juce::Component
{
public:
    EditorContent (SimpleReverbAudioProcessor& p, juce::UndoManager& um);
    
    void resized() override;

    void mouseEnter (const juce::MouseEvent& e) override;
    void mouseExit (const juce::MouseEvent& e) override;

    bool keyPressed (const juce::KeyPress& k) override;

private:
    juce::AudioProcessorValueTreeState& apvts;
    juce::UndoManager& undoManager;
    
    juce::Label sizeLabel;
    juce::Label dampLabel;
    juce::Label widthLabel;
    juce::Label dwLabel;

    Dial sizeDial;
    Dial dampDial;
    Dial widthDial;
    Dial dwDial;

    FreezeButton freezeButton;

    using APVTS = juce::AudioProcessorValueTreeState;
    APVTS::SliderAttachment sizeDialAttachment;
    APVTS::SliderAttachment dampDialAttachment;
    APVTS::SliderAttachment widthDialAttachment;
    APVTS::SliderAttachment dwDialAttachment;

    APVTS::ButtonAttachment freezeButtonAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EditorContent)
};
