#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <string>
#include <memory>

// 前向声明
class Operation;

// 基础计算器类
class Calculator
{
protected:
    std::vector<std::string> history_; // 计算历史
    double last_result_;               // 最后结果

public:
    Calculator();
    virtual ~Calculator() = default;

    // 基本运算方法
    virtual double add(double a, double b);
    virtual double subtract(double a, double b);
    virtual double multiply(double a, double b);
    virtual double divide(double a, double b);

    // 获取结果和历史
    double getLastResult() const { return last_result_; }
    const std::vector<std::string> &getHistory() const { return history_; }
    void clearHistory();

    // 虚函数，供子类重写
    virtual std::string getCalculatorType() const
    {
        return "Basic Calculator";
    }
};

// 高级计算器类，继承自基础计算器
class AdvancedCalculator : public Calculator
{
private:
    std::vector<std::unique_ptr<Operation>> operations_; // 多态操作集合

public:
    AdvancedCalculator();
    ~AdvancedCalculator() override = default;

    // 高级运算方法
    double power(double base, int exponent);
    double square_root(double value);
    double factorial(int n);
    double sine(double angle);   // 角度制
    double cosine(double angle); // 角度制

    // 模板方法：数组运算
    template <typename T>
    T sum_array(const std::vector<T> &arr);

    template <typename T>
    T max_element(const std::vector<T> &arr);

    template <typename T>
    T min_element(const std::vector<T> &arr);

    // 重写虚函数
    std::string getCalculatorType() const override
    {
        return "Advanced Calculator";
    }

    // 批量运算
    std::vector<double> batch_add(const std::vector<double> &values, double addend);
};

// 操作基类，用于多态
class Operation
{
public:
    virtual ~Operation() = default;
    virtual double execute(double a, double b = 0) = 0;
    virtual std::string getName() const = 0;
};

// 具体操作类
class AddOperation : public Operation
{
public:
    double execute(double a, double b = 0) override { return a + b; }
    std::string getName() const override { return "Addition"; }
};

class MultiplyOperation : public Operation
{
public:
    double execute(double a, double b = 0) override { return a * b; }
    std::string getName() const override { return "Multiplication"; }
};

// 异常类
class CalculatorException : public std::exception
{
private:
    std::string message_;

public:
    explicit CalculatorException(const std::string &message) : message_(message) {}
    const char *what() const noexcept override
    {
        return message_.c_str();
    }
};

#endif // CALCULATOR_H