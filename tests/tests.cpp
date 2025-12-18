#include <gtest/gtest.h>
#include "../include/matrix.h"
#include "../include/constantGenerator.h"
#include "../include/randomGenerator.h"
#include "../include/task1Exercise.h"
#include "../include/task2Exercise.h"
#include "../include/task3Exercise.h"

namespace alg = miit::algebra;

TEST(MatrixTest, DefaultConstructor) {
    alg::Matrix<int> matrix;
    EXPECT_EQ(matrix.size(), 0);
}

TEST(MatrixTest, SizedConstructor) {
    alg::Matrix<int> matrix(5);
    EXPECT_EQ(matrix.size(), 5);
}

TEST(MatrixTest, CopyConstructor) {
    alg::Matrix<int> original(3);
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;
    
    alg::Matrix<int> copy(original);
    EXPECT_EQ(copy.size(), 3);
    EXPECT_EQ(copy[0], 1);
    EXPECT_EQ(copy[1], 2);
    EXPECT_EQ(copy[2], 3);
}

TEST(Task1ExerciseTest, PerformTask1) {
    alg::Matrix<int> test_data(4);
    test_data[0] = -5;
    test_data[1] = 10;
    test_data[2] = -15;
    test_data[3] = -2;

    alg::Task1Exercise task(test_data);
    task.task();
    
    auto result = task.get_matrix();
    EXPECT_EQ(result[0], -5);
    EXPECT_EQ(result[1], 10);
    EXPECT_EQ(result[2], 0); 
    EXPECT_EQ(result[3], -2);
}

TEST(Task2ExerciseTest, PerformTask2) {
    alg::Matrix<int> test_data(3);
    test_data[0] = 5;  
    test_data[1] = -3; 
    test_data[2] = 2;  

    int K = 99;
    alg::Task2Exercise task(test_data, K);
    task.task();
    
    auto result = task.get_matrix();
    ASSERT_EQ(result.size(), 5);
    EXPECT_EQ(result[0], 5);
    EXPECT_EQ(result[1], 99);
    EXPECT_EQ(result[2], -3);
    EXPECT_EQ(result[3], 99);
    EXPECT_EQ(result[4], 2);
}

TEST(Task3ExerciseTest, PerformTask3) {
    alg::Matrix<int> input(4);
    input[0] = 2;
    input[1] = 3;
    input[2] = 4;
    input[3] = 5;

    size_t k_threshold = 2;
    alg::Task3Exercise task(input, k_threshold);
    task.task();
    
    auto result = task.get_matrix();
    
    EXPECT_EQ(result.size(), 4);
    EXPECT_EQ(result[0], -4);
    EXPECT_EQ(result[1], -9);
    EXPECT_EQ(result[2], 3);
    EXPECT_EQ(result[3], 4);
}