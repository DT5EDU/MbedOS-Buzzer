#include "Buzzer.h"

namespace BuzzerLib {

std::unordered_map<Tune,int> Tune2Freq = {
    // 2nd
    {Tune::C2, 131}, {Tune::C2s,139},
    {Tune::D2, 147}, {Tune::D2s,156},
    {Tune::E2, 165}, {Tune::F2, 175},
    {Tune::F2s,185}, {Tune::G2, 196},
    {Tune::G2s,208}, {Tune::A2, 220},
    {Tune::A2s,233}, {Tune::B2, 247},
    // 3rd
    {Tune::C3, 262}, {Tune::C3s,277},
    {Tune::D3, 294}, {Tune::D3s,311},
    {Tune::E3, 330}, {Tune::F3, 349},
    {Tune::F3s,370}, {Tune::G3, 392},
    {Tune::G3s,415}, {Tune::A3, 440},
    {Tune::A3s,466}, {Tune::B3, 494},
    // 4th
    {Tune::C4, 523}, {Tune::C4s,554},
    {Tune::D4, 587}, {Tune::D4s,622},
    {Tune::E4, 659}, {Tune::F4, 698},
    {Tune::F4s,740}, {Tune::G4, 784},
    {Tune::G4s,831}, {Tune::A4, 880},
    {Tune::A4s,932}, {Tune::B4, 988},
    // 5th
    {Tune::C5, 1047},{Tune::C5s,1109},
    {Tune::D5, 1175},{Tune::D5s,1245},
    {Tune::E5, 1319},{Tune::F5, 1397},
    {Tune::F5s,1480},{Tune::G5, 1568},
    {Tune::G5s,1661},{Tune::A5, 1760},
    {Tune::A5s,1865},{Tune::B5, 1976},
    // 6th
    {Tune::C6, 2093},{Tune::C6s,2217},
    {Tune::D6, 2349},{Tune::D6s,2489},
    {Tune::E6, 2637},{Tune::F6, 2794},
    {Tune::F6s,2960},{Tune::G6, 3136},
    {Tune::G6s,3322},{Tune::A6, 3520},
    {Tune::A6s,3729},{Tune::B6, 3951},
};

buzzer & buzzer::SetTune(Tune tune_input) {
    if (tune_input == Tune::Pause) {
        IO.write(1.f);
    }
    else if (tune_input != Tune::Sustain) {
        IO.period(1.f/(Tune2Freq[tune_input]));
        IO.write(0.5f);
    }
    return *this;
}

buzzer & buzzer::PlayMusic(const vector<Tune> &Music, float NotePerMin) {
    auto delay_time = (int32_t)(60000/NotePerMin);
    for (auto &note: Music) {
        SetTune(note);
        ThisThread::sleep_for(delay_time);
    }
    SetTune();
    return *this;
};

buzzer & buzzer::PlayMusic(const vector<pair<Tune,float>> &Music, float NotePerMin) {
    auto delay_time = 60000/NotePerMin;
    for (auto &[note,beat]: Music) {
        SetTune(note);
        ThisThread::sleep_for(uint32_t(beat * delay_time));
    }
    SetTune();
    return *this;
};

// This example music is from "Bocchi The Rock" (孤独摇滚)
buzzer & buzzer::exmple(void) {
    std::vector<pair<Tune,float>> music = {
        {Tune::C5,1}, {Tune::B4,1}, {Tune::G4,1}, {Tune::G4,0.5}, {Tune::A4,0.5}, {Tune::A4,0.5}, {Tune::A4,0.5}, {Tune::G4,0.5}, {Tune::A4,0.5}, {Tune::A4,0.5}, {Tune::A4,0.5}, 
        {Tune::B4,1}, {Tune::C5,1}, {Tune::D5,1}, {Tune::B4,1}, {Tune::B4,1}, {Tune::C5,1}, {Tune::B4,1}, {Tune::G4,1}, {Tune::E4,1}, {Tune::Pause,0.5},
        {Tune::E4,0.5}, {Tune::A4,0.5}, {Tune::G4,0.5}, {Tune::E4,0.5}, {Tune::A3,0.5}, {Tune::D4,0.5}, {Tune::E4,1}, {Tune::A3,0.5}, {Tune::D4,0.5}, {Tune::E4,1}, {Tune::A3,0.5}, {Tune::D4,0.5}, {Tune::E4,1},
        {Tune::A3,0.5}, {Tune::D4,0.5}, {Tune::E4,1}, {Tune::G4,0.5}, {Tune::E4,0.5}, {Tune::D4,1}, {Tune::E4,1}, {Tune::D4,1}, {Tune::C4,1}, {Tune::D4,1}, {Tune::E4,2},
        {Tune::A4,1}, {Tune::G4,1}, {Tune::G4,0.5}, {Tune::A4,0.5}, {Tune::A4,1}, {Tune::G4,0.5}, {Tune::A4,0.5}, {Tune::A4,1}, {Tune::B4,1}, {Tune::C5,1}, {Tune::D5,1}, {Tune::B4,1}, {Tune::G4,2},
        {Tune::F5,1.5}, {Tune::E5,0.5}, {Tune::E5,2}, {Tune::C5,1}, {Tune::D5,1}, {Tune::E5,1}, {Tune::F5,0.5}, {Tune::E5,0.5}, {Tune::E5,0.5}, {Tune::D5,0.5}, {Tune::C5,0.5}, {Tune::B4,0.5}, {Tune::B4,1},
        {Tune::A4,0.5}, {Tune::B4,0.5}, {Tune::B4,1}, {Tune::C5,0.5}, {Tune::C5,3}
    };
    PlayMusic(music, 193);
    return *this;
}

// empty template
buzzer & buzzer::empty_template(void) {
    std::vector<pair<Tune,float>> music = {
        // Writer your music here
    };
    PlayMusic(music, 100); // Remember to change the speed of the music
    return *this;
}

}