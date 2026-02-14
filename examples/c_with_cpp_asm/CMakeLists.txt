cmake_minimum_required(VERSION 3.10)

# C项目示例 - 使用C++和汇编库
project(c_with_cpp_asm_example)

# 设置C标准
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 源文件
set(SOURCES
    main.c
)

# 创建可执行文件
add_executable(c_with_cpp_asm_example ${SOURCES})

# 链接库
target_link_libraries(c_with_cpp_asm_example
    c_math_ops
    asm_math_ops
    cpp_calculator
    m  # 数学库
)

# 设置输出目录
set_target_properties(c_with_cpp_asm_example PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# 安装规则（可选）
install(TARGETS c_with_cpp_asm_example
    RUNTIME DESTINATION bin
)