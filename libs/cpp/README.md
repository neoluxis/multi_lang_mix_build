# C++ 面向对象计算器库

本库展示了C++面向对象编程的完整特性，包括继承、多态、模板、异常处理等现代C++特性。

## 功能特性

### 核心类设计

#### Calculator (基础计算器)
- **基本运算**: 加减乘除运算
- **历史记录**: 自动记录计算历史
- **结果缓存**: 保存最后计算结果
- **类型标识**: 返回计算器类型

#### AdvancedCalculator (高级计算器)
继承自Calculator，提供扩展功能：
- **科学运算**: 幂运算、阶乘、三角函数、平方根
- **模板方法**: 泛型数组操作
- **批量处理**: 数组批量运算
- **多态操作**: 支持可扩展的操作类

#### Operation (操作基类)
- **多态设计**: 纯虚函数接口
- **扩展性**: 支持自定义操作
- **类型安全**: 编译时类型检查

### 高级特性展示

#### 继承和多态
```cpp
Calculator* calc = new AdvancedCalculator();
std::cout << calc->getCalculatorType(); // "Advanced Calculator"
```

#### 模板编程
```cpp
std::vector<int> arr = {1, 2, 3, 4, 5};
int sum = adv_calc.sum_array(arr);
int max_val = adv_calc.max_element(arr);
```

#### 异常处理
```cpp
try {
    double result = calc.divide(10.0, 0.0);
} catch (const CalculatorException& e) {
    std::cout << e.what(); // "Division by zero!"
}
```

## 构建方法

### 依赖要求
- C++14兼容编译器 (GCC 5+, Clang 3.4+, MSVC 2017+)
- CMake 3.10+
- 数学库 (libm)

### 使用CMake构建

```bash
# 在项目根目录
mkdir build && cd build
cmake ..
make

# 构建产物
# 静态库: lib/libcpp_calculator.a
# 测试程序: bin/test_cpp_calculator
```

### 手动编译

```bash
# 编译源文件
g++ -c Calculator.cpp -std=c++14 -o Calculator.o
ar rcs libcpp_calculator.a Calculator.o

# 编译测试程序
g++ test_main.cpp -L. -lcpp_calculator -lm -std=c++14 -o test_cpp_calculator
```

## 使用方法

### 基础计算器使用

```cpp
#include "Calculator.h"

int main() {
    Calculator calc;

    // 基本运算
    double result = calc.add(10.5, 5.2);
    std::cout << "Result: " << result << std::endl;

    // 获取历史记录
    const auto& history = calc.getHistory();
    for (const auto& entry : history) {
        std::cout << entry << std::endl;
    }

    return 0;
}
```

### 高级计算器使用

```cpp
#include "Calculator.h"
#include <vector>

int main() {
    AdvancedCalculator adv_calc;

    // 科学运算
    double power = adv_calc.power(2.0, 10);     // 1024
    double sqrt_val = adv_calc.square_root(144.0); // 12
    double fact = adv_calc.factorial(5);         // 120
    double sin_val = adv_calc.sine(30.0);        // 0.5

    // 模板数组操作
    std::vector<double> double_arr = {1.1, 2.2, 3.3};
    double sum = adv_calc.sum_array(double_arr);
    double max_val = adv_calc.max_element(double_arr);

    std::vector<int> int_arr = {10, 20, 5, 30};
    int int_sum = adv_calc.sum_array(int_arr);

    // 批量操作
    std::vector<double> values = {1.0, 2.0, 3.0};
    auto results = adv_calc.batch_add(values, 10.0);
    // results: {11.0, 12.0, 13.0}

    return 0;
}
```

### 多态使用

```cpp
#include "Calculator.h"

void use_calculator(Calculator* calc) {
    std::cout << "Using: " << calc->getCalculatorType() << std::endl;
    calc->add(5.0, 3.0);
}

int main() {
    Calculator* basic = new Calculator();
    Calculator* advanced = new AdvancedCalculator();

    use_calculator(basic);     // "Using: Basic Calculator"
    use_calculator(advanced);  // "Using: Advanced Calculator"

    delete basic;
    delete advanced;

    return 0;
}
```

## API文档

### Calculator类

```cpp
class Calculator {
public:
    Calculator();
    virtual ~Calculator() = default;

    // 基本运算
    virtual double add(double a, double b);
    virtual double subtract(double a, double b);
    virtual double multiply(double a, double b);
    virtual double divide(double a, double b);

    // 访问方法
    double getLastResult() const;
    const std::vector<std::string>& getHistory() const;
    void clearHistory();

    // 多态方法
    virtual std::string getCalculatorType() const;
};
```

### AdvancedCalculator类

```cpp
class AdvancedCalculator : public Calculator {
public:
    AdvancedCalculator();
    ~AdvancedCalculator() override;

    // 科学运算
    double power(double base, int exponent);
    double square_root(double value);
    double factorial(int n);
    double sine(double angle);    // 角度制
    double cosine(double angle);  // 角度制

    // 模板方法
    template<typename T>
    T sum_array(const std::vector<T>& arr);

    template<typename T>
    T max_element(const std::vector<T>& arr);

    template<typename T>
    T min_element(const std::vector<T>& arr);

    // 批量操作
    std::vector<double> batch_add(const std::vector<double>& values, double addend);

    // 重写方法
    std::string getCalculatorType() const override;
};
```

### 异常类

```cpp
class CalculatorException : public std::exception {
public:
    explicit CalculatorException(const std::string& message);
    const char* what() const noexcept override;
};
```

## 设计模式

### 模板方法模式
数组操作方法使用模板提供类型安全和代码复用。

### 工厂模式
Operation类可以扩展为工厂模式创建不同操作实例。

### 策略模式
不同的计算策略可以通过继承和多态实现。

## 测试

运行测试程序验证所有功能：

```bash
./bin/test_cpp_calculator
```

测试覆盖：
- 基础计算器功能测试
- 高级计算器扩展功能
- 多态行为验证
- 异常处理测试
- 模板方法类型安全

## 性能特点

- **类型安全**: 编译时类型检查，运行时安全
- **零开销抽象**: 现代C++优化，接近汇编性能
- **内存安全**: RAII和智能指针管理
- **扩展性**: 面向对象设计便于功能扩展

## 平台支持

- **编译器**: GCC 5+, Clang 3.4+, MSVC 2017+
- **标准库**: C++14标准库
- **操作系统**: Linux, macOS, Windows

## 扩展建议

- 添加更多科学函数 (对数、指数等)
- 实现计算器插件系统
- 添加表达式解析器
- 支持复数运算
- 实现计算历史持久化

## 许可证

本项目遵循项目根目录的许可证。