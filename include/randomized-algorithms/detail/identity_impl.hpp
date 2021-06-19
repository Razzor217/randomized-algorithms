/**
 * @file identity_impl.hpp
 * @author Max Beddies (max.beddies@t-online.de)
 * @brief Implementation of matrix identity test
 * @date 2021-06-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <random>

#include <eigen3/Eigen/Dense>

namespace randalg
{
    namespace detail
    {
        template <typename config>
        class identity_helper
        {
        public:
            using size_type = config::size_type;
            using difference_type = config::difference_type;

            bool operator ()(Eigen::MatrixXd const& a, Eigen::MatrixXd const& b, Eigen::MatrixXd const& c);

            explicit identity_helper();

        private:
            Eigen::VectorXd rand_vec(Eigen::Index const& rows);
            bool matrix_identity(Eigen::MatrixXd const& a, Eigen::MatrixXd const& b, Eigen::MatrixXd const& c);

        private:
            std::random_device rd_ {};
            std::mt19937_64 generator_;
            std::uniform_real_distribution<double> distribution_;
        };

        template <typename config>
        identity_helper<config>::identity_helper() :
            generator_ {rd_()}, distribution_ {config::min_double, config::max_double}
        {}

        template <typename config>
        bool identity_helper<config>::operator ()(Eigen::MatrixXd const& a, Eigen::MatrixXd const& b, Eigen::MatrixXd const& c)
        {
            return matrix_identity(a, b, c);
        }

        template <typename config>
        Eigen::VectorXd identity_helper<config>::rand_vec(Eigen::Index const& rows)
        {
            Eigen::VectorXd r {rows};

            for (Eigen::Index i {}; i < rows; ++i)
            {
                r(i) = distribution_(generator_);
            }

            return r;
        }

        template <typename config>
        bool identity_helper<config>::matrix_identity(Eigen::MatrixXd const& a, Eigen::MatrixXd const& b, Eigen::MatrixXd const& c)
        {
            Eigen::VectorXd const r {rand_vec(a.rows())};

            Eigen::VectorXd const x {b * r};
            Eigen::VectorXd const y {a * x};
            Eigen::VectorXd const z {c * r};

            return ((y - z).norm() < config::error_margin) ? true : false;
        }
    } // namespace detail
} // namespace randalg
