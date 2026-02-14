#!/usr/bin/env python3
"""
Python示例：使用多语言数学库
演示如何在Python中同时使用C、汇编和C++库的绑定

这个示例展示了：
- C库：基本算术和位运算
- 汇编库：高性能数学运算
- C++库：面向对象的高级数学功能
"""

import sys
import os
import time
from typing import List

# 添加库路径
project_root = os.path.dirname(os.path.dirname(os.path.dirname(__file__)))
sys.path.insert(0, os.path.join(project_root, 'libs', 'c', 'bindings', 'python'))
sys.path.insert(0, os.path.join(project_root, 'libs', 'asm', 'bindings', 'python'))
sys.path.insert(0, os.path.join(project_root, 'libs', 'cpp', 'bindings', 'python'))

# 设置库路径（如果需要运行时加载）
lib_paths = [
    os.path.join(project_root, 'build', 'lib'),
    os.path.join(project_root, 'build', 'libs', 'c'),
]
for path in lib_paths:
    if path not in os.environ.get('LD_LIBRARY_PATH', ''):
        os.environ['LD_LIBRARY_PATH'] = path + ':' + os.environ.get('LD_LIBRARY_PATH', '')

# 导入库
try:
    from c_math import CMathOps
    from asm_math import AsmMathOps
    from cpp_calculator import CppCalculator
    print("✓ 所有库导入成功！")
except ImportError as e:
    print(f"✗ 导入失败: {e}")
    print("请确保已构建所有库: cmake .. && make -j$(nproc)")
    sys.exit(1)


def demonstrate_c_library():
    """演示C库功能"""
    print("\n" + "="*50)
    print("🧮 C库演示 - 基本算术和位运算")
    print("="*50)

    c_math = CMathOps()

    # 基本算术
    print("\n📊 基本算术运算:")
    a, b = 15, 7
    print(f"  {a} + {b} = {c_math.add(a, b)}")
    print(f"  {a} - {b} = {c_math.subtract(a, b)}")
    print(f"  {a} × {b} = {c_math.multiply(a, b)}")
    print(f"  {a} ÷ {b} = {c_math.divide(a, b)}")
    print(f"  {a} % {b} = {c_math.mod(a, b)}")

    # 位运算
    print("\n🔢 位运算:")
    x, y = 12, 10  # 1100, 1010
    print(f"  {x} AND {y} = {c_math.bitwise_and(x, y)}  # {bin(x)} & {bin(y)} = {bin(c_math.bitwise_and(x, y))}")
    print(f"  {x} OR  {y} = {c_math.bitwise_or(x, y)}   # {bin(x)} | {bin(y)} = {bin(c_math.bitwise_or(x, y))}")
    print(f"  {x} XOR {y} = {c_math.bitwise_xor(x, y)} # {bin(x)} ^ {bin(y)} = {bin(c_math.bitwise_xor(x, y))}")

    return c_math


def demonstrate_assembly_library():
    """演示汇编库功能"""
    print("\n" + "="*50)
    print("⚡ 汇编库演示 - 高性能数学运算")
    print("="*50)

    asm_math = AsmMathOps()

    # 基本运算
    print("\n📈 基本运算:")
    a, b = 25, 7
    print(f"  {a} + {b} = {asm_math.add(a, b)}")
    print(f"  {a} × {b} = {asm_math.multiply(a, b)}")

    # 高级运算
    print("\n🚀 高级运算:")
    n = 6
    print(f"  {n}! = {asm_math.factorial(n)}")

    base, exp = 3, 5
    print(f"  {base}^{exp} = {asm_math.power(base, exp)}")

    # 位运算
    print("\n🔧 位运算:")
    value = 16
    shift = 2
    print(f"  {value} << {shift} = {asm_math.left_shift(value, shift)}")

    return asm_math


def demonstrate_cpp_library():
    """演示C++库功能"""
    print("\n" + "="*50)
    print("🎯 C++库演示 - 面向对象高级功能")
    print("="*50)

    cpp_calc = CppCalculator()

    # 基本运算
    print("\n🧮 基本计算器:")
    a, b = 10, 3
    print(f"  {a} + {b} = {cpp_calc.add(a, b)}")
    print(f"  {a} - {b} = {cpp_calc.subtract(a, b)}")
    print(f"  {a} × {b} = {cpp_calc.multiply(a, b)}")
    print(f"  {a} ÷ {b} = {cpp_calc.divide(a, b)}")

    # 高级数学
    print("\n🔬 高级数学:")
    print(f"  2^8 = {cpp_calc.power(2, 8)}")
    print(f"  √16 = {cpp_calc.square_root(16)}")
    print(f"  5! = {cpp_calc.factorial(5)}")

    # 三角函数
    print("\n📐 三角函数:")
    angles = [0, 30, 45, 60, 90]
    for angle in angles:
        sin_val = cpp_calc.sine(angle)
        cos_val = cpp_calc.cosine(angle)
        print("2d")

    # 历史记录
    print("\n📝 计算历史:")
    history = cpp_calc.get_history()
    for i, entry in enumerate(history[-5:], 1):  # 显示最后5条记录
        print(f"  {i}. {entry}")

    return cpp_calc


