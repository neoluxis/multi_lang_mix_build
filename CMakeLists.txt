cmake_minimum_required(VERSION 3.10)

project(MultProgLangMixien)

# 设置 C/C++ 标准
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加子目录
add_subdirectory(libs/c)