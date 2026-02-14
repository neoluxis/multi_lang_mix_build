#ifndef MATH_OPS_ASM_H
#define MATH_OPS_ASM_H

#include <stdint.h>

// x64 汇编实现的计算函数
extern int64_t asm_add(int64_t a, int64_t b);
extern int64_t asm_subtract(int64_t a, int64_t b);
extern int64_t asm_multiply(int64_t a, int64_t b);
extern uint64_t asm_factorial(uint32_t n);
extern uint64_t asm_power(uint32_t base, uint32_t exp);
extern uint64_t asm_bitwise_and(uint64_t a, uint64_t b);
extern uint64_t asm_bitwise_or(uint64_t a, uint64_t b);
extern uint64_t asm_left_shift(uint64_t value, int shift);

#endif // MATH_OPS_ASM_H