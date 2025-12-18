#include "../include/task1Exercise.h"
#include <cmath>

namespace miit::algebra 
{
    Task1Exercise::Task1Exercise(Matrix<int> matrix) : Exercise(matrix) {}

    void Task1Exercise::task() {
        int max_abs_neg_index = -1;

        for (size_t i = 0; i < matrix.size(); ++i) {
            if (matrix[i] < 0) {
                if (max_abs_neg_index == -1 || std::abs(matrix[i]) > std::abs(matrix[max_abs_neg_index])) {
                    max_abs_neg_index = static_cast<int>(i);
                }
            }
        }

        if (max_abs_neg_index != -1) {
            matrix[max_abs_neg_index] = 0;
        }
    }
}