# C 数学运算库

本库提供了一系列高效的C语言数学运算函数，适合作为其他语言调用的底层实现。

## 功能特性

### 基本算术运算
- `add_int(int32_t a, int32_t b)` - 整数加法
- `sub_int(int32_t a, int32_t b)` - 整数减法
- `mul_int(int32_t a, int32_t b)` - 整数乘法
- `div_int(int32_t a, int32_t b)` - 整数除法
- `mod_int(int32_t a, int32_t b)` - 整数取模

### 位运算
- `left_shift(uint32_t value, int shift)` - 左移位
- `right_shift(uint32_t value, int shift)` - 右移位
- `bitwise_and(uint32_t a, uint32_t b)` - 按位与
- `bitwise_or(uint32_t a, uint32_t b)` - 按位或
- `bitwise_xor(uint32_t a, uint32_t b)` - 按位异或

### 数组操作
- `sum_array(const int32_t* arr, size_t size)` - 数组求和
- `find_max(const int32_t* arr, size_t size)` - 查找最大值
- `find_min(const int32_t* arr, size_t size)` - 查找最小值

### 字符串操作
- `string_length(const char* str)` - 计算字符串长度
- `string_copy(char* dest, const char* src, size_t max_len)` - 安全字符串拷贝

### 内存操作
- `memory_copy(void* dest, const void* src, size_t n)` - 内存拷贝
- `memory_set(void* dest, int value, size_t n)` - 内存设置

## 构建方法

### 使用CMake构建

```bash
# 在项目根目录
mkdir build && cd build
cmake ..
make

# 构建产物
# 静态库: lib/libmath_ops.a
# 测试程序: bin/test_c_math_ops
```

### 直接编译

```bash
# 编译静态库
gcc -c math_ops.c -o math_ops.o
ar rcs libmath_ops.a math_ops.o

# 编译测试程序
gcc test_main.c -L. -lmath_ops -o test_c_math_ops
```

## 使用方法

### 在C/C++项目中使用

```c
#include "math_ops.h"

int main() {
    // 基本运算
    int32_t result = add_int(5, 3);
    printf("5 + 3 = %d\n", result);

    // 数组操作
    int32_t arr[] = {1, 5, 3, 9, 2};
    int64_t sum = sum_array(arr, 5);
    printf("Array sum: %lld\n", sum);

    return 0;
}
```

### 作为其他语言的底层库

本库设计为C ABI兼容，可以被Python、Java、C#等语言通过FFI调用。

## API文档

### 函数签名

```c
// 基本整数运算
int32_t add_int(int32_t a, int32_t b);
int32_t sub_int(int32_t a, int32_t b);
int32_t mul_int(int32_t a, int32_t b);
int32_t div_int(int32_t a, int32_t b);  // 注意：除零返回0
int32_t mod_int(int32_t a, int32_t b);  // 注意：除零返回0

// 位运算
uint32_t left_shift(uint32_t value, int shift);
uint32_t right_shift(uint32_t value, int shift);
uint32_t bitwise_and(uint32_t a, uint32_t b);
uint32_t bitwise_or(uint32_t a, uint32_t b);
uint32_t bitwise_xor(uint32_t a, uint32_t b);

// 数组操作
int64_t sum_array(const int32_t* arr, size_t size);
int32_t find_max(const int32_t* arr, size_t size);
int32_t find_min(const int32_t* arr, size_t size);

// 字符串操作
size_t string_length(const char* str);
void string_copy(char* dest, const char* src, size_t max_len);

// 内存操作
void* memory_copy(void* dest, const void* src, size_t n);
void* memory_set(void* dest, int value, size_t n);
```

## 测试

运行测试程序验证所有功能：

```bash
./bin/test_c_math_ops
```

测试输出应显示所有运算的正确结果。

## 性能特点

- **高效**: 直接使用C语言特性，无额外开销
- **轻量**: 无外部依赖，代码简洁
- **稳定**: 经过完整测试，边界情况处理完善
- **兼容**: C89标准，广泛平台支持

## 许可证

本项目遵循项目根目录的许可证。