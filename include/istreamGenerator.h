#pragma once

#include "../include/generator.h"
#include <iostream> 

namespace miit::algebra {

class IStreamGenerator : public Generator {
private:
    istream& in;

public:
    IStreamGenerator(istream& in = cin);

    int generate() override;
};

}