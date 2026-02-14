# cython: language_level=3

"""
Cython bindings for C math operations library.
This compiles to a Python extension module that links directly to the C library.
"""

from libc.stdint cimport int32_t, uint32_t
from libc.stddef cimport size_t

# Declare C functions from our library
cdef extern from "c_math_ops/math_ops.h":
    int32_t add_int(int32_t a, int32_t b)
    int32_t sub_int(int32_t a, int32_t b)
    int32_t mul_int(int32_t a, int32_t b)
    int32_t div_int(int32_t a, int32_t b)
    int32_t mod_int(int32_t a, int32_t b)
    uint32_t bitwise_and(uint32_t a, uint32_t b)
    uint32_t bitwise_or(uint32_t a, uint32_t b)
    uint32_t bitwise_xor(uint32_t a, uint32_t b)


cdef class CMathOps:
    """Python wrapper for C math operations library using Cython."""

    def add(self, int a, int b):
        """Add two integers."""
        return add_int(a, b)

    def subtract(self, int a, int b):
        """Subtract two integers."""
        return sub_int(a, b)

    def multiply(self, int a, int b):
        """Multiply two integers."""
        return mul_int(a, b)

    def divide(self, int a, int b):
        """Divide two integers."""
        if b == 0:
            raise ZeroDivisionError("Division by zero")
        return div_int(a, b)

    def mod(self, int a, int b):
        """Modulo operation."""
        if b == 0:
            raise ZeroDivisionError("Modulo by zero")
        return mod_int(a, b)

    def bitwise_and(self, int a, int b):
        """Bitwise AND operation."""
        return bitwise_and(a, b)

    def bitwise_or(self, int a, int b):
        """Bitwise OR operation."""
        return bitwise_or(a, b)

    def bitwise_xor(self, int a, int b):
        """Bitwise XOR operation."""
        return bitwise_xor(a, b)