#include "../include/exercise.h"

namespace miit::algebra 
{

Exercise::Exercise(Matrix<int> matrix) : matrix(matrix) {}

const Matrix<int>& Exercise::get_matrix() const
{
    return matrix;
}

}