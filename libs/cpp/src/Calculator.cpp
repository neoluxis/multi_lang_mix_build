#include "cpp_calculator/Calculator.h"
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iostream>

// Calculator 类的实现
Calculator::Calculator() : last_result_(0.0) {}

double Calculator::add(double a, double b)
{
    double result = a + b;
    last_result_ = result;

    std::ostringstream oss;
    oss << a << " + " << b << " = " << result;
    history_.push_back(oss.str());

    return result;
}

double Calculator::subtract(double a, double b)
{
    double result = a - b;
    last_result_ = result;

    std::ostringstream oss;
    oss << a << " - " << b << " = " << result;
    history_.push_back(oss.str());

    return result;
}

double Calculator::multiply(double a, double b)
{
    double result = a * b;
    last_result_ = result;

    std::ostringstream oss;
    oss << a << " * " << b << " = " << result;
    history_.push_back(oss.str());

    return result;
}

double Calculator::divide(double a, double b)
{
    if (b == 0.0)
    {
        throw CalculatorException("Division by zero!");
    }

    double result = a / b;
    last_result_ = result;

    std::ostringstream oss;
    oss << a << " / " << b << " = " << result;
    history_.push_back(oss.str());

    return result;
}

void Calculator::clearHistory()
{
    history_.clear();
}

// AdvancedCalculator 类的实现
AdvancedCalculator::AdvancedCalculator()
{
    // 初始化操作集合
    operations_.push_back(std::make_unique<AddOperation>());
    operations_.push_back(std::make_unique<MultiplyOperation>());
}

double AdvancedCalculator::power(double base, int exponent)
{
    double result = std::pow(base, exponent);
    last_result_ = result;

    std::ostringstream oss;
    oss << base << "^" << exponent << " = " << result;
    history_.push_back(oss.str());

    return result;
}

double AdvancedCalculator::square_root(double value)
{
    if (value < 0)
    {
        throw CalculatorException("Cannot calculate square root of negative number!");
    }

    double result = std::sqrt(value);
    last_result_ = result;

    std::ostringstream oss;
    oss << "sqrt(" << value << ") = " << result;
    history_.push_back(oss.str());

    return result;
}

double AdvancedCalculator::factorial(int n)
{
    if (n < 0)
    {
        throw CalculatorException("Factorial of negative number is undefined!");
    }

    double result = 1.0;
    for (int i = 2; i <= n; ++i)
    {
        result *= i;
    }

    last_result_ = result;

    std::ostringstream oss;
    oss << n << "! = " << result;
    history_.push_back(oss.str());

    return result;
}

double AdvancedCalculator::sine(double angle)
{
    // 角度转换为弧度
    double radians = angle * M_PI / 180.0;
    double result = std::sin(radians);
    last_result_ = result;

    std::ostringstream oss;
    oss << "sin(" << angle << "°) = " << result;
    history_.push_back(oss.str());

    return result;
}

double AdvancedCalculator::cosine(double angle)
{
    // 角度转换为弧度
    double radians = angle * M_PI / 180.0;
    double result = std::cos(radians);
    last_result_ = result;

    std::ostringstream oss;
    oss << "cos(" << angle << "°) = " << result;
    history_.push_back(oss.str());

    return result;
}

// 模板方法的实现
template <typename T>
T AdvancedCalculator::sum_array(const std::vector<T> &arr)
{
    T sum = 0;
    for (const auto &val : arr)
    {
        sum += val;
    }
    return sum;
}

template <typename T>
T AdvancedCalculator::max_element(const std::vector<T> &arr)
{
    if (arr.empty())
    {
        throw CalculatorException("Array is empty!");
    }
    return *std::max_element(arr.begin(), arr.end());
}

template <typename T>
T AdvancedCalculator::min_element(const std::vector<T> &arr)
{
    if (arr.empty())
    {
        throw CalculatorException("Array is empty!");
    }
    return *std::min_element(arr.begin(), arr.end());
}

std::vector<double> AdvancedCalculator::batch_add(const std::vector<double> &values, double addend)
{
    std::vector<double> results;
    results.reserve(values.size());

    for (double val : values)
    {
        results.push_back(val + addend);
    }

    return results;
}

// 显式实例化模板方法（为了链接时可见）
template double AdvancedCalculator::sum_array(const std::vector<double> &);
template double AdvancedCalculator::max_element(const std::vector<double> &);
template double AdvancedCalculator::min_element(const std::vector<double> &);

template int AdvancedCalculator::sum_array(const std::vector<int> &);
template int AdvancedCalculator::max_element(const std::vector<int> &);
template int AdvancedCalculator::min_element(const std::vector<int> &);