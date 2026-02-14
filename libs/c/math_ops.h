#ifndef MATH_OPS_H
#define MATH_OPS_H

#include <stdint.h>
#include <stddef.h>

// 基本整数运算
int32_t add_int(int32_t a, int32_t b);
int32_t sub_int(int32_t a, int32_t b);
int32_t mul_int(int32_t a, int32_t b);
int32_t div_int(int32_t a, int32_t b);
int32_t mod_int(int32_t a, int32_t b);

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

#endif // MATH_OPS_H