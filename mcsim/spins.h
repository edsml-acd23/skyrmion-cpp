#ifndef SPINS_H
#define SPINS_H

#include <vector>

class Spins {
public:
    Spins(std::vector<int> n, std::vector<float> value = {0.0f, 0.0f, 1.0f});

    float mean();
    float abs();
    void normalise();
    void randomise();

private:
    std::vector<int> n;
    std::vector<float> array;

    float computeMagnitude(size_t index) const;
};

#endif // SPINS_H
