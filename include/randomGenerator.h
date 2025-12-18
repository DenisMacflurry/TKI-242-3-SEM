#pragma once

#include "../include/generator.h"
#include <random>

namespace miit::algebra {

class RandomGenerator : public Generator {
private:
    uniform_int_distribution<int> distribution;
    mt19937 generator;

public:
    RandomGenerator(const int min, const int max);

    int generate() override;
};

}