def performance_comparison():
    """性能对比测试"""
    print("\n" + "="*50)
    print("⚡ 性能对比测试")
    print("="*50)

    # 初始化库
    c_math = CMathOps()
    asm_math = AsmMathOps()
    cpp_calc = CppCalculator()

    # 测试数据
    test_cases = [
        ("加法", lambda: c_math.add(123456, 789012)),
        ("汇编加法", lambda: asm_math.add(123456, 789012)),
        ("C++加法", lambda: cpp_calc.add(123456, 789012)),
        ("阶乘", lambda: asm_math.factorial(10)),
        ("C++阶乘", lambda: cpp_calc.factorial(10)),
        ("幂运算", lambda: asm_math.power(2, 20)),
        ("C++幂运算", lambda: cpp_calc.power(2, 20)),
    ]

    print("\n⏱️  性能测试 (1000次调用):")
    print("-" * 60)

    for name, func in test_cases:
        # 预热
        for _ in range(100):
            func()

        # 计时
        start_time = time.time()
        iterations = 1000
        for _ in range(iterations):
            func()
        end_time = time.time()

        avg_time = (end_time - start_time) / iterations * 1_000_000  # 微秒
        print("30s")


def combined_demo():
    """组合使用演示"""
    print("\n" + "="*50)
    print("🎪 组合使用演示")
    print("="*50)

    # 初始化所有库
    c_math = CMathOps()
    asm_math = AsmMathOps()
    cpp_calc = CppCalculator()

    print("\n🔄 计算流程: (2 + 3) × 4! ÷ √16")
    print("   分解步骤:")

    # 步骤1: C库做加法
    step1 = c_math.add(2, 3)
    print(f"   1. C库加法: 2 + 3 = {step1}")

    # 步骤2: 汇编库算阶乘
    step2 = asm_math.factorial(4)
    print(f"   2. 汇编阶乘: 4! = {step2}")

    # 步骤3: C++库算平方根
    step3 = cpp_calc.square_root(16)
    print(f"   3. C++平方根: √16 = {step3}")

    # 步骤4: C++库做乘法和除法
    step4 = cpp_calc.multiply(step1, step2)
    print(f"   4. C++乘法: {step1} × {step2} = {step4}")

    final_result = cpp_calc.divide(step4, step3)
    print(f"   5. C++除法: {step4} ÷ {step3} = {final_result}")

    print(f"\n🎉 最终结果: {final_result}")


def error_handling_demo():
    """错误处理演示"""
    print("\n" + "="*50)
    print("🛡️  错误处理演示")
    print("="*50)

    c_math = CMathOps()
    asm_math = AsmMathOps()
    cpp_calc = CppCalculator()

    print("\n🚫 除零错误:")
    try:
        result = c_math.divide(10, 0)
    except ZeroDivisionError as e:
        print(f"   C库: {e}")

    try:
        result = cpp_calc.divide(10, 0)
    except Exception as e:
        print(f"   C++库: {e}")

    print("\n🚫 无效输入:")
    try:
        result = asm_math.factorial(-1)
    except ValueError as e:
        print(f"   负数阶乘: {e}")

    try:
        result = cpp_calc.square_root(-4)
    except ValueError as e:
        print(f"   负数平方根: {e}")

    try:
        result = asm_math.power(2, -1)
    except ValueError as e:
        print(f"   负数指数: {e}")


def main():
    """主函数"""
    print("🌟 多语言数学库Python绑定示例")
    print("=" * 60)
    print("这个示例演示了如何在Python中同时使用三个不同语言实现的库:")
    print("• C库: 基本算术和位运算")
    print("• 汇编库: 高性能数学运算")
    print("• C++库: 面向对象的高级数学功能")
    print("=" * 60)

    try:
        # 演示各个库的功能
        demonstrate_c_library()
        demonstrate_assembly_library()
        demonstrate_cpp_library()

        # 组合使用演示
        combined_demo()

        # 错误处理演示
        error_handling_demo()

        # 性能对比
        performance_comparison()

        print("\n" + "="*60)
        print("🎊 示例完成！所有库都成功集成到Python中！")
        print("="*60)

    except Exception as e:
        print(f"\n❌ 运行出错: {e}")
        print("请确保所有库都已正确构建。")
        return 1

    return 0


if __name__ == "__main__":
    sys.exit(main())