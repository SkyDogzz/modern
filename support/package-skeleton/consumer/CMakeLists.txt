cmake_minimum_required(VERSION 3.25)

project(RoadmapLibraryConsumer LANGUAGES CXX)

include(CTest)

find_package(RoadmapLibrary 0.1 CONFIG REQUIRED)

add_executable(roadmap_consumer main.cpp)
target_link_libraries(roadmap_consumer PRIVATE Roadmap::Library)
target_compile_features(roadmap_consumer PRIVATE cxx_std_23)
set_target_properties(roadmap_consumer PROPERTIES CXX_EXTENSIONS OFF)

add_test(NAME roadmap_consumer.runs COMMAND roadmap_consumer)
