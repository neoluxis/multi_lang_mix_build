# x64 汇编数学运算库

本库提供了一系列x64汇编实现的数学运算函数，展示了底层编程的性能优势。

## 功能特性

### 基本算术运算
- `asm_add(int64_t a, int64_t b)` - 64位整数加法
- `asm_subtract(int64_t a, int64_t b)` - 64位整数减法
- `asm_multiply(int64_t a, int64_t b)` - 64位整数乘法

### 高级运算
- `asm_factorial(uint32_t n)` - 阶乘计算
- `asm_power(uint32_t base, uint32_t exp)` - 幂运算

### 位运算
- `asm_bitwise_and(uint64_t a, uint64_t b)` - 64位按位与
- `asm_bitwise_or(uint64_t a, uint64_t b)` - 64位按位或
- `asm_left_shift(uint64_t value, int shift)` - 左移位

## 技术实现

### 汇编特性
- **x64架构**: 针对AMD64指令集优化
- **System V ABI**: 遵循Linux/macOS调用约定
- **性能优化**: 直接CPU指令，零开销调用

### 指令使用
- 基本运算: `mov`, `add`, `sub`, `imul`
- 循环控制: 阶乘和幂运算使用循环
- 位运算: `and`, `or`, `shl`

## 构建方法

### 依赖要求
- NASM汇编器 (Netwide Assembler)
- CMake 3.10+
- GCC/Clang (用于链接)

### 使用CMake构建

```bash
# 在项目根目录
mkdir build && cd build
cmake ..
make

# 构建产物
# 静态库: lib/libasm_math_ops.a
# 测试程序: bin/test_asm_ops
```

### 手动编译

```bash
# 汇编源码
nasm -f elf64 math_ops.asm -o math_ops.o

# 创建静态库
ar rcs libasm_math_ops.a math_ops.o

# 编译测试程序
gcc test_main.c -L. -lasm_math_ops -o test_asm_ops
```

## 使用方法

### 在C/C++项目中使用

```c
#include "math_ops_asm.h"

int main() {
    // 基本运算
    int64_t result = asm_add(42, 58);
    printf("42 + 58 = %lld\n", result);

    // 高级运算
    uint64_t fact = asm_factorial(5);
    printf("5! = %llu\n", fact);

    uint64_t power = asm_power(2, 8);
    printf("2^8 = %llu\n", power);

    // 位运算
    uint64_t bitwise = asm_bitwise_and(0xFF00, 0x00FF);
    printf("0xFF00 & 0x00FF = 0x%llX\n", bitwise);

    return 0;
}
```

### 性能优势

汇编实现相比高级语言有以下优势：
- **零抽象开销**: 直接CPU指令执行
- **精确控制**: 手动优化指令选择
- **内存效率**: 最小化内存访问
- **确定性性能**: 无JIT编译开销

## API文档

### 函数签名

```c
// 基本算术
extern int64_t asm_add(int64_t a, int64_t b);
extern int64_t asm_subtract(int64_t a, int64_t b);
extern int64_t asm_multiply(int64_t a, int64_t b);

// 高级运算
extern uint64_t asm_factorial(uint32_t n);
extern uint64_t asm_power(uint32_t base, uint32_t exp);

// 位运算
extern uint64_t asm_bitwise_and(uint64_t a, uint64_t b);
extern uint64_t asm_bitwise_or(uint64_t a, uint64_t b);
extern uint64_t asm_left_shift(uint64_t value, int shift);
```

### 调用约定
- **参数传递**: System V AMD64 ABI
  - 整数参数: rdi, rsi, rdx, rcx, r8, r9
  - 返回值: rax
- **堆栈对齐**: 16字节对齐
- **被调用者保存**: rbx, rbp, r12-r15

## 测试

运行测试程序验证所有功能：

```bash
./bin/test_asm_ops
```

测试覆盖：
- 基本算术运算正确性
- 阶乘计算边界情况
- 位运算结果验证
- 性能基准测试

## 平台支持

- **架构**: x86-64 (AMD64)
- **操作系统**: Linux, macOS, Windows (通过MinGW)
- **编译器**: GCC, Clang

## 调试和分析

### 使用objdump分析

```bash
objdump -d libasm_math_ops.a
```

### 性能分析

```bash
perf stat ./test_asm_ops
```

## 扩展建议

- 添加浮点运算 (SSE/AVX指令)
- 实现SIMD并行处理
- 添加原子操作支持
- 实现自定义内存分配器

## 许可证

本项目遵循项目根目录的许可证。