#pragma once

#include "../include/generator.h"

namespace miit::algebra{
    class ConstGenerator : public Generator
    {
        int value;
    
    public:
        ConstGenerator(const int value);
    
        int generate() override;
    };
}
