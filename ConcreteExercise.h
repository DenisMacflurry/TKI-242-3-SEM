#pragma once
#include "Exercise.h"
#include <iostream>

namespace miit::algebra
{
    template<typename T>
    class ConcreteExercise : public Exercise<T>
    {
    public:
        ConcreteExercise(size_t size, Generator* gen) : Exercise<T>(size, gen) {}
        
        void Task1() override
        {
            std::cout << "Task 1: Matrix content - " << this->matrix.to_string() << std::endl;
            
            // Пример задачи: найти сумму элементов
            T sum = 0;
            for (size_t i = 0; i < this->matrix.get_size(); ++i)
            {
                sum += this->matrix[i];
            }
            std::cout << "Sum of elements: " << sum << std::endl;
        }
        
        void Task2() override
        {
            std::cout << "Task 2: Matrix operations" << std::endl;
            
            // Пример задачи: сдвиг массива
            auto shifted_left = this->matrix << 2;
            std::cout << "Shifted left by 2: " << shifted_left.to_string() << std::endl;
            
            auto shifted_right = this->matrix >> 1;
            std::cout << "Shifted right by 1: " << shifted_right.to_string() << std::endl;
        }
    };
}