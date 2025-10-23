#include <iostream>
#include "Matrix.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ConcreteExercise.h"

using namespace miit::algebra;

int main()
{
    // Демонстрация работы с различными генераторами
    const size_t SIZE = 5;
    
    // Заполнение случайными числами
    std::cout << "=== Random Generator Demo ===" << std::endl;
    RandomGenerator random_gen(1, 100);
    ConcreteExercise<int> ex1(SIZE, &random_gen);
    ex1.fill_matrix();
    ex1.Task1();
    ex1.Task2();
    
    std::cout << "\n=== Stream Generator Demo ===" << std::endl;
    // Заполнение с клавиатуры
    std::cout << "Enter " << SIZE << " integers: ";
    IStreamGenerator stream_gen;
    ConcreteExercise<int> ex2(SIZE, &stream_gen);
    ex2.fill_matrix();
    ex2.Task1();
    ex2.Task2();
    
    // Демонстрация операторов
    std::cout << "\n=== Operators Demo ===" << std::endl;
    Matrix<int> m1(SIZE);
    RandomGenerator gen(10, 50);
    m1.fill(gen);
    
    std::cout << "Original: " << m1.to_string() << std::endl;
    std::cout << "Left shift 1: " << (m1 << 1).to_string() << std::endl;
    std::cout << "Right shift 2: " << (m1 >> 2).to_string() << std::endl;
    
    // Демонстрация оператора индекса
    std::cout << "\nElement at index 2: " << m1[2] << std::endl;
    
    return 0;
}