cmake_minimum_required(VERSION 4.3)

project(debugger_cmake_smoketest VERSION 0.1.0 LANGUAGES C CXX)

set(EXECUTABLE exe)

enable_testing()

add_executable(${EXECUTABLE} main.cpp)
set_target_properties(${EXECUTABLE} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_compile_options(${EXECUTABLE} PRIVATE -g3)
target_compile_features(${EXECUTABLE} PUBLIC cxx_std_23)

add_test(NAME test COMMAND "${CMAKE_SOURCE_DIR}/simple_test.sh")
