find_package(GTest REQUIRED)

add_executable(temperature_test)

target_sources(temperature_test PRIVATE temperature_test.cpp)

enable_testing()

target_link_libraries(temperature_test PRIVATE
    temperature
    GTest::gtest_main
    pthread)

include(GoogleTest)
gtest_discover_tests(temperature_test)
