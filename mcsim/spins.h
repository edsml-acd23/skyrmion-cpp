#ifndef SPINS_H
#define SPINS_H

class Spins {
public:
    Spins(Vector n, Vector value);

    float mean();

    float abs();

    float normalise();

    float randomise();
};

#endif