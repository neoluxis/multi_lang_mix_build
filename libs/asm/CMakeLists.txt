cmake_minimum_required(VERSION 3.10)

# 汇编库项目
project(asm_math_ops)

# 查找 NASM 汇编器
find_program(NASM_EXECUTABLE nasm)
if(NOT NASM_EXECUTABLE)
    message(FATAL_ERROR "NASM assembler not found. Please install NASM.")
endif()

# 包含目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 头文件
set(HEADERS
    include/asm_math_ops/math_ops_asm.h
)

# 自定义命令编译汇编文件
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/math_ops.o
    COMMAND ${NASM_EXECUTABLE} -f elf64 -o ${CMAKE_CURRENT_BINARY_DIR}/math_ops.o ${CMAKE_CURRENT_SOURCE_DIR}/src/math_ops.asm
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/math_ops.asm
    COMMENT "Assembling math_ops.asm"
)

# 创建静态库
add_library(asm_math_ops STATIC ${CMAKE_CURRENT_BINARY_DIR}/math_ops.o ${HEADERS})

# 创建共享库（用于Python绑定）
add_library(asm_math_ops_shared SHARED ${CMAKE_CURRENT_BINARY_DIR}/math_ops.o ${HEADERS})

# 设置公共包含目录 - 允许外部项目使用 <asm/math_ops_asm.h>
target_include_directories(asm_math_ops PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/asm>
)
target_include_directories(asm_math_ops_shared PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/asm>
)

# 明确指定链接语言
set_target_properties(asm_math_ops PROPERTIES LINKER_LANGUAGE C)
set_target_properties(asm_math_ops_shared PROPERTIES
    LINKER_LANGUAGE C
    OUTPUT_NAME "asm_math_ops"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

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
    add_executable(test_asm_ops tests/test_main.c)
    target_link_libraries(test_asm_ops asm_math_ops)
    set_target_properties(test_asm_ops PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )

    # 创建另一个测试程序
    add_executable(test_asm_math_ops tests/test_main.c)
    target_link_libraries(test_asm_math_ops asm_math_ops_shared)
    set_target_properties(test_asm_math_ops PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
endif()