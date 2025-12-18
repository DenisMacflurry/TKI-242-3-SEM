#include "../include/task2Exercise.h"

namespace miit::algebra 
{
    Task2Exercise::Task2Exercise(Matrix<int> matrix, int k_value)
        : Exercise(matrix), k_to_insert(k_value) {}

    void Task2Exercise::task() {
        if (matrix.size() < 2) return;

        size_t insertions = 0;
        for (size_t i = 0; i < matrix.size() - 1; ++i) {
            if ((matrix[i] > 0 && matrix[i+1] < 0) || (matrix[i] < 0 && matrix[i+1] > 0)) {
                insertions++;
            }
        }

        Matrix<int> new_matrix(matrix.size() + insertions);
        size_t write_idx = 0;

        for (size_t i = 0; i < matrix.size(); ++i) {
            new_matrix[write_idx++] = matrix[i];
            
            if (i < matrix.size() - 1) {
                if ((matrix[i] > 0 && matrix[i+1] < 0) || (matrix[i] < 0 && matrix[i+1] > 0)) {
                    new_matrix[write_idx++] = k_to_insert;
                }
            }
        }

        matrix = std::move(new_matrix);
    }
}