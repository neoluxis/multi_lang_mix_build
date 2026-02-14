#include "math_ops.h"
#include <string.h>

// 基本整数运算
int32_t add_int(int32_t a, int32_t b)
{
    return a + b;
}

int32_t sub_int(int32_t a, int32_t b)
{
    return a - b;
}

int32_t mul_int(int32_t a, int32_t b)
{
    return a * b;
}

int32_t div_int(int32_t a, int32_t b)
{
    if (b == 0)
        return 0; // 简单错误处理
    return a / b;
}

int32_t mod_int(int32_t a, int32_t b)
{
    if (b == 0)
        return 0;
    return a % b;
}

// 位运算
uint32_t left_shift(uint32_t value, int shift)
{
    return value << shift;
}

uint32_t right_shift(uint32_t value, int shift)
{
    return value >> shift;
}

uint32_t bitwise_and(uint32_t a, uint32_t b)
{
    return a & b;
}

uint32_t bitwise_or(uint32_t a, uint32_t b)
{
    return a | b;
}

uint32_t bitwise_xor(uint32_t a, uint32_t b)
{
    return a ^ b;
}

// 数组操作
int64_t sum_array(const int32_t *arr, size_t size)
{
    int64_t sum = 0;
    for (size_t i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

int32_t find_max(const int32_t *arr, size_t size)
{
    if (size == 0)
        return 0;
    int32_t max = arr[0];
    for (size_t i = 1; i < size; ++i)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int32_t find_min(const int32_t *arr, size_t size)
{
    if (size == 0)
        return 0;
    int32_t min = arr[0];
    for (size_t i = 1; i < size; ++i)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

// 字符串操作
size_t string_length(const char *str)
{
    return strlen(str);
}

void string_copy(char *dest, const char *src, size_t max_len)
{
    strncpy(dest, src, max_len - 1);
    dest[max_len - 1] = '\0';
}

// 内存操作
void *memory_copy(void *dest, const void *src, size_t n)
{
    return memcpy(dest, src, n);
}

void *memory_set(void *dest, int value, size_t n)
{
    return memset(dest, value, n);
}