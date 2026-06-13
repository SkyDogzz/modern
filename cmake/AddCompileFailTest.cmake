function(add_compile_fail_test name source)
    get_filename_component(source_path "${source}" ABSOLUTE
                           BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
    set(output_path "${CMAKE_CURRENT_BINARY_DIR}/${name}.o")

    add_test(
        NAME "${name}"
        COMMAND
            "${CMAKE_COMMAND}"
            "-DROADMAP_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
            "-DROADMAP_CXX_COMPILER_ID=${CMAKE_CXX_COMPILER_ID}"
            "-DROADMAP_SOURCE=${source_path}"
            "-DROADMAP_OUTPUT=${output_path}"
            -P "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/RunCompileFail.cmake")
endfunction()
