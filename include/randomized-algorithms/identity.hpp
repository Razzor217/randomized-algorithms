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
        // (NxM) * (MxP) -> (NxP)
        assert(a.cols == b.rows);
        assert(a.rows == c.rows);
        assert(b.cols == c.cols);

        detail::identity_helper<config> helper {};

        return helper(a, b, c);
    }

    template <std::size_t k, typename config = configuration<>>
    bool matrix_identity(Eigen::MatrixXd const& a,
                         Eigen::MatrixXd const& b,
                         Eigen::MatrixXd const& c)
    {
        // (NxM) * (MxP) -> (NxP)
        assert(a.cols == b.rows);
        assert(a.rows == c.rows);
        assert(b.cols == c.cols);

        detail::identity_helper<config> helper {};

        bool is_equal {true};
        // k independent repetitions
        for (std::size_t i {}; i < k && is_equal; ++i, is_equal = helper(a, b, c));

        return is_equal;
    }
} // namespace randalg