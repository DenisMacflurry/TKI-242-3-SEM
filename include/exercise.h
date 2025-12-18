#pragma once
#include "../include/matrix.h"
#include "../include/generator.h"
#include <iostream>

using namespace std;

namespace miit::algebra {

class Exercise {
protected:
    Matrix<int> matrix;
public:
    Exercise(Matrix<int> matrix);

    virtual ~Exercise() = default;

    const Matrix<int>& get_matrix() const;

    virtual void task() = 0;
};

}