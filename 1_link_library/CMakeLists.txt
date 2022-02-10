cmake_minimum_required(VERSION 3.4)

project(test_link_lib LANGUAGES CXX)

add_executable(linklib src/main.cc)

# Set the default C++ compiler
set(CMAKE_CXX_COMPILER g++)
message(STATUS "CMAKE_CXX_COMPILER: " ${CMAKE_CXX_COMPILER})

# The following setting invokes a "-O3 -DNDEBUG" flag. 
# This is needed for heavy computation.
set(CMAKE_BUILD_TYPE Release)
message(STATUS "CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE})

# Link an external library
# This can be modified by either invoking ccmake (GUI) 
#   or with `cmake . -DUSE_MYMATH=ON`
option(USE_MYMATH "Use mymath" OFF)
if(${USE_MYMATH})
	message(STATUS "Use our own function!")

	# Switch on USE_MYMATH flag in the code
	target_compile_definitions(linklib PRIVATE USE_MYMATH)

	# Include and linking
	target_include_directories(linklib PRIVATE ThirdParty/include)
	target_link_directories(linklib PRIVATE ThirdParty/lib)
	target_link_libraries(linklib PRIVATE mymath)	
else()
	message(STATUS "Use the standard function")
endif(${USE_MYMATH})