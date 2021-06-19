/**
 * @file identity.hpp
 * @author Max Beddies (max.beddies@t-online.de)
 * @brief Randomized matrix identity test interface
 * @date 2021-06-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <cassert>

#include "configuration.hpp"
#include "detail/identity_impl.hpp"


namespace randalg
{
    template <typename config = configuration<>>
    bool matrix_identity(Eigen::MatrixXd const& a,
                         Eigen::MatrixXd const& b,
                         Eigen::MatrixXd const& c)
    {
        assert(a.rows == b.rows);
        assert(a.rows == c.rows);
        assert(a.cols == b.cols);
        assert(a.cols == c.cols);
        // quadratic matrices
        assert(a.rows == a.cols);

        detail::identity_helper<config> helper {};

        return helper(a, b, c);
    }
} // namespace randalg