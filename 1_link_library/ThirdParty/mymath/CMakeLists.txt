cmake_minimum_required(VERSION 3.4)

project(mathlib LANGUAGES CXX)

add_library(mymath STATIC src/mymath.cc)
target_include_directories(mymath PRIVATE include)

# Install
include(GNUInstallDirs)

# Library
install(TARGETS mymath
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# Include
install(FILES include/mymath.h 
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})