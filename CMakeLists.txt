###############################################################################
# For both projects ###########################################################
###############################################################################
cmake_minimum_required(VERSION 3.22)

###############################################################################
# Building the library ########################################################
###############################################################################
project(neushoorn)

# Source files
file(GLOB NH_SOURCES ${PROJECT_SOURCE_DIR}/src/*.c)

# Actual library
add_library(neushoorn STATIC ${NH_SOURCES})

# Include folder
target_include_directories(neushoorn PRIVATE ${PROJECT_SOURCE_DIR}/include)

###############################################################################
# Testing the library #########################################################
###############################################################################
project(nh_test)

# Source files
file(GLOB NH_TEST_SOURCES ${PROJECT_SOURCE_DIR}/test/src/*.c)

# Actual executable
add_executable(nh_test ${NH_TEST_SOURCES})

# Include folder
target_include_directories(nh_test PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Neushoorn library
target_link_libraries(nh_test ${PROJECT_BINARY_DIR}/libneushoorn.a)
