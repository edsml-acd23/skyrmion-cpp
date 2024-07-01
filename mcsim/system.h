#ifndef SYSTEM_H
#define SYSTEM_H

#include "spins.h"

class System {
public:
    System(Spins s, Vector B, float K, Vector u, float J, float D);

    float energy();

    float zeeman();

    float anisotropy();

    float exchange();

    float dmi();
};
#endif