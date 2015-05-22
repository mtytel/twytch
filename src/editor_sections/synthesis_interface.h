/* Copyright 2013-2015 Matt Tytel
 *
 * twytch is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * twytch is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with twytch.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#ifndef SYNTHESIS_INTERFACE_H
#define SYNTHESIS_INTERFACE_H

#include "JuceHeader.h"
#include "twytch_engine.h"

#include "envelope_section.h"
#include "feedback_section.h"
#include "filter_section.h"
#include "lfo_section.h"
#include "reverb_section.h"
#include "step_sequencer_section.h"

#include "modulation_button.h"
#include "xy_pad.h"

class SynthesisInterface  : public SynthSection {
  public:
    SynthesisInterface(mopo::control_map controls);
    ~SynthesisInterface();

    void setSliderUnits();
    void createTempoSliders();
    void markBipolarSliders();
    void setDefaultDoubleClickValues();
    void setStyles();
    void createStepSequencerSliders();

    void setValue(std::string name, mopo::mopo_float value,
                  NotificationType notification = sendNotificationAsync);
    void modulationChanged(std::string source);

    SynthSlider* getSlider(std::string name);

    void paint(Graphics& g);
    void resized();
    void sliderValueChanged(Slider* sliderThatWasMoved);
    void buttonClicked(Button* buttonThatWasClicked);

  private:
    ScopedPointer<EnvelopeSection> amplitude_envelope_section_;
    ScopedPointer<FeedbackSection> feedback_section_;
    ScopedPointer<EnvelopeSection> filter_envelope_section_;
    ScopedPointer<FilterSection> filter_section_;
    ScopedPointer<LfoSection> mono_lfo_1_section_;
    ScopedPointer<LfoSection> mono_lfo_2_section_;
    ScopedPointer<LfoSection> poly_lfo_section_;
    ScopedPointer<ReverbSection> reverb_section_;
    ScopedPointer<StepSequencerSection> step_sequencer_section_;

    ScopedPointer<SynthSlider> delay_tempo_;
    ScopedPointer<WaveViewer> osc_1_wave_display_;
    ScopedPointer<WaveViewer> osc_2_wave_display_;
    ScopedPointer<SynthSlider> polyphony_;
    ScopedPointer<SynthSlider> portamento_;
    ScopedPointer<SynthSlider> pitch_bend_range_;
    ScopedPointer<SynthSlider> cross_modulation_;
    ScopedPointer<SynthSlider> portamento_type_;
    ScopedPointer<SynthSlider> osc_mix_;
    ScopedPointer<SynthSlider> osc_2_transpose_;
    ScopedPointer<SynthSlider> osc_2_tune_;
    ScopedPointer<SynthSlider> volume_;
    ScopedPointer<SynthSlider> delay_feedback_;
    ScopedPointer<SynthSlider> delay_dry_wet_;
    ScopedPointer<SynthSlider> velocity_track_;
    ScopedPointer<WaveSelector> osc_1_waveform_;
    ScopedPointer<WaveSelector> osc_2_waveform_;
    ScopedPointer<ToggleButton> formant_on_;
    ScopedPointer<XYPad> formant_xy_pad_;
    ScopedPointer<SynthSlider> formant_x_;
    ScopedPointer<SynthSlider> formant_y_;
    ScopedPointer<SynthSlider> osc_1_tune_;
    ScopedPointer<SynthSlider> delay_frequency_;
    ScopedPointer<SynthSlider> osc_1_transpose_;
    ScopedPointer<SynthSlider> stutter_frequency_;
    ScopedPointer<ToggleButton> stutter_on_;
    ScopedPointer<SynthSlider> stutter_resample_frequency_;
    ScopedPointer<TempoSelector> delay_sync_;
    ScopedPointer<SynthSlider> osc_1_unison_detune_;
    ScopedPointer<SynthSlider> osc_2_unison_detune_;
    ScopedPointer<SynthSlider> osc_1_unison_voices_;
    ScopedPointer<SynthSlider> osc_2_unison_voices_;
    ScopedPointer<ModulationButton> filter_envelope_mod_;
    ScopedPointer<ModulationButton> amplitude_envelope_mod_;
    ScopedPointer<ModulationButton> step_sequencer_mod_;
    ScopedPointer<ModulationButton> mono_lfo_1_mod_;
    ScopedPointer<ModulationButton> mono_lfo_2_mod_;
    ScopedPointer<ModulationButton> poly_lfo_mod_;
    ScopedPointer<ModulationButton> aftertouch_mod_;
    ScopedPointer<ModulationButton> note_mod_;
    ScopedPointer<ModulationButton> velocity_mod_;
    ScopedPointer<ModulationButton> mod_wheel_mod_;
    ScopedPointer<ModulationButton> pitch_wheel_mod_;
    ScopedPointer<ToggleButton> legato_;
    ScopedPointer<ToggleButton> unison_1_harmonize_;
    ScopedPointer<ToggleButton> unison_2_harmonize_;
    Path internalPath1;
    Path internalPath2;
    Path internalPath3;
    Path internalPath4;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthesisInterface)
};

#endif // SYNTHESIS_INTERFACE_H