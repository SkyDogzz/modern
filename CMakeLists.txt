cmake_minimum_required(VERSION 3.25)

project(modern_cpp_roadmap_support LANGUAGES CXX)

include(CTest)

set(ROADMAP_SANITIZER "none" CACHE STRING
    "Support-test sanitizer: none, address-undefined, or thread")
set_property(CACHE ROADMAP_SANITIZER PROPERTY STRINGS
             none address-undefined thread)

function(roadmap_configure_target target)
    target_compile_features(${target} PRIVATE cxx_std_23)
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)

    if(MSVC)
        target_compile_options(${target} PRIVATE /W4 /permissive-)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)

        if(ROADMAP_SANITIZER STREQUAL "address-undefined")
            target_compile_options(
                ${target} PRIVATE
                -fsanitize=address,undefined -fno-omit-frame-pointer)
            target_link_options(
                ${target} PRIVATE
                -fsanitize=address,undefined -fno-omit-frame-pointer)
        elseif(ROADMAP_SANITIZER STREQUAL "thread")
            target_compile_options(
                ${target} PRIVATE
                -fsanitize=thread -fno-omit-frame-pointer)
            target_link_options(
                ${target} PRIVATE
                -fsanitize=thread -fno-omit-frame-pointer)
        elseif(NOT ROADMAP_SANITIZER STREQUAL "none")
            message(FATAL_ERROR "Unknown ROADMAP_SANITIZER value")
        endif()
    endif()
endfunction()

if(BUILD_TESTING)
    add_executable(
        roadmap-minitest-smoke
        support/tests/minitest_smoke.cpp)
    target_include_directories(
        roadmap-minitest-smoke PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/support/minitest")
    roadmap_configure_target(roadmap-minitest-smoke)
    add_test(NAME support.minitest COMMAND roadmap-minitest-smoke)

    add_executable(
        roadmap-allocation-failure-smoke
        support/tests/allocation_failure_smoke.cpp)
    target_include_directories(
        roadmap-allocation-failure-smoke PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/support/allocation-failure"
        "${CMAKE_CURRENT_SOURCE_DIR}/support/minitest")
    roadmap_configure_target(roadmap-allocation-failure-smoke)
    add_test(
        NAME support.allocation-failure
        COMMAND roadmap-allocation-failure-smoke)

    include(cmake/AddCompileFailTest.cmake)
    add_compile_fail_test(
        support.compile-fail.narrowing
        projects/04-integer-conversion-lab/compile-fail/narrowing.cpp)
endif()
