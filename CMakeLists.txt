cmake_minimum_required(VERSION 3.10)

project(MultProgLangMixien)

# 设置全局包含目录 - 允许使用 <c_math_ops/math_ops.h>, <asm_math_ops/math_ops_asm.h>, <cpp_calculator/Calculator.h>
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/c/include
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/asm/include
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/cpp/include
)

# 添加子目录
add_subdirectory(libs/c)
add_subdirectory(libs/asm)
add_subdirectory(libs/cpp)
add_subdirectory(libs/cpp/bindings/python)
add_subdirectory(examples/c_with_cpp_asm)