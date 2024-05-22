//
//  Breezer.h
//
//  Created by CATEDS on 2024-5-9.
//  Copyright © 2024 DT5EDU.
//  All rights reserved.
//

#ifndef _CATEDS_MS_Buzzer_
#define _CATEDS_MS_Buzzer_

#include "mbed.h"
#include <unordered_map>
#include <vector>

namespace BuzzerLib {

enum class Tune {
    C2,C2s,D2,D2s,E2,F2,F2s,G2,G2s,A2,A2s,B2, 
    C3,C3s,D3,D3s,E3,F3,F3s,G3,G3s,A3,A3s,B3,
    C4,C4s,D4,D4s,E4,F4,F4s,G4,G4s,A4,A4s,B4,
    C5,C5s,D5,D5s,E5,F5,F5s,G5,G5s,A5,A5s,B5,
    C6,C6s,D6,D6s,E6,F6,F6s,G6,G6s,A6,A6s,B6,
    Pause,Sustain
};

extern std::unordered_map<Tune,int> Tune2Freq;

class buzzer {
private:
    PwmOut IO;
public:
    buzzer(PinName Pin_PWMOUT): IO(Pin_PWMOUT) {
        IO.write(0.f);
    }
    ~buzzer() {}

    buzzer & SetTune(Tune tune_input = Tune::Pause);
    buzzer & PlayMusic(const vector<Tune> &Music, float NotePerMin);
    buzzer & PlayMusic(const vector<pair<Tune,float>> &Music, float NotePerMin);
    // example
    buzzer & exmple(void);
    // empty template
    buzzer & empty_template(void);
};

}

using BuzzerLib::buzzer;

#endif // Copyright © 2024 DT5EDU. All rights reserved.