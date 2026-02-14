cmake_minimum_required(VERSION 3.10)

# Python bindings project
project(cpp_calculator_py)

# Find Python
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

# Find pybind11
find_package(pybind11 REQUIRED)

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../c/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../asm/include
)

# Source files
set(SOURCES
    cpp_calculator_py.cpp
)

# Create Python module
pybind11_add_module(cpp_calculator_py ${SOURCES})

# Link with the C++ calculator library
target_link_libraries(cpp_calculator_py PRIVATE cpp_calculator)

# Set output directory for Python module
set_target_properties(cpp_calculator_py PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/python"
)

# Install the Python module
install(TARGETS cpp_calculator_py
    LIBRARY DESTINATION lib/python
)