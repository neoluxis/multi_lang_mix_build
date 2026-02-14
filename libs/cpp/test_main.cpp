#include <iostream>
#include <vector>
#include <iomanip>
#include "Calculator.h"

void testBasicCalculator()
{
    std::cout << "=== Testing Basic Calculator ===" << std::endl;

    Calculator calc;

    try
    {
        std::cout << "Addition: " << calc.add(10.5, 5.2) << std::endl;
        std::cout << "Subtraction: " << calc.subtract(20.0, 7.5) << std::endl;
        std::cout << "Multiplication: " << calc.multiply(6.0, 8.0) << std::endl;
        std::cout << "Division: " << calc.divide(100.0, 4.0) << std::endl;

        // 测试异常
        try
        {
            calc.divide(10.0, 0.0);
        }
        catch (const CalculatorException &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        std::cout << "Last result: " << calc.getLastResult() << std::endl;
        std::cout << "Calculator type: " << calc.getCalculatorType() << std::endl;

        std::cout << "\nCalculation history:" << std::endl;
        for (const auto &entry : calc.getHistory())
        {
            std::cout << "  " << entry << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void testAdvancedCalculator()
{
    std::cout << "=== Testing Advanced Calculator ===" << std::endl;

    AdvancedCalculator adv_calc;

    try
    {
        std::cout << std::fixed << std::setprecision(6);

        std::cout << "Power: " << adv_calc.power(2.0, 10) << std::endl;
        std::cout << "Square root: " << adv_calc.square_root(144.0) << std::endl;
        std::cout << "Factorial: " << adv_calc.factorial(5) << std::endl;
        std::cout << "Sine(30°): " << adv_calc.sine(30.0) << std::endl;
        std::cout << "Cosine(60°): " << adv_calc.cosine(60.0) << std::endl;

        // 测试模板方法
        std::vector<double> double_arr = {1.1, 2.2, 3.3, 4.4, 5.5};
        std::cout << "Double array sum: " << adv_calc.sum_array(double_arr) << std::endl;
        std::cout << "Double array max: " << adv_calc.max_element(double_arr) << std::endl;
        std::cout << "Double array min: " << adv_calc.min_element(double_arr) << std::endl;

        std::vector<int> int_arr = {10, 20, 5, 30, 15};
        std::cout << "Int array sum: " << adv_calc.sum_array(int_arr) << std::endl;
        std::cout << "Int array max: " << adv_calc.max_element(int_arr) << std::endl;
        std::cout << "Int array min: " << adv_calc.min_element(int_arr) << std::endl;

        // 测试批量运算
        std::vector<double> values = {1.0, 2.0, 3.0, 4.0, 5.0};
        auto results = adv_calc.batch_add(values, 10.0);
        std::cout << "Batch add 10: ";
        for (double val : results)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        // 测试异常
        try
        {
            adv_calc.square_root(-4.0);
        }
        catch (const CalculatorException &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        try
        {
            std::vector<double> empty_arr;
            adv_calc.max_element(empty_arr);
        }
        catch (const CalculatorException &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        std::cout << "Calculator type: " << adv_calc.getCalculatorType() << std::endl;

        std::cout << "\nCalculation history:" << std::endl;
        for (const auto &entry : adv_calc.getHistory())
        {
            std::cout << "  " << entry << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void testPolymorphism()
{
    std::cout << "=== Testing Polymorphism ===" << std::endl;

    // 使用基类指针指向派生类对象
    Calculator *calc1 = new Calculator();
    Calculator *calc2 = new AdvancedCalculator();

    std::cout << "Base calculator type: " << calc1->getCalculatorType() << std::endl;
    std::cout << "Derived calculator type: " << calc2->getCalculatorType() << std::endl;

    // 基本运算
    calc1->add(5.0, 3.0);
    calc2->add(5.0, 3.0);

    // 清理内存
    delete calc1;
    delete calc2;

    std::cout << std::endl;
}

int main()
{
    std::cout << "C++ Calculator Library Test" << std::endl;
    std::cout << "===========================" << std::endl
              << std::endl;

    testBasicCalculator();
    testAdvancedCalculator();
    testPolymorphism();

    std::cout << "All C++ calculator tests completed successfully!" << std::endl;
    return 0;
}