"""
Python bindings for C math operations library using ctypes.
"""

import os
import ctypes
from typing import List, Union


class CMathOps:
    """Python wrapper for C math operations library."""

    def __init__(self):
        # Load the shared library
        lib_path = self._find_library('libmath_ops.so')
        if not lib_path:
            raise RuntimeError("Could not find libmath_ops.so library")

        self._lib = ctypes.CDLL(lib_path)

        # Define function signatures
        self._setup_function_signatures()

    def _find_library(self, lib_name: str) -> str:
        """Find the library in common locations."""
        search_paths = [
            os.path.join(os.path.dirname(__file__), '..', '..', '..', 'build', 'libs', 'c'),
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
        # Basic integer operations
        self._lib.add_int.argtypes = [ctypes.c_int32, ctypes.c_int32]
        self._lib.add_int.restype = ctypes.c_int32

        self._lib.sub_int.argtypes = [ctypes.c_int32, ctypes.c_int32]
        self._lib.sub_int.restype = ctypes.c_int32

        self._lib.mul_int.argtypes = [ctypes.c_int32, ctypes.c_int32]
        self._lib.mul_int.restype = ctypes.c_int32

        self._lib.div_int.argtypes = [ctypes.c_int32, ctypes.c_int32]
        self._lib.div_int.restype = ctypes.c_int32

        self._lib.mod_int.argtypes = [ctypes.c_int32, ctypes.c_int32]
        self._lib.mod_int.restype = ctypes.c_int32

        # Bitwise operations
        self._lib.bitwise_and.argtypes = [ctypes.c_uint32, ctypes.c_uint32]
        self._lib.bitwise_and.restype = ctypes.c_uint32

        self._lib.bitwise_or.argtypes = [ctypes.c_uint32, ctypes.c_uint32]
        self._lib.bitwise_or.restype = ctypes.c_uint32

        self._lib.bitwise_xor.argtypes = [ctypes.c_uint32, ctypes.c_uint32]
        self._lib.bitwise_xor.restype = ctypes.c_uint32

        self._lib.left_shift.argtypes = [ctypes.c_uint32, ctypes.c_int]
        self._lib.left_shift.restype = ctypes.c_uint32

        self._lib.right_shift.argtypes = [ctypes.c_uint32, ctypes.c_int]
        self._lib.right_shift.restype = ctypes.c_uint32

        # Array operations
        self._lib.sum_array.argtypes = [ctypes.POINTER(ctypes.c_int32), ctypes.c_size_t]
        self._lib.sum_array.restype = ctypes.c_int64

        self._lib.find_max.argtypes = [ctypes.POINTER(ctypes.c_int32), ctypes.c_size_t]
        self._lib.find_max.restype = ctypes.c_int32

        self._lib.find_min.argtypes = [ctypes.POINTER(ctypes.c_int32), ctypes.c_size_t]
        self._lib.find_min.restype = ctypes.c_int32

        # String operations
        self._lib.string_length.argtypes = [ctypes.c_char_p]
        self._lib.string_length.restype = ctypes.c_size_t

        self._lib.string_copy.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_size_t]
        self._lib.string_copy.restype = None

    # Basic arithmetic operations
    def add(self, a: int, b: int) -> int:
        """Add two integers."""
        return self._lib.add_int(a, b)

    def subtract(self, a: int, b: int) -> int:
        """Subtract two integers."""
        return self._lib.sub_int(a, b)

    def multiply(self, a: int, b: int) -> int:
        """Multiply two integers."""
        return self._lib.mul_int(a, b)

    def divide(self, a: int, b: int) -> int:
        """Divide two integers."""
        return self._lib.div_int(a, b)

    def modulo(self, a: int, b: int) -> int:
        """Modulo operation."""
        return self._lib.mod_int(a, b)

    # Bitwise operations
    def bitwise_and(self, a: int, b: int) -> int:
        """Bitwise AND operation."""
        return self._lib.bitwise_and(a, b)

    def bitwise_or(self, a: int, b: int) -> int:
        """Bitwise OR operation."""
        return self._lib.bitwise_or(a, b)

    def bitwise_xor(self, a: int, b: int) -> int:
        """Bitwise XOR operation."""
        return self._lib.bitwise_xor(a, b)

    def left_shift(self, value: int, shift: int) -> int:
        """Left shift operation."""
        return self._lib.left_shift(value, shift)

    def right_shift(self, value: int, shift: int) -> int:
        """Right shift operation."""
        return self._lib.right_shift(value, shift)

    # Array operations
    def sum_array(self, arr: List[int]) -> int:
        """Sum all elements in an integer array."""
        if not arr:
            return 0

        arr_type = ctypes.c_int32 * len(arr)
        c_arr = arr_type(*arr)
        return self._lib.sum_array(c_arr, len(arr))

    def find_max(self, arr: List[int]) -> int:
        """Find maximum value in an integer array."""
        if not arr:
            raise ValueError("Array cannot be empty")

        arr_type = ctypes.c_int32 * len(arr)
        c_arr = arr_type(*arr)
        return self._lib.find_max(c_arr, len(arr))

    def find_min(self, arr: List[int]) -> int:
        """Find minimum value in an integer array."""
        if not arr:
            raise ValueError("Array cannot be empty")

        arr_type = ctypes.c_int32 * len(arr)
        c_arr = arr_type(*arr)
        return self._lib.find_min(c_arr, len(arr))

    # String operations
    def string_length(self, s: str) -> int:
        """Get string length."""
        return self._lib.string_length(s.encode('utf-8'))

    def string_copy(self, src: str, max_len: int = 1024) -> str:
        """Copy string with maximum length."""
        dest = ctypes.create_string_buffer(max_len)
        self._lib.string_copy(dest, src.encode('utf-8'), max_len)
        return dest.value.decode('utf-8')