#pragma once

#include "../include/exercise.h"

namespace miit::algebra {

class Task2Exercise : public Exercise {
private:
    int k_to_insert;
public:
    Task2Exercise(Matrix<int> matrix, int k_value);

    void task() override;
};

}