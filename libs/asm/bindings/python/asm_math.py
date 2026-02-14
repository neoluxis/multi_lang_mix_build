"""
Python bindings for Assembly math operations library using ctypes.
"""

import os
import ctypes
from typing import Union


class AsmMathOps:
    """Python wrapper for Assembly math operations library."""

    def __init__(self):
        # Load the shared library
        lib_path = self._find_library('libasm_math_ops.so')
        if not lib_path:
            raise RuntimeError("Could not find libasm_math_ops.so library")

        self._lib = ctypes.CDLL(lib_path)

        # Define function signatures
        self._setup_function_signatures()

    def _find_library(self, lib_name: str) -> str:
        """Find the library in common locations."""
        search_paths = [
            os.path.join(os.path.dirname(__file__), '..', '..', '..', 'build', 'lib'),
            '/usr/local/lib',
            '/usr/lib',
        ]

        for path in search_paths:
            lib_path = os.path.join(path, lib_name)
            if os.path.exists(lib_path):
                return lib_path

        # Try to find in system paths
        try:
            return ctypes.util.find_library(lib_name.replace('lib', '').replace('.so', ''))
        except:
            pass

        return None

    def _setup_function_signatures(self):
        """Setup ctypes function signatures."""
        # Basic operations
        self._lib.asm_add.argtypes = [ctypes.c_int64, ctypes.c_int64]
        self._lib.asm_add.restype = ctypes.c_int64

        self._lib.asm_subtract.argtypes = [ctypes.c_int64, ctypes.c_int64]
        self._lib.asm_subtract.restype = ctypes.c_int64

        self._lib.asm_multiply.argtypes = [ctypes.c_int64, ctypes.c_int64]
        self._lib.asm_multiply.restype = ctypes.c_int64

        # Advanced operations
        self._lib.asm_factorial.argtypes = [ctypes.c_uint32]
        self._lib.asm_factorial.restype = ctypes.c_uint64

        self._lib.asm_power.argtypes = [ctypes.c_uint32, ctypes.c_uint32]
        self._lib.asm_power.restype = ctypes.c_uint64

        # Bitwise operations
        self._lib.asm_bitwise_and.argtypes = [ctypes.c_uint64, ctypes.c_uint64]
        self._lib.asm_bitwise_and.restype = ctypes.c_uint64

        self._lib.asm_bitwise_or.argtypes = [ctypes.c_uint64, ctypes.c_uint64]
        self._lib.asm_bitwise_or.restype = ctypes.c_uint64

        self._lib.asm_left_shift.argtypes = [ctypes.c_uint64, ctypes.c_int]
        self._lib.asm_left_shift.restype = ctypes.c_uint64

    # Basic arithmetic operations
    def add(self, a: Union[int, float], b: Union[int, float]) -> int:
        """Add two 64-bit integers using assembly."""
        return self._lib.asm_add(int(a), int(b))

    def subtract(self, a: Union[int, float], b: Union[int, float]) -> int:
        """Subtract two 64-bit integers using assembly."""
        return self._lib.asm_subtract(int(a), int(b))

    def multiply(self, a: Union[int, float], b: Union[int, float]) -> int:
        """Multiply two 64-bit integers using assembly."""
        return self._lib.asm_multiply(int(a), int(b))

    # Advanced operations
    def factorial(self, n: int) -> int:
        """Calculate factorial using assembly."""
        if n < 0:
            raise ValueError("Factorial is not defined for negative numbers")
        if n > 20:  # Prevent overflow
            raise ValueError("Factorial too large (max n=20)")
        return self._lib.asm_factorial(n)

    def power(self, base: int, exp: int) -> int:
        """Calculate power using assembly."""
        if exp < 0:
            raise ValueError("Negative exponents not supported")
        return self._lib.asm_power(base, exp)

    # Bitwise operations
    def bitwise_and(self, a: int, b: int) -> int:
        """Bitwise AND operation using assembly."""
        return self._lib.asm_bitwise_and(a, b)

    def bitwise_or(self, a: int, b: int) -> int:
        """Bitwise OR operation using assembly."""
        return self._lib.asm_bitwise_or(a, b)

    def left_shift(self, value: int, shift: int) -> int:
        """Left shift operation using assembly."""
        if shift < 0:
            raise ValueError("Negative shift not supported")
        return self._lib.asm_left_shift(value, shift)