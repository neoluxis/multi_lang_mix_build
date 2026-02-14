cmake_minimum_required(VERSION 3.10)

# C 库项目
project(c_math_ops)

# 设置 C 标准
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 包含目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 源文件
set(SOURCES
    src/math_ops.c
)

# 头文件
set(HEADERS
    include/c_math_ops/math_ops.h
)

# 创建库
add_library(c_math_ops SHARED ${SOURCES} ${HEADERS})
add_library(c_math_ops_s STATIC ${SOURCES} ${HEADERS})

# 设置公共包含目录 - 允许外部项目使用 <c/math_ops.h>
target_include_directories(c_math_ops PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/c>
)
target_include_directories(c_math_ops_s PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/c>
)

# 设置库的输出名称
set_target_properties(c_math_ops PROPERTIES
    OUTPUT_NAME "math_ops"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
set_target_properties(c_math_ops_s PROPERTIES
    OUTPUT_NAME "math_ops"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

# 安装规则
install(TARGETS c_math_ops
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(FILES ${HEADERS} DESTINATION include)

# 可选：构建测试程序
option(BUILD_TESTS "Build test programs" ON)
if(BUILD_TESTS)
    add_executable(test_c_math_ops tests/test_main.c)
    target_link_libraries(test_c_math_ops c_math_ops)
    set_target_properties(test_c_math_ops PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
endif()