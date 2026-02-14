# cython: language_level=3

"""
Cython bindings for Assembly math operations library.
This compiles to a Python extension module that links directly to the assembly library.
"""

from libc.stdint cimport int64_t, uint64_t, uint32_t

# Declare C functions from our assembly library
cdef extern from "asm_math_ops/math_ops_asm.h":
    int64_t asm_add(int64_t a, int64_t b)
    int64_t asm_subtract(int64_t a, int64_t b)
    int64_t asm_multiply(int64_t a, int64_t b)
    uint64_t asm_factorial(uint32_t n)
    uint64_t asm_power(uint32_t base, uint32_t exp)
    uint64_t asm_bitwise_and(uint64_t a, uint64_t b)
    uint64_t asm_bitwise_or(uint64_t a, uint64_t b)
    uint64_t asm_left_shift(uint64_t value, int shift)


cdef class AsmMathOps:
    """Python wrapper for Assembly math operations library using Cython."""

    def add(self, int a, int b):
        """Add two 64-bit integers using assembly."""
        return asm_add(a, b)

    def subtract(self, int a, int b):
        """Subtract two 64-bit integers using assembly."""
        return asm_subtract(a, b)

    def multiply(self, int a, int b):
        """Multiply two 64-bit integers using assembly."""
        return asm_multiply(a, b)

    def factorial(self, int n):
        """Calculate factorial using assembly."""
        if n < 0:
            raise ValueError("Factorial is not defined for negative numbers")
        if n > 20:  # Prevent overflow
            raise ValueError("Factorial too large (max n=20)")
        return asm_factorial(n)

    def power(self, int base, int exp):
        """Calculate power using assembly."""
        if exp < 0:
            raise ValueError("Negative exponents not supported")
        return asm_power(base, exp)

    def bitwise_and(self, int a, int b):
        """Bitwise AND operation using assembly."""
        return asm_bitwise_and(a, b)

    def bitwise_or(self, int a, int b):
        """Bitwise OR operation using assembly."""
        return asm_bitwise_or(a, b)

    def left_shift(self, int value, int shift):
        """Left shift operation using assembly."""
        if shift < 0:
            raise ValueError("Negative shift not supported")
        return asm_left_shift(value, shift)