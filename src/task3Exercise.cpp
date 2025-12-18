#include "../include/task3Exercise.h"

namespace miit::algebra 
{
    Task3Exercise::Task3Exercise(Matrix<int> matrix, size_t k)
        : Exercise(matrix), k_param(k) {}

    void Task3Exercise::task() {
        Matrix<int> matrix_new(matrix.size());
        for (size_t i = 0; i < matrix.size(); ++i) { 
            if ((i + 1) <= k_param) { 
                matrix_new[i] = -(matrix[i] * matrix[i]);
            } else { 
                matrix_new[i] = matrix[i] - 1;
            }
        }
        cout << "Result array A from Task3: " << matrix_new.to_string() << endl;
    }
}