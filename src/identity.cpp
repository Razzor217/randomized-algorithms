/**
 * @file identity.cpp
 * @author Max Beddies (max.beddies@t-onlin.de)
 * @brief Implementation of matrix identity test interface
 * @date 2021-06-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "include/randomized-algorithms/identity.h"
#include "include/randomized-algorithms/detail/identity_impl.h"

namespace randalg
{
    bool matrix_identity(Eigen::MatrixXd const& a,
                         Eigen::MatrixXd const& b,
                         Eigen::MatrixXd const& c)
    {
        std::uniform_real_distribution<double> dist
        {
            std::numeric_limits<double>::lowest(),
            std::numeric_limits<double>::max()
        };

        std::random_device rd {};
        std::mt19937_64 gen {rd()};

        return detail::matrix_identity(a, b, c);
    }
} // namespace randalg