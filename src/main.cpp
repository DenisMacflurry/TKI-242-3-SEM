#include "../include/matrix.h"
#include "../include/randomGenerator.h"
#include "../include/istreamGenerator.h"
#include "../include/task1Exercise.h"
#include "../include/task2Exercise.h"
#include "../include/task3Exercise.h"
#include <iostream>
#include <stdexcept>

using namespace std;

enum FillMethod {
    Random = 0,
    UserInput = 1
};

template<typename T, typename GeneratorType>
void fillMatrixWithGenerator(miit::algebra::Matrix<T>& matrix, GeneratorType& generator);

int pInput(void);

int input(void);

int main(void) 
{
    namespace alg = miit::algebra;
    cout << "Enter array size: " << endl;

    size_t size = pInput();

    cout << "Choose array fill method: " << Random << " - random numbers, " << UserInput << " - user input" << endl;

    size_t choice = pInput();

    alg::Matrix<int> matrix(size);

    switch (choice) {
        case Random: {
            cout << "Filling array with random numbers..." << endl;
            cout << "Enter range: [a, b] : " << endl;
            int a = input();
            int b = input();
            if (a > b)
            {
                throw range_error("Invalid range");
            }
            alg::RandomGenerator rand_gen(a, b);
            fillMatrixWithGenerator(matrix, rand_gen);
            break;
        }
        case UserInput:
        {
            cout << "Enter " << size << " integers:" << endl;
            alg::IStreamGenerator istream_gen(cin);
            fillMatrixWithGenerator(matrix, istream_gen);
            break;
        }
        default:
            cerr << "Wrong value, enter 0 or 1" << endl;
            return 1;
    }

    cout << "Initial array: " << matrix.to_string() << endl;

    cout << "\n--- Executing Task 1 (Replace first negative with first positive) ---" << endl;
    alg::Task1Exercise task1(matrix);
    cout << "Array before Task1: " << task1.get_matrix().to_string() << endl;
    task1.task(); 
    cout << "Array after Task1: " << task1.get_matrix().to_string() << endl;

    cout << "\n--- Executing Task 2 (Inserting k between different signs) ---" << endl;
    cout << "Enter value K to insert: ";
        int k = input();
    alg::Task2Exercise task2(task1.get_matrix(), k);
    cout << "Array before Task2: " << task2.get_matrix().to_string() << endl;
    task2.task();
    cout << "Array after Task2: " << task2.get_matrix().to_string() << endl;

    cout << "\n--- Executing Task 3 (Create array A from array D using formula) ---" << endl;
    cout << "Enter value K for Task3: ";
    size_t k_index = pInput();
    alg::Task3Exercise task3(task2.get_matrix(), k_index);
    cout << "Input array D for Task3: " << task3.get_matrix().to_string() << endl;
    task3.task();

    return 0;
}

template<typename T, typename GeneratorType>
void fillMatrixWithGenerator(miit::algebra::Matrix<T>& matrix, GeneratorType& generator) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        matrix[i] = generator.generate();
    }
}

int pInput(void)
{
    int value = 0;
    cin >> value;
    if (cin.fail() || value < 0)
    {
        cin.clear();
        throw("Entered value must be a positive number!");
    }
    return value;
}

int input(void)
{
    int value = 0;
    cin >> value;
    if (cin.fail())
    {
        cin.clear();
        throw("Entered value must be a number!");
    }
    return value;
}