/**
 * @file identity.h
 * @author Max Beddies (max.beddies@t-online.de)
 * @brief Randomized matrix identity test interface
 * @date 2021-06-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <Eigen/Dense>

namespace randalg
{
    bool matrix_identity(Eigen::MatrixXd const& a,
                         Eigen::MatrixXd const& b,
                         Eigen::MatrixXd const& c);
} // namespace randalg