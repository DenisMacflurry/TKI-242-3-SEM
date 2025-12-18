#include "../include/istreamGenerator.h"

namespace miit::algebra
{
    IStreamGenerator::IStreamGenerator(istream& in) : in(in) {}

    int IStreamGenerator::generate() {
        int value = 0;
        in >> value;
        return value;
    }
}