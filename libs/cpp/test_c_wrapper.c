#include "c_wrapper.h"
#include <stdio.h>
#include <stdlib.h>

void test_basic_calculator() {
    printf("=== Testing Basic Calculator C Wrapper ===\n");

    // 创建计算器
    CalculatorHandle* calc = calculator_create();
    if (!calc) {
        printf("Failed to create calculator\n");
        return;
    }

    double result;
    CalculatorError err;

    // 测试基本运算
    err = calculator_add(calc, 10.5, 5.2, &result);
    if (err == CALC_SUCCESS) {
        printf("10.5 + 5.2 = %.2f\n", result);
    } else {
        printf("Error: %s\n", calculator_error_to_string(err));
    }

    err = calculator_subtract(calc, 20.0, 7.5, &result);
    if (err == CALC_SUCCESS) {
        printf("20.0 - 7.5 = %.2f\n", result);
    }

    err = calculator_multiply(calc, 6.0, 8.0, &result);
    if (err == CALC_SUCCESS) {
        printf("6.0 * 8.0 = %.2f\n", result);
    }

    err = calculator_divide(calc, 100.0, 4.0, &result);
    if (err == CALC_SUCCESS) {
        printf("100.0 / 4.0 = %.2f\n", result);
    }

    // 测试除零错误
    err = calculator_divide(calc, 10.0, 0.0, &result);
    if (err != CALC_SUCCESS) {
        printf("Division by zero error: %s\n", calculator_error_to_string(err));
    }

    // 获取最后结果
    printf("Last result: %.2f\n", calculator_get_last_result(calc));

    // 测试历史记录
    size_t history_count = calculator_get_history_count(calc);
    printf("History count: %zu\n", history_count);

    for (size_t i = 0; i < history_count; ++i) {
        char buffer[256];
        err = calculator_get_history_entry(calc, i, buffer, sizeof(buffer));
        if (err == CALC_SUCCESS) {
            printf("  History[%zu]: %s\n", i, buffer);
        }
    }

    // 清理
    calculator_destroy(calc);
    printf("\n");
}

void test_advanced_calculator() {
    printf("=== Testing Advanced Calculator C Wrapper ===\n");

    // 创建高级计算器
    AdvancedCalculatorHandle* adv_calc = advanced_calculator_create();
    if (!adv_calc) {
        printf("Failed to create advanced calculator\n");
        return;
    }

    double result;
    CalculatorError err;

    // 测试高级运算
    err = advanced_calculator_power(adv_calc, 2.0, 10, &result);
    if (err == CALC_SUCCESS) {
        printf("2^10 = %.0f\n", result);
    }

    err = advanced_calculator_square_root(adv_calc, 144.0, &result);
    if (err == CALC_SUCCESS) {
        printf("sqrt(144) = %.0f\n", result);
    }

    err = advanced_calculator_factorial(adv_calc, 5, &result);
    if (err == CALC_SUCCESS) {
        printf("5! = %.0f\n", result);
    }

    err = advanced_calculator_sine(adv_calc, 30.0, &result);
    if (err == CALC_SUCCESS) {
        printf("sin(30°) = %.6f\n", result);
    }

    err = advanced_calculator_cosine(adv_calc, 60.0, &result);
    if (err == CALC_SUCCESS) {
        printf("cos(60°) = %.6f\n", result);
    }

    // 测试数组操作
    int32_t int_arr[] = {10, 20, 5, 30, 15};
    size_t int_arr_size = sizeof(int_arr) / sizeof(int_arr[0]);

    int64_t int_sum;
    err = advanced_calculator_sum_array_int32(adv_calc, int_arr, int_arr_size, &int_sum);
    if (err == CALC_SUCCESS) {
        printf("Int array sum: %lld\n", int_sum);
    }

    int32_t int_max;
    err = advanced_calculator_max_element_int32(adv_calc, int_arr, int_arr_size, &int_max);
    if (err == CALC_SUCCESS) {
        printf("Int array max: %d\n", int_max);
    }

    // 测试double数组
    double double_arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t double_arr_size = sizeof(double_arr) / sizeof(double_arr[0]);

    err = advanced_calculator_sum_array_double(adv_calc, double_arr, double_arr_size, &result);
    if (err == CALC_SUCCESS) {
        printf("Double array sum: %.2f\n", result);
    }

    err = advanced_calculator_max_element_double(adv_calc, double_arr, double_arr_size, &result);
    if (err == CALC_SUCCESS) {
        printf("Double array max: %.2f\n", result);
    }

    // 测试批量操作
    double values[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double results[5];
    err = advanced_calculator_batch_add(adv_calc, values, 5, 10.0, results);
    if (err == CALC_SUCCESS) {
        printf("Batch add 10: ");
        for (int i = 0; i < 5; ++i) {
            printf("%.1f ", results[i]);
        }
        printf("\n");
    }

    // 测试错误情况
    err = advanced_calculator_square_root(adv_calc, -4.0, &result);
    if (err != CALC_SUCCESS) {
        printf("Square root of negative error: %s\n", calculator_error_to_string(err));
    }

    // 清理
    advanced_calculator_destroy(adv_calc);
    printf("\n");
}

int main() {
    printf("C++ Calculator C Wrapper Test\n");
    printf("=============================\n\n");

    test_basic_calculator();
    test_advanced_calculator();

    printf("All C wrapper tests completed successfully!\n");
    return 0;
}