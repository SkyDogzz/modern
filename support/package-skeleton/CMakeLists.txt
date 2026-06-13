cmake_minimum_required(VERSION 3.25)

project(RoadmapLibrary VERSION 0.1.0 LANGUAGES CXX)

include(CMakePackageConfigHelpers)
include(CTest)

add_library(roadmap_library src/example.cpp)
add_library(Roadmap::Library ALIAS roadmap_library)
target_compile_features(roadmap_library PUBLIC cxx_std_23)
set_target_properties(
    roadmap_library PROPERTIES
    CXX_EXTENSIONS OFF
    EXPORT_NAME Library)
target_include_directories(
    roadmap_library
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>")

if(BUILD_TESTING)
    add_executable(roadmap_library_test tests/example_test.cpp)
    target_link_libraries(roadmap_library_test PRIVATE Roadmap::Library)
    target_compile_features(roadmap_library_test PRIVATE cxx_std_23)
    set_target_properties(
        roadmap_library_test PROPERTIES CXX_EXTENSIONS OFF)
    add_test(NAME roadmap_library.example COMMAND roadmap_library_test)
endif()

install(
    TARGETS roadmap_library
    EXPORT RoadmapLibraryTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include)
install(DIRECTORY include/ DESTINATION include)
install(
    EXPORT RoadmapLibraryTargets
    FILE RoadmapLibraryTargets.cmake
    NAMESPACE Roadmap::
    DESTINATION lib/cmake/RoadmapLibrary)

configure_package_config_file(
    cmake/RoadmapLibraryConfig.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/RoadmapLibraryConfig.cmake"
    INSTALL_DESTINATION lib/cmake/RoadmapLibrary)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/RoadmapLibraryConfigVersion.cmake"
    VERSION "${PROJECT_VERSION}"
    COMPATIBILITY SameMajorVersion)
install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/RoadmapLibraryConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/RoadmapLibraryConfigVersion.cmake"
    DESTINATION lib/cmake/RoadmapLibrary)
