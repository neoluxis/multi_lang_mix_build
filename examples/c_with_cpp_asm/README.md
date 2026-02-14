# C项目使用C++和汇编库示例

这个示例项目展示了如何在纯C代码中调用C++和汇编库，实现多语言混合编程。

## 项目概述

本示例演示了在C项目中集成多个语言库的能力：

- **C库** (`libmath_ops.a`): 提供基础数学运算
- **汇编库** (`libasm_math_ops.a`): 提供高性能计算
- **C++库** (`libcpp_calculator.a`): 通过C wrapper提供面向对象功能

## 功能演示

### 1. C库调用
- 基本算术运算（加减乘除模）
- 位运算（与或非移位）
- 数组操作（求和、最大最小值）
- 字符串操作（拷贝、长度计算）

### 2. 汇编库调用
- 64位整数运算
- 阶乘和幂运算
- 位运算（与或非移位）

### 3. C++库调用（通过C wrapper）
- 基础计算器功能
- 高级科学运算（幂、平方根、阶乘、三角函数）
- 数组操作（支持int32和double类型）
- 批量处理操作
- 错误处理

### 4. 综合集成
最后的综合演示展示了如何将三个库的功能结合起来使用。

## 构建方法

### 依赖要求
- CMake 3.10+
- GCC/Clang (支持C和C++)
- NASM (汇编器)
- 数学库 (libm)

### 构建步骤

```bash
# 在项目根目录
mkdir build && cd build
cmake ..
make

# 运行示例
./bin/c_with_cpp_asm_example
```

### 单独构建示例

```bash
cd examples/c_with_cpp_asm
mkdir build && cd build
cmake ..
make
./c_with_cpp_asm_example
```

## 代码结构

```
c_with_cpp_asm/
├── main.c              # 主程序，演示所有库的使用
├── CMakeLists.txt      # 构建配置
└── README.md          # 本文档
```

## 技术要点

### 库集成方式

1. **C库**: 直接包含头文件，链接静态库
2. **汇编库**: 直接包含头文件，链接静态库
3. **C++库**: 通过C wrapper接口调用，避免C++ ABI问题

### 构建依赖

CMake自动处理库依赖关系：
- `c_math_ops` - C数学库
- `asm_math_ops` - 汇编数学库
- `cpp_calculator` - C++计算器库（包含C wrapper）
- `m` - 标准数学库

### 跨语言调用

- **C调用C**: 直接函数调用
- **C调用汇编**: 遵循System V AMD64 ABI
- **C调用C++**: 通过C wrapper隐藏C++复杂性

## 输出示例

```
C Project Using C++, C, and Assembly Libraries
===============================================

1. Using C Library (Basic Math Operations)
------------------------------------------
C Library Results:
  15 + 7 = 22
  15 - 7 = 8
  15 * 7 = 105
  15 / 7 = 2
  15 % 7 = 1
  60 & 13 = 12
  60 | 13 = 61
  60 ^ 13 = 49
  60 << 2 = 240
  Array operations on [12, 45, 23, 67, 34, 89, 56]:
    Sum = 326
    Max = 89
    Min = 12
  String copy: 'Hello, Mixed Language Programming!'
  String length: 33

2. Using Assembly Library (High-Performance Math)
-------------------------------------------------
Assembly Library Results:
  42 + 18 = 60
  42 - 18 = 24
  42 * 18 = 756
  2^8 = 256
  6! = 720
  0xFF00FF00 & 0xFF00FF = 0xFF00FF00
  0xFF00FF00 | 0xFF00FF = 0xFFFFFF00
  1 << 5 = 32

3. Using C++ Library (via C Wrapper - OOP Features)
---------------------------------------------------
Basic Calculator Operations:
  25.5 + 14.7 = 40.20
  8.0 * 9.0 = 72.00
  Calculation history (2 entries):
    25.5 + 14.7 = 40.2
    8 * 9 = 72

Advanced Calculator Operations:
  3^4 = 81
  √144 = 12
  5! = 120
  sin(30°) = 0.500000
  Integer array sum [15, 42, 8, 23, 91, 34] = 213
  Integer array max = 91
  Double array sum [3.14, 2.71, 1.41, 1.73] = 8.99
  Batch add 5.0: [10.0, 20.0, 30.0, 40.0] -> [15.0, 25.0, 35.0, 45.0]
  Error handling: Division by zero!
  Error handling: Cannot calculate square root of negative number!

4. Integrated Demo (Combining All Libraries)
---------------------------------------------
Integrated computation:
  Generated data: [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
  Sum (via assembly): 110
  Square root of sum (via C++): 10.49

🎉 Successfully demonstrated mixed-language programming!
   - C Library: Basic math operations
   - Assembly Library: High-performance calculations
   - C++ Library: Object-oriented features via C wrapper
```

## 学习要点

### 多语言编程模式

1. **库设计**: 每个库都有明确的职责分工
2. **接口抽象**: C wrapper隐藏了C++实现的复杂性
3. **构建系统**: CMake统一管理多语言构建
4. **错误处理**: 统一的错误处理机制

### 性能考虑

- **C库**: 适合通用计算，代码简洁
- **汇编库**: 适合性能关键的简单运算
- **C++库**: 适合复杂算法和数据结构

### 可维护性

- **模块化**: 每个库独立开发和测试
- **文档化**: 完整的API文档和示例
- **兼容性**: C ABI确保了广泛的兼容性

## 扩展建议

- 添加更多语言库（如Rust、Go）
- 实现性能基准测试
- 添加配置文件支持
- 实现插件系统
- 添加网络通信功能

## 相关链接

- [C库文档](../../libs/c/README.md)
- [汇编库文档](../../libs/asm/README.md)
- [C++库文档](../../libs/cpp/README.md)
- [项目主文档](../../README.md)

## 许可证

本项目遵循项目根目录的许可证。