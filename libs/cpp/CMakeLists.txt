cmake_minimum_required(VERSION 3.10)

# C++ 库项目
project(cpp_calculator)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 源文件
set(SOURCES
    Calculator.cpp
    c_wrapper.cpp
)

# 头文件
set(HEADERS
    Calculator.h
    c_wrapper.h
)

# 创建静态库
add_library(cpp_calculator STATIC ${SOURCES} ${HEADERS})

# 设置库的输出名称
set_target_properties(cpp_calculator PROPERTIES
    OUTPUT_NAME "cpp_calculator"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

# 链接数学库
target_link_libraries(cpp_calculator m)

# 安装规则
install(TARGETS cpp_calculator
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(FILES ${HEADERS} DESTINATION include)

# 可选：构建测试程序
option(BUILD_TESTS "Build test programs" ON)
if(BUILD_TESTS)
    # C++测试程序
    add_executable(test_cpp_calculator test_main.cpp)
    target_link_libraries(test_cpp_calculator cpp_calculator)
    set_target_properties(test_cpp_calculator PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )

    # C wrapper测试程序
    add_executable(test_c_wrapper test_c_wrapper.c)
    target_link_libraries(test_c_wrapper cpp_calculator)
    set_target_properties(test_c_wrapper PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
endif()