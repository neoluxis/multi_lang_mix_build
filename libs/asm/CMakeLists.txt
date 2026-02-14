cmake_minimum_required(VERSION 3.10)

# 汇编库项目
project(asm_math_ops)

# 查找 NASM 汇编器
find_program(NASM_EXECUTABLE nasm)
if(NOT NASM_EXECUTABLE)
    message(FATAL_ERROR "NASM assembler not found. Please install NASM.")
endif()

# 设置汇编编译器
set(CMAKE_ASM_NASM_COMPILER ${NASM_EXECUTABLE})
enable_language(ASM_NASM)

# 设置 NASM 编译标志 (x64)
set(CMAKE_ASM_NASM_FLAGS "-f elf64")

# 包含目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 源文件
set(SOURCES
    math_ops.asm
)

# 头文件
set(HEADERS
    math_ops_asm.h
)

# 创建库
add_library(asm_math_ops SHARED ${SOURCES} ${HEADERS})
add_library(asm_math_ops_s STATIC ${SOURCES} ${HEADERS})

# 设置库的输出名称
set_target_properties(asm_math_ops PROPERTIES
    OUTPUT_NAME "asm_math_ops"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

# 安装规则
install(TARGETS asm_math_ops
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(FILES ${HEADERS} DESTINATION include)

# 可选：构建测试程序
option(BUILD_TESTS "Build test programs" ON)
if(BUILD_TESTS)
    # 创建一个简单的C测试程序
    add_executable(test_asm_math_ops test_main.c)
    target_link_libraries(test_asm_math_ops asm_math_ops)
    set_target_properties(test_asm_math_ops PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
endif()