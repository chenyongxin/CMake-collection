cmake_minimum_required(VERSION 3.4)

project(link_lapacke LANGUAGES C)

# Get some noise to see the build process
set(CMAKE_VERBOSE_MAKEFILE ON)

# You should add the path to lapack here
set(LAPACK_HOME "")
if("${LAPACK_HOME}" STREQUAL "")
	message(FATAL_ERROR "Must specify the path to lapack!")
endif()

# Make executable
set(CMAKE_BUILD_TYPE Release)
add_executable(exe main.c)

# Fix the C compiler to gcc as we need `-lgfortran` flag latter
set(CMAKE_C_COMPILER gcc)

# Include
target_include_directories(exe PRIVATE ${LAPACK_HOME}/include)

# Linking
target_link_directories(exe PRIVATE ${LAPACK_HOME}/lib)   
target_link_libraries(exe PRIVATE lapacke lapack blas)     # must link in this order
target_link_libraries(exe PRIVATE m gfortran)              # -lm -lgfortran flags are necessary