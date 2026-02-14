cmake_minimum_required(VERSION 3.10)

# C++ 库项目
project(cpp_calculator)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 源文件
set(SOURCES
    src/Calculator.cpp
    src/c_wrapper.cpp
)

# 头文件
set(HEADERS
    include/cpp_calculator/Calculator.h
    include/cpp_calculator/c_wrapper.h
)

# 创建静态库
add_library(cpp_calculator_s STATIC ${SOURCES} ${HEADERS})
add_library(cpp_calculator SHARED ${SOURCES} ${HEADERS})

# 设置公共包含目录 - 允许外部项目使用 <cpp/Calculator.h>
target_include_directories(cpp_calculator_s PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/cpp>
)
target_include_directories(cpp_calculator PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/cpp>
)

# 设置库的输出名称和属性
set_target_properties(cpp_calculator_s PROPERTIES
    OUTPUT_NAME "cpp_calculator"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
set_target_properties(cpp_calculator PROPERTIES
    OUTPUT_NAME "cpp_calculator"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    POSITION_INDEPENDENT_CODE ON
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
    add_executable(test_cpp_calculator tests/test_main.cpp)
    target_link_libraries(test_cpp_calculator cpp_calculator)
    set_target_properties(test_cpp_calculator PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )

    # C wrapper测试程序
    add_executable(test_c_wrapper tests/test_c_wrapper.c)
    target_link_libraries(test_c_wrapper cpp_calculator)
    set_target_properties(test_c_wrapper PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
endif()