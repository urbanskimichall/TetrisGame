if (BUILD_TESTING)
    add_executable(test1 test1.cpp)
    target_link_libraries(test1 PRIVATE GTest::gtest_main )

    include(GoogleTest)
    gtest_discover_tests(test1)

endif ()