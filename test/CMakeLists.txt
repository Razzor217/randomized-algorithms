set(HEADERS
    ../include/randomized-algorithms/identity.hpp

    ../include/randomized-algorithms/detail/identity_impl.hpp
)

add_executable(identity_test identity_test.cpp ${HEADERS})