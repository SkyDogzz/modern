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

function(add_character_test test_name)
    set(options WILL_FAIL)
    set(oneValueArgs ARG)
    cmake_parse_arguments(TEST "${options}" "${oneValueArgs}" "" ${ARGN})

    if(DEFINED TEST_ARG)
        add_test(NAME "${test_name}" COMMAND "${CMAKE_SOURCE_DIR}/simple_test.sh" "${TEST_ARG}")
    else()
        add_test(NAME "${test_name}" COMMAND "${CMAKE_SOURCE_DIR}/simple_test.sh")
    endif()

    if(TEST_WILL_FAIL)
        set_tests_properties("${test_name}" PROPERTIES WILL_FAIL TRUE)
    endif()
endfunction()

add_character_test(test WILL_FAIL)
add_character_test(test2 ARG jacques)
add_character_test(test3 ARG pierre)
add_character_test(test4 ARG paul)
add_character_test(test5 ARG fail WILL_FAIL)
add_character_test(test6 ARG "" WILL_FAIL)
