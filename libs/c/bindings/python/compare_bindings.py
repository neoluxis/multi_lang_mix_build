#!/usr/bin/env python3
"""
Comparison of different C binding approaches.
"""

import sys
import time
import os

# Add library path
lib_path = os.path.join(os.path.dirname(__file__), '..', '..', '..', 'build', 'libs', 'c')
if lib_path not in os.environ.get('LD_LIBRARY_PATH', ''):
    os.environ['LD_LIBRARY_PATH'] = lib_path + ':' + os.environ.get('LD_LIBRARY_PATH', '')

def test_ctypes():
    """Test ctypes binding."""
    print("Testing ctypes binding...")
    try:
        from c_math import CMathOps
        c_math = CMathOps()

        # Test operations
        assert c_math.add(5, 3) == 8
        assert c_math.bitwise_and(12, 10) == 8
        assert c_math.sum_array([1, 2, 3, 4, 5]) == 15

        print("  ✓ ctypes binding works!")
        return True
    except Exception as e:
        print(f"  ✗ ctypes binding failed: {e}")
        return False

def test_cffi():
    """Test CFFI binding."""
    print("Testing CFFI binding...")
    try:
        from c_math_cffi import CMathOpsCFFI
        c_math = CMathOpsCFFI()

        # Test operations
        assert c_math.add(5, 3) == 8
        assert c_math.bitwise_and(12, 10) == 8
        assert c_math.sum_array([1, 2, 3, 4, 5]) == 15

        print("  ✓ CFFI binding works!")
        return True
    except Exception as e:
        print(f"  ✗ CFFI binding failed: {e}")
        return False

def test_cython():
    """Test Cython binding."""
    print("Testing Cython binding...")
    try:
        from c_math import CMathOps
        c_math = CMathOps()

        # Test operations
        assert c_math.add(5, 3) == 8
        assert c_math.bitwise_and(12, 10) == 8

        print("  ✓ Cython binding works!")
        return True
    except ImportError:
        print("  - Cython binding not compiled (run: python setup.py build_ext --inplace)")
        return False
    except Exception as e:
        print(f"  ✗ Cython binding failed: {e}")
        return False

def benchmark_binding(binding_func, name, iterations=10000):
    """Benchmark a binding approach."""
    print(f"Benchmarking {name}...")

    # Warm up
    for _ in range(100):
        binding_func()

    # Benchmark
    start_time = time.time()
    for _ in range(iterations):
        binding_func()
    end_time = time.time()

    avg_time = (end_time - start_time) / iterations * 1000  # ms
    print(".4f")
    return avg_time

def main():
    print("=== C Binding Methods Comparison ===\n")

    # Test each binding method
    ctypes_works = test_ctypes()
    cffi_works = test_cffi()
    cython_works = test_cython()

    print("\n=== Performance Comparison ===")

    if ctypes_works:
        def ctypes_op():
            from c_math import CMathOps
            c_math = CMathOps()
            return c_math.add(5, 3)

        ctypes_time = benchmark_binding(ctypes_op, "ctypes")

    if cffi_works:
        def cffi_op():
            from c_math_cffi import CMathOpsCFFI
            c_math = CMathOpsCFFI()
            return c_math.add(5, 3)

        cffi_time = benchmark_binding(cffi_op, "CFFI")

    if cython_works:
        def cython_op():
            from c_math import CMathOps
            c_math = CMathOps()
            return c_math.add(5, 3)

        cython_time = benchmark_binding(cython_op, "Cython")

    print("\n=== Summary ===")
    print("1. ctypes: 最简单，运行时加载库，无需编译")
    print("2. CFFI: 类型安全，运行时加载库，无需编译")
    print("3. Cython: 编译时链接，性能最好，无运行时依赖")
    print("\n当前实现使用 Cython，提供了最佳性能和无运行时依赖。")
    print("\n选择取决于您的需求：")
    print("- 快速原型开发 → ctypes")
    print("- 类型安全和性能 → CFFI")
    print("- 最高性能，无运行时依赖 → Cython (当前选择)")

if __name__ == "__main__":
    main()