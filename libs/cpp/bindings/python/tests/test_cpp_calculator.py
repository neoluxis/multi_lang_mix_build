"""
Tests for C++ Calculator Python bindings.
"""

import pytest
import sys
import os

# Add the Python bindings directory to path
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))

try:
    from cpp_calculator import CppCalculator
    CPP_BINDINGS_AVAILABLE = True
except ImportError:
    CPP_BINDINGS_AVAILABLE = False
    CppCalculator = None


@pytest.mark.skipif(not CPP_BINDINGS_AVAILABLE, reason="C++ Python bindings not available")
class TestCppCalculator:
    """Test C++ Calculator Python bindings."""

    def setup_method(self):
        """Set up test fixtures."""
        self.calc = CppCalculator()

    def test_basic_arithmetic(self):
        """Test basic arithmetic operations."""
        assert self.calc.add(5, 3) == 8.0
        assert self.calc.subtract(10, 4) == 6.0
        assert self.calc.multiply(6, 7) == 42.0
        assert self.calc.divide(15, 3) == 5.0

    def test_division_by_zero(self):
        """Test division by zero raises exception."""
        with pytest.raises(ZeroDivisionError):
            self.calc.divide(10, 0)

    def test_last_result(self):
        """Test getting last result."""
        self.calc.add(2, 3)
        assert self.calc.get_last_result() == 5.0

        self.calc.multiply(4, 5)
        assert self.calc.get_last_result() == 20.0

    def test_history(self):
        """Test calculation history."""
        self.calc.add(1, 2)
        self.calc.subtract(5, 3)
        self.calc.multiply(2, 4)

        history = self.calc.get_history()
        assert len(history) == 3
        assert "1 + 2 = 3" in history
        assert "5 - 3 = 2" in history
        assert "2 * 4 = 8" in history

    def test_clear_history(self):
        """Test clearing history."""
        self.calc.add(1, 1)
        assert len(self.calc.get_history()) == 1

        self.calc.clear_history()
        assert len(self.calc.get_history()) == 0

    def test_calculator_type(self):
        """Test calculator type."""
        assert self.calc.get_calculator_type() == "Basic Calculator"

    def test_power(self):
        """Test power function."""
        assert self.calc.power(2, 3) == 8.0
        assert self.calc.power(5, 0) == 1.0
        assert self.calc.power(3, 2) == 9.0

    def test_square_root(self):
        """Test square root function."""
        assert abs(self.calc.square_root(9) - 3.0) < 1e-6
        assert abs(self.calc.square_root(16) - 4.0) < 1e-6
        assert self.calc.square_root(0) == 0.0

    def test_square_root_negative(self):
        """Test square root of negative number raises exception."""
        with pytest.raises(ValueError):
            self.calc.square_root(-1)

    def test_factorial(self):
        """Test factorial function."""
        assert self.calc.factorial(0) == 1.0
        assert self.calc.factorial(1) == 1.0
        assert self.calc.factorial(5) == 120.0
        assert self.calc.factorial(10) == 3628800.0

    def test_factorial_negative(self):
        """Test factorial of negative number raises exception."""
        with pytest.raises(ValueError):
            self.calc.factorial(-1)

    def test_factorial_large(self):
        """Test factorial of large number raises exception."""
        with pytest.raises(ValueError):
            self.calc.factorial(200)

    def test_trigonometric_functions(self):
        """Test sine and cosine functions."""
        # Test sine at 0, 90, 180 degrees
        assert abs(self.calc.sine(0) - 0.0) < 1e-6
        assert abs(self.calc.sine(90) - 1.0) < 1e-6
        assert abs(self.calc.sine(180) - 0.0) < 1e-6

        # Test cosine at 0, 90, 180 degrees
        assert abs(self.calc.cosine(0) - 1.0) < 1e-6
        assert abs(self.calc.cosine(90) - 0.0) < 1e-6
        assert abs(self.calc.cosine(180) + 1.0) < 1e-6

    def test_array_operations(self):
        """Test array operations."""
        int_arr = [1, 2, 3, 4, 5]
        float_arr = [1.5, 2.5, 3.5]

        # Test sum
        assert self.calc.sum_array(int_arr) == 15
        assert abs(self.calc.sum_array(float_arr) - 7.5) < 1e-6

        # Test max
        assert self.calc.max_element(int_arr) == 5
        assert self.calc.max_element(float_arr) == 3.5

        # Test min
        assert self.calc.min_element(int_arr) == 1
        assert self.calc.min_element(float_arr) == 1.5

    def test_empty_array_operations(self):
        """Test operations on empty arrays."""
        with pytest.raises(ValueError):
            self.calc.max_element([])

        with pytest.raises(ValueError):
            self.calc.min_element([])

        assert self.calc.sum_array([]) == 0

    def test_batch_operations(self):
        """Test batch operations."""
        values = [1, 2, 3, 4]
        result = self.calc.batch_add(values, 10)
        expected = [11.0, 12.0, 13.0, 14.0]
        assert result == expected


if __name__ == "__main__":
    pytest.main([__file__])