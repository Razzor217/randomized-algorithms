/**
 * @file configuration.hpp
 * @author yMax Beddies (max.beddies@t-online.de)
 * @brief Configuration for randomization
 * @date 2021-06-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#ifndef MIN_DOUBLE
#define MIN_DOUBLE 0.0
#endif

#ifndef MAX_DOUBLE
#define MAX_DOUBLE 1.0
#endif

#ifndef ERROR_MARGIN
#define ERROR_MARGIN 1e-6
#endif


namespace randalg
{
    template <double min_double_ = MIN_DOUBLE,
              double max_double_ = MAX_DOUBLE,
              double error_margin_ = ERROR_MARGIN>
    class configuration
    {
    public:
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;

        static constexpr double const min_double {min_double_};
        static constexpr double const max_double {max_double_};
        static constexpr double const error_margin {error_margin_};
    };

    #undef MIN_DOUBLE
    #undef MAX_DOUBLE
    #undef ERROR_MARGIN
} // namespace randalg
