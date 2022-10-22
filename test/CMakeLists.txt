cmake_minimum_required(VERSION 3.0)

set(This UnitTests)

set(Sources
    UnitTest.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    SectionChallenge13
)

add_test(
    NAME ${This}
    COMMAND ${This}
)