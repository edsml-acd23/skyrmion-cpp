#include "Spins.h"
#include <stdexcept> // For std::invalid_argument
#include <cmath>     // For std::fabs and std::sqrt
#include <algorithm>  // For std::fill
#include <numeric>    // For std::accumulate
#include <random>     // For random number generation

Spins::Spins(std::vector<int> n, std::vector<float> value) {
    if (n.size() != 2) {
        throw std::invalid_argument("Length of iterable n must be 2.");
    }
    for (int i : n) {
        if (i <= 0) {
            throw std::invalid_argument("Elements of n must be positive integers.");
        }
    }
    if (value.size() != 3) {
        throw std::invalid_argument("Length of iterable value must be 3.");
    }

    size_t size = n[0] * n[1] * 3;
    array.resize(size);
    for (size_t i = 0; i < size; i += 3) {
        array[i] = value[0];
        array[i + 1] = value[1];
        array[i + 2] = value[2];
    }

    float magnitude = std::sqrt(value[0] * value[0] + value[1] * value[1] + value[2] * value[2]);
    if (std::fabs(magnitude - 1.0f) > 1e-6) {
        normalise();
    }
}

float Spins::mean() {
    float sum = std::accumulate(array.begin(), array.end(), 0.0f);
    return sum / array.size();
}

float Spins::abs() {
    float sum = 0.0f;
    for (size_t i = 0; i < array.size(); i += 3) {
        sum += computeMagnitude(i);
    }
    return sum / (array.size() / 3);
}

void Spins::normalise() {
    for (size_t i = 0; i < array.size(); i += 3) {
        float magnitude = computeMagnitude(i);
        if (magnitude != 0) {
            array[i] /= magnitude;
            array[i + 1] /= magnitude;
            array[i + 2] /= magnitude;
        }
    }
}

void Spins::randomise() {
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(0.0, 1.0);
    for (auto& val : array) {
        val = distribution(generator);
    }
}

float Spins::computeMagnitude(size_t index) const {
    float x_sq = array[index] * array[index];
    float y_sq = array[index + 1] * array[index + 1];
    float z_sq = array[index + 2] * array[index + 2];
    return std::sqrt(x_sq + y_sq + z_sq);
}
