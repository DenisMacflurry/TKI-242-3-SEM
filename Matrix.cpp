#include "Matrix.h"
#include "Generator.h"
#include <sstream>
#include <algorithm>

namespace miit::algebra
{
    template<typename T>
    Matrix<T>::Matrix() : data(nullptr), size(0) {}
    
    template<typename T>
    Matrix<T>::Matrix(size_t size) : size(size)
    {
        data = new T[size];
    }
    
    template<typename T>
    Matrix<T>::Matrix(const Matrix& other) : size(other.size)
    {
        data = new T[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }
    
    template<typename T>
    Matrix<T>::Matrix(Matrix&& other) noexcept : data(other.data), size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
    }
    
    template<typename T>
    Matrix<T>::~Matrix()
    {
        delete[] data;
    }
    
    template<typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix& other)
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
    
    template<typename T>
    Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept
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
    
    template<typename T>
    Matrix<T> Matrix<T>::operator<<(int shift) const
    {
        Matrix result(size);
        shift = shift % size;
        for (size_t i = 0; i < size; ++i)
        {
            result.data[(i + shift) % size] = data[i];
        }
        return result;
    }
    
    template<typename T>
    Matrix<T> Matrix<T>::operator>>(int shift) const
    {
        Matrix result(size);
        shift = shift % size;
        for (size_t i = 0; i < size; ++i)
        {
            result.data[i] = data[(i + shift) % size];
        }
        return result;
    }
    
    template<typename T>
    T& Matrix<T>::operator[](size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    template<typename T>
    const T& Matrix<T>::operator[](size_t index) const
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    template<typename T>
    std::string Matrix<T>::to_string() const
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
    
    template<typename T>
    size_t Matrix<T>::get_size() const
    {
        return size;
    }
    
    template<typename T>
    void Matrix<T>::fill(Generator& generator)
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = static_cast<T>(generator.generate());
        }
    }
    
    // Явные инстанцирования для часто используемых типов
    template class Matrix<int>;
    template class Matrix<double>;
}