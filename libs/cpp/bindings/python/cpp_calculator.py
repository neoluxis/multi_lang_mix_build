"""
Python bindings for C++ Calculator library using pybind11.
"""

import os
import sys
from typing import List, Union


class CppCalculator:
    """Python wrapper for C++ Calculator library using pybind11."""

    def __init__(self):
        # Try to import the compiled module
        try:
            # Add possible build library paths to sys.path
            possible_paths = [
                os.path.join(os.path.dirname(__file__), '..', '..', '..', 'build', 'lib', 'python'),
                os.path.join(os.path.dirname(__file__), '..', '..', '..', '..', 'build', 'lib', 'python'),
                os.path.join(os.path.dirname(__file__), 'build', 'lib', 'python'),
            ]

            module_found = False
            for path in possible_paths:
                if os.path.exists(path) and path not in sys.path:
                    sys.path.insert(0, path)
                    try:
                        import cpp_calculator_py as cpp_mod
                        self._cpp_mod = cpp_mod
                        module_found = True
                        break
                    except ImportError:
                        continue

            if not module_found:
                # Try direct import (if already in path)
                import cpp_calculator_py as cpp_mod
                self._cpp_mod = cpp_mod

            self._calc = None
            self._advanced_calc = None
        except ImportError as e:
            raise RuntimeError(f"Could not import cpp_calculator_py module: {e}. "
                             "Make sure the C++ extension is compiled and the build/lib/python "
                             "directory is in your Python path.")

    def _get_basic_calculator(self):
        """Get or create basic calculator instance."""
        if self._calc is None:
            self._calc = self._cpp_mod.Calculator()
        return self._calc

    def _get_advanced_calculator(self):
        """Get or create advanced calculator instance."""
        if self._advanced_calc is None:
            self._advanced_calc = self._cpp_mod.AdvancedCalculator()
        return self._advanced_calc

    # Basic calculator operations
    def add(self, a: Union[int, float], b: Union[int, float]) -> float:
        """Add two numbers."""
        return self._get_basic_calculator().add(float(a), float(b))

    def subtract(self, a: Union[int, float], b: Union[int, float]) -> float:
        """Subtract two numbers."""
        return self._get_basic_calculator().subtract(float(a), float(b))

    def multiply(self, a: Union[int, float], b: Union[int, float]) -> float:
        """Multiply two numbers."""
        return self._get_basic_calculator().multiply(float(a), float(b))

    def divide(self, a: Union[int, float], b: Union[int, float]) -> float:
        """Divide two numbers."""
        try:
            return self._get_basic_calculator().divide(float(a), float(b))
        except self._cpp_mod.CalculatorException as e:
            if "Division by zero" in str(e):
                raise ZeroDivisionError("Division by zero")
            raise

    def get_last_result(self) -> float:
        """Get the last calculation result."""
        return self._get_basic_calculator().get_last_result()

    def get_history(self) -> List[str]:
        """Get calculation history."""
        return self._get_basic_calculator().get_history()

    def clear_history(self):
        """Clear calculation history."""
        self._get_basic_calculator().clear_history()

    def get_calculator_type(self) -> str:
        """Get calculator type."""
        return self._get_basic_calculator().get_calculator_type()

    # Advanced calculator operations
    def power(self, base: Union[int, float], exponent: int) -> float:
        """Calculate power."""
        return self._get_advanced_calculator().power(float(base), exponent)

    def square_root(self, value: Union[int, float]) -> float:
        """Calculate square root."""
        if value < 0:
            raise ValueError("Cannot calculate square root of negative number")
        try:
            return self._get_advanced_calculator().square_root(float(value))
        except self._cpp_mod.CalculatorException as e:
            if "negative number" in str(e):
                raise ValueError("Cannot calculate square root of negative number")
            raise

    def factorial(self, n: int) -> float:
        """Calculate factorial."""
        if n < 0:
            raise ValueError("Factorial is not defined for negative numbers")
        if n > 170:  # Prevent overflow
            raise ValueError("Factorial too large")
        try:
            return self._get_advanced_calculator().factorial(n)
        except self._cpp_mod.CalculatorException as e:
            if "negative number" in str(e):
                raise ValueError("Factorial is not defined for negative numbers")
            raise

    def sine(self, angle: Union[int, float]) -> float:
        """Calculate sine (degrees)."""
        return self._get_advanced_calculator().sine(float(angle))

    def cosine(self, angle: Union[int, float]) -> float:
        """Calculate cosine (degrees)."""
        return self._get_advanced_calculator().cosine(float(angle))

    # Array operations
    def sum_array(self, arr: List[Union[int, float]]) -> Union[int, float]:
        """Sum all elements in an array."""
        if not arr:
            return 0

        if isinstance(arr[0], int):
            return self._get_advanced_calculator().sum_array_int(arr)
        else:
            return self._get_advanced_calculator().sum_array_double([float(x) for x in arr])

    def max_element(self, arr: List[Union[int, float]]) -> Union[int, float]:
        """Find maximum element in an array."""
        if not arr:
            raise ValueError("Array cannot be empty")

        if isinstance(arr[0], int):
            return self._get_advanced_calculator().max_element_int(arr)
        else:
            return self._get_advanced_calculator().max_element_double([float(x) for x in arr])

    def min_element(self, arr: List[Union[int, float]]) -> Union[int, float]:
        """Find minimum element in an array."""
        if not arr:
            raise ValueError("Array cannot be empty")

        if isinstance(arr[0], int):
            return self._get_advanced_calculator().min_element_int(arr)
        else:
            return self._get_advanced_calculator().min_element_double([float(x) for x in arr])

    def batch_add(self, values: List[Union[int, float]], addend: Union[int, float]) -> List[float]:
        """Batch add operation."""
        return self._get_advanced_calculator().batch_add([float(x) for x in values], float(addend))