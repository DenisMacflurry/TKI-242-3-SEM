#pragma once
#include "Generator.h"
#include <string>
#include <stdexcept>

namespace miit::algebra
{
    class Generator 
    {
    public:
        virtual double generate() = 0;
        virtual ~Generator() = default;
    };

    template<typename T>
    class Matrix
    {
    private:
        T* data;
        size_t size;
        
    public:
        // Конструкторы по умолчанию
        Matrix() : data(nullptr), size(0) {}

        Matrix(size_t size) : size(size)
        {
            data = new T[size];
        }

        Matrix(const Matrix& other) : size(other.size)
        {
            data = new T[size];
            for (size_t i = 0; i < size; ++i)
            {
                data[i] = other.data[i];
            }
        }

        Matrix(Matrix&& other) noexcept : data(other.data), size(other.size)
        {
            other.data = nullptr;
            other.size = 0;
        }

        // Деструктор
        ~Matrix()
        {
            delete[] data;
        }

        // Операторы присваивания
        Matrix& operator=(const Matrix& other)
        {
            if (this != &other)
            {
                delete[] data;
                size = other.size;
                data = new T[size];
                for (size_t i = 0; i < size; ++i)
                {
                    data[i] = other.data[i];
                }
            }
            return *this;
        }

        Matrix& operator=(Matrix&& other) noexcept
        {
            if (this != &other)
            {
                delete[] data;
                data = other.data;
                size = other.size;
                other.data = nullptr;
                other.size = 0;
            }
            return *this;
        }

        // Операторы сдвига
        Matrix operator<<(int shift) const
        {
            Matrix result(size);
            shift = shift % size;
            for (size_t i = 0; i < size; ++i)
            {
                result.data[(i + shift) % size] = data[i];
            }
            return result;
        }

        Matrix operator>>(int shift) const
        {
            Matrix result(size);
            shift = shift % size;
            for (size_t i = 0; i < size; ++i)
            {
                result.data[i] = data[(i + shift) % size];
            }
            return result;
        }

        // Оператор разыменования
        T& operator[](size_t index)
        {
            if (index >= size)
            {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        const T& operator[](size_t index) const
        {
            if (index >= size)
            {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        // Методы
        std::string to_string() const
        {
            std::ostringstream oss;
            oss << "[";
            for (size_t i = 0; i < size; ++i)
            {
                oss << data[i];
                if (i < size - 1)
                {
                    oss << ", ";
                }
            }
            oss << "]";
            return oss.str();
        }

        size_t get_size() const
        {
            return size;
        }

        void fill(Generator& generator)
        {
            for (size_t i = 0; i < size; ++i)
            {
                data[i] = static_cast<T>(generator.generate());
            }
        }
    };

    // Явные инстанцирования для часто используемых типов
    template class Matrix<int>;
    template class Matrix<double>;
}
