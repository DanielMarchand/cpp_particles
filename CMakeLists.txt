cmake_minimum_required(VERSION 3.14)
project(ParticleSimulation)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)

# GoogleTest setup
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)


# pybind11
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG v2.6.1
)

# Eigen
FetchContent_Declare(
  eigen
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG 3.3.9
)

# Make available all the declared content
FetchContent_MakeAvailable(googletest pybind11 eigen)


# Set compiler flags
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set_target_properties(gtest PROPERTIES COMPILE_FLAGS -Wno-error)
set_target_properties(gtest_main PROPERTIES COMPILE_FLAGS -Wno-error)

enable_testing()

# Include directories
include_directories(${pybind11_INCLUDE_DIR})
include_directories(${eigen_SOURCE_DIR})

include_directories(src)

# Add your source files
add_library(particle_lib src/Particle.cc)

# Add test executable
add_executable(particle_test tests/ParticleTest.cc)
target_link_libraries(particle_test gtest_main particle_lib)

include(GoogleTest)
gtest_discover_tests(particle_test)

