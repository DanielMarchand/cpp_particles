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
FetchContent_MakeAvailable(googletest)

# pybind11
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG v2.6.1
)
FetchContent_MakeAvailable(pybind11)

# Eigen
FetchContent_Declare(
  eigen
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG 3.3.9
)
FetchContent_MakeAvailable(eigen)

# Include directories
include_directories(${pybind11_INCLUDE_DIR})
include_directories(${eigen_SOURCE_DIR})
include_directories(src)

# Add your source files
add_library(particle_lib src/Particle.cc)

# Enable testing
enable_testing()

# Include GoogleTest
include(GoogleTest)

# Add a macro to simplify adding tests
macro(package_add_test TESTNAME TEST_SOURCES)
    add_executable(${TESTNAME} ${TEST_SOURCES})
    target_link_libraries(${TESTNAME} gtest_main particle_lib)

    # Discover tests
    gtest_discover_tests(${TESTNAME})
endmacro()

package_add_test(ParticleTest tests/ParticleTest.cc)
# Add additional tests here using package_add_test

