/**
 * @file identity_test.cpp
 * @author Max Beddies (max.beddies@t-online.de)
 * @brief Tests for matrix identity test
 * @date 2021-06-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

#include "include/randomized-algorithms/identity.hpp"

int main()
{
    Eigen::MatrixXd a {3, 3};
    a << 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0;
    Eigen::MatrixXd b {3, 3};
    b << 2.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 2.0;
    Eigen::MatrixXd c {3, 3};
    c << 2.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 2.0;

    std::cout << randalg::matrix_identity(a, b, c) << "\n";

    return 0;
}
