#pragma once

#include "../include/exercise.h"

namespace miit::algebra {

class Task1Exercise : public Exercise {
public:
    Task1Exercise(Matrix<int> matrix);

    void task() override;
};

}