#include "../include/constantGenerator.h"

namespace miit::algebra{
    ConstGenerator::ConstGenerator(const int value) : value(value) {};

    int ConstGenerator::generate() { return value; }
}