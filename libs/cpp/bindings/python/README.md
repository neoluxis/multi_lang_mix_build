# C++ Calculator Python Bindings

This package provides Python bindings for the C++ Calculator library using pybind11.

## Features

- Basic arithmetic operations (add, subtract, multiply, divide)
- Advanced mathematical functions (power, square root, factorial, trigonometry)
- Array operations (sum, min, max, batch operations)
- Calculation history tracking
- Full OOP interface with Calculator and AdvancedCalculator classes

## Installation

### Prerequisites

- Python 3.6+
- CMake 3.10+
- C++ compiler (gcc, clang, etc.)
- pybind11

### Building from Source

1. Clone the repository and navigate to the C++ bindings directory:
   ```bash
   cd libs/cpp/bindings/python
   ```

2. Install dependencies:
   ```bash
   pip install pybind11
   ```

3. Build the extension:
   ```bash
   python setup.py build_ext --inplace
   ```

Or using pip:
```bash
pip install .
```

## Usage

### Basic Usage

```python
from cpp_calculator import CppCalculator

# Create calculator instance
calc = CppCalculator()

# Basic arithmetic
result = calc.add(5, 3)  # 8.0
result = calc.subtract(10, 4)  # 6.0
result = calc.multiply(6, 7)  # 42.0
result = calc.divide(15, 3)  # 5.0

# Get last result
last = calc.get_last_result()  # 5.0

# Get calculation history
history = calc.get_history()  # ['15 / 3 = 5']
```

### Advanced Operations

```python
# Mathematical functions
power = calc.power(2, 3)  # 8.0
sqrt_val = calc.square_root(16)  # 4.0
fact = calc.factorial(5)  # 120.0

# Trigonometric functions (degrees)
sin_val = calc.sine(90)  # 1.0
cos_val = calc.cosine(0)  # 1.0
```

### Array Operations

```python
# Array operations
numbers = [1, 2, 3, 4, 5]
total = calc.sum_array(numbers)  # 15
maximum = calc.max_element(numbers)  # 5
minimum = calc.min_element(numbers)  # 1

# Batch operations
batch_result = calc.batch_add(numbers, 10)  # [11.0, 12.0, 13.0, 14.0, 15.0]
```

## API Reference

### CppCalculator Class

#### Basic Operations
- `add(a, b)` - Add two numbers
- `subtract(a, b)` - Subtract two numbers
- `multiply(a, b)` - Multiply two numbers
- `divide(a, b)` - Divide two numbers

#### History Management
- `get_last_result()` - Get the last calculation result
- `get_history()` - Get list of all calculations
- `clear_history()` - Clear calculation history
- `get_calculator_type()` - Get calculator type string

#### Advanced Operations
- `power(base, exponent)` - Calculate power
- `square_root(value)` - Calculate square root
- `factorial(n)` - Calculate factorial
- `sine(angle)` - Calculate sine (degrees)
- `cosine(angle)` - Calculate cosine (degrees)

#### Array Operations
- `sum_array(arr)` - Sum all elements in array
- `max_element(arr)` - Find maximum element
- `min_element(arr)` - Find minimum element
- `batch_add(values, addend)` - Add value to each element in array

## Error Handling

The bindings include proper error handling:
- Division by zero raises `ZeroDivisionError`
- Square root of negative numbers raises `ValueError`
- Factorial of negative numbers raises `ValueError`
- Empty arrays for min/max operations raise `ValueError`

## Testing

Run the tests using pytest:

```bash
cd libs/cpp/bindings/python
python -m pytest tests/
```

## Dependencies

- pybind11 - For C++ to Python binding
- C++ Calculator library - The underlying C++ implementation

## License

MIT License