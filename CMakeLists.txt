cmake_minimum_required(VERSION 3.10)

project(MultProgLangMixien)

# 添加子目录
add_subdirectory(libs/c)
add_subdirectory(libs/asm)
add_subdirectory(libs/cpp)
add_subdirectory(examples/c_with_cpp_asm)