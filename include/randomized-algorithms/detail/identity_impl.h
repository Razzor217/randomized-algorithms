/**
 * @file identity_impl.h
 * @author Max Beddies (max.beddies@t-online.de)
 * @brief Implementation of matrix identity test
 * @date 2021-06-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <limits>
#include <random>

namespace randalg
{
    namespace detail
    {
        // template parameter
        bool matrix_identity(Eigen::MatrixXd const& a, Eigen::MatrixXd const& b, Eigen::MatrixXd const& c);
    } // namespace detail
} // namespace randalg

#include "identity_impl.hxx"