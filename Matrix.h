#pragma once
#include <string>
#include <stdexcept>

namespace miit::algebra
{
    // Добавьте определение Generator перед классом Matrix
    class Generator 
    {
    public:
        virtual double generate() = 0; // чисто виртуальная функция
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
        Matrix();
        Matrix(size_t size);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept;
        
        // Деструктор
        ~Matrix();
        
        // Операторы присваивания
        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;
        
        // Операторы сдвига
        Matrix operator<<(int shift) const;
        Matrix operator>>(int shift) const;
        
        // Оператор разыменования
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        
        // Методы
        std::string to_string() const;
        size_t get_size() const;
        void fill(Generator& generator); // Теперь компилятор знает Generator
    };

    template<typename T>
    void miit::algebra::Matrix<T>::fill(Generator& generator) {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = static_cast<T>(generator.generate());
        }
    }
}