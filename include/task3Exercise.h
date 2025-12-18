#pragma once

#include "../include/exercise.h"

namespace miit::algebra {


class Task3Exercise : public Exercise {
private:
    size_t k_param;
public:
    Task3Exercise(Matrix<int> matrix, size_t k);

    void task() override;

};

}