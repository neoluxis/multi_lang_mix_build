#include <stdio.h>
#include <stdint.h>
#include "math_ops_asm.h"

int main() {
    printf("Testing x64 Assembly Math Operations\n");
    printf("=====================================\n\n");

    // 测试加法
    int64_t a = 42, b = 58;
    printf("Addition: %lld + %lld = %lld\n", a, b, asm_add(a, b));

    // 测试减法
    printf("Subtraction: %lld - %lld = %lld\n", a, b, asm_subtract(a, b));

    // 测试乘法
    int64_t x = 7, y = 9;
    printf("Multiplication: %lld * %lld = %lld\n", x, y, asm_multiply(x, y));

    // 测试阶乘
    uint32_t n = 5;
    printf("Factorial: %u! = %llu\n", n, asm_factorial(n));

    // 测试幂运算
    uint32_t base = 2, exp = 8;
    printf("Power: %u^%u = %llu\n", base, exp, asm_power(base, exp));

    // 测试位运算
    uint64_t p = 0xFF00, q = 0x00FF;
    printf("Bitwise AND: 0x%llX & 0x%llX = 0x%llX\n", p, q, asm_bitwise_and(p, q));
    printf("Bitwise OR:  0x%llX | 0x%llX = 0x%llX\n", p, q, asm_bitwise_or(p, q));

    // 测试左移
    uint64_t value = 1;
    int shift = 5;
    printf("Left shift: %llu << %d = %llu\n", value, shift, asm_left_shift(value, shift));

    printf("\nAll x64 assembly tests completed successfully!\n");
    return 0;
}