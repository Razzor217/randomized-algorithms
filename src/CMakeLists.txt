set(HEADERS
    ../include/randomized-algorithms/identity.h

    ../include/randomized-algorithms/detail/identity_impl.h
    ../include/randomized-algorithms/detail/identity_impl.hxx
)

set(SOURCES
    identity.cpp
)

add_library(RandAlgs ${HEADERS} ${SOURCES})

set(LIBS
    RandAlgs
)

add_executable(identity_test test/identity_test.cpp)
target_link_libraries(identity_test ${LIBS})