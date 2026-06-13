if(NOT DEFINED ROADMAP_CXX_COMPILER OR
   NOT DEFINED ROADMAP_CXX_COMPILER_ID OR
   NOT DEFINED ROADMAP_SOURCE OR
   NOT DEFINED ROADMAP_OUTPUT)
    message(FATAL_ERROR "Compile-fail test is missing required arguments")
endif()

get_filename_component(output_directory "${ROADMAP_OUTPUT}" DIRECTORY)
file(MAKE_DIRECTORY "${output_directory}")

if(ROADMAP_CXX_COMPILER_ID STREQUAL "MSVC")
    execute_process(
        COMMAND
            "${ROADMAP_CXX_COMPILER}"
            /nologo /std:c++latest /permissive- /c
            "${ROADMAP_SOURCE}" "/Fo${ROADMAP_OUTPUT}"
        RESULT_VARIABLE result
        OUTPUT_VARIABLE standard_output
        ERROR_VARIABLE standard_error)
else()
    execute_process(
        COMMAND
            "${ROADMAP_CXX_COMPILER}"
            -std=c++23 -Wall -Wextra -Wpedantic -pedantic-errors -c
            "${ROADMAP_SOURCE}" -o "${ROADMAP_OUTPUT}"
        RESULT_VARIABLE result
        OUTPUT_VARIABLE standard_output
        ERROR_VARIABLE standard_error)
endif()

if(result EQUAL 0)
    message(FATAL_ERROR
        "Expected compilation to fail, but it succeeded: ${ROADMAP_SOURCE}")
endif()

message(STATUS "Observed expected compile failure for ${ROADMAP_SOURCE}")
