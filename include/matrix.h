#pragma once

#include <memory> 
#include <string> 
#include <sstream> 
#include <stdexcept> 

namespace miit::algebra {

template<typename T>
class Matrix {
private:
    unique_ptr<T[]> data; 
    size_t size_val;           
public:
    Matrix();

    explicit Matrix(size_t size);

    Matrix(const Matrix& other);

    Matrix(Matrix&& other) noexcept;

    Matrix& operator=(const Matrix& other);

    Matrix& operator=(Matrix&& other) noexcept;

    const T& operator[](size_t index) const;

    T& operator[](size_t index);

    size_t size() const;

    string to_string() const;

    template<typename Gen>
    void fill(Gen& gen);

};

template<typename T>
Matrix<T>::Matrix() : data(nullptr), size_val(0) {}

template<typename T>
Matrix<T>::Matrix(size_t size) : data(make_unique<T[]>(size)), size_val(size) {}

template<typename T>
Matrix<T>::Matrix(const Matrix& other) : data(make_unique<T[]>(other.size_val)), size_val(other.size_val) {
    for (size_t i = 0; i < size_val; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
Matrix<T>::Matrix(Matrix&& other) noexcept : data(move(other.data)), size_val(other.size_val) {
    other.size_val = 0; 
}
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other) {
    if (this != &other) { 
        auto new_data = make_unique<T[]>(other.size_val);
        for (size_t i = 0; i < other.size_val; ++i) {
            new_data[i] = other.data[i];
        }
        data = move(new_data);
        size_val = other.size_val;
    }
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept {
    if (this != &other) { 
        data = move(other.data);
        size_val = other.size_val;
        other.size_val = 0; 
    }
    return *this;
}

template<typename T>
const T& Matrix<T>::operator[](size_t index) const {
    if (index >= size_val) {
        throw out_of_range("Index out of bounds");
    }
    return data[index];
}

template<typename T>
T& Matrix<T>::operator[](size_t index) {
    if (index >= size_val) {
        throw out_of_range("Index out of bounds");
    }
    return data[index];
}

template<typename T>
size_t Matrix<T>::size() const {
    return size_val;
}

template<typename T>
string Matrix<T>::to_string() const {
    ostringstream oss;
    oss << "[ ";
    for (size_t i = 0; i < size_val; ++i) {
        oss << data[i];
        if (i < size_val - 1) {
            oss << ", ";
        }
    }
    oss << " ]";
    return oss.str();
}

template<typename T>
template<typename Gen>
void Matrix<T>::fill(Gen& gen) {
    for (size_t i = 0; i < size_val; ++i) {
        data[i] = gen.generate();
    }
}

}
