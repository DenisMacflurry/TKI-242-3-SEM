#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra
{
    template<typename T>
    class Exercise
    {
    protected:
        Matrix<T> matrix;
        Generator* generator;
        
    public:
        Exercise(size_t size, Generator* gen) : matrix(size), generator(gen) {}
        virtual ~Exercise() = default;
        
        void fill_matrix()
        {
            matrix.fill(*generator);
        }
        
        Matrix<T> get_matrix() const { return matrix; }
        
        virtual void Task1() = 0;
        virtual void Task2() = 0;
    };
}