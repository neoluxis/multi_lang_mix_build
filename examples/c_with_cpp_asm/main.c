#include <stdio.h>
#include <stdlib.h>

// C库头文件
#include "math_ops.h"

// 汇编库头文件
#include "math_ops_asm.h"

// C++库C wrapper头文件
#include "c_wrapper.h"

int main() {
    printf("C Project Using C++, C, and Assembly Libraries\n");
    printf("===============================================\n\n");

    // ==========================================
    // 使用C库进行基本数学运算
    // ==========================================
    printf("1. Using C Library (Basic Math Operations)\n");
    printf("------------------------------------------\n");

    // 基本整数运算
    int32_t a = 15, b = 7;
    printf("C Library Results:\n");
    printf("  %d + %d = %d\n", a, b, add_int(a, b));
    printf("  %d - %d = %d\n", a, b, sub_int(a, b));
    printf("  %d * %d = %d\n", a, b, mul_int(a, b));
    printf("  %d / %d = %d\n", a, b, div_int(a, b));
    printf("  %d %% %d = %d\n", a, b, mod_int(a, b));

    // 位运算
    uint32_t x = 60, y = 13;  // 60 = 111100, 13 = 001101
    printf("  %u & %u = %u\n", x, y, bitwise_and(x, y));    // 12 = 001100
    printf("  %u | %u = %u\n", x, y, bitwise_or(x, y));     // 61 = 111101
    printf("  %u ^ %u = %u\n", x, y, bitwise_xor(x, y));    // 49 = 110001
    printf("  %u << 2 = %u\n", x, left_shift(x, 2));        // 240 = 11110000

    // 数组操作
    int32_t numbers[] = {12, 45, 23, 67, 34, 89, 56};
    size_t array_size = sizeof(numbers) / sizeof(numbers[0]);
    printf("  Array operations on [%d, %d, %d, %d, %d, %d, %d]:\n",
           numbers[0], numbers[1], numbers[2], numbers[3],
           numbers[4], numbers[5], numbers[6]);
    printf("    Sum = %lld\n", sum_array(numbers, array_size));
    printf("    Max = %d\n", find_max(numbers, array_size));
    printf("    Min = %d\n", find_min(numbers, array_size));

    // 字符串操作
    const char* test_string = "Hello, Mixed Language Programming!";
    char buffer[50];
    string_copy(buffer, test_string, sizeof(buffer));
    printf("  String copy: '%s'\n", buffer);
    printf("  String length: %zu\n", string_length(test_string));

    printf("\n");

    // ==========================================
    // 使用汇编库进行高效计算
    // ==========================================
    printf("2. Using Assembly Library (High-Performance Math)\n");
    printf("-------------------------------------------------\n");

    printf("Assembly Library Results:\n");

    // 基本算术（64位）
    int64_t num1 = 42, num2 = 18;
    printf("  %lld + %lld = %lld\n", num1, num2, asm_add(num1, num2));
    printf("  %lld - %lld = %lld\n", num1, num2, asm_subtract(num1, num2));
    printf("  %lld * %lld = %lld\n", num1, num2, asm_multiply(num1, num2));

    // 高级运算
    printf("  2^8 = %llu\n", asm_power(2, 8));
    printf("  6! = %llu\n", asm_factorial(6));

    // 位运算
    uint64_t val1 = 0xFF00FF00, val2 = 0x00FF00FF;
    printf("  0x%llX & 0x%llX = 0x%llX\n", val1, val2, asm_bitwise_and(val1, val2));
    printf("  0x%llX | 0x%llX = 0x%llX\n", val1, val2, asm_bitwise_or(val1, val2));
    printf("  1 << 5 = %llu\n", asm_left_shift(1, 5));

    printf("\n");

    // ==========================================
    // 使用C++库（通过C wrapper）
    // ==========================================
    printf("3. Using C++ Library (via C Wrapper - OOP Features)\n");
    printf("---------------------------------------------------\n");

    // 创建基础计算器
    CalculatorHandle* basic_calc = calculator_create();
    if (!basic_calc) {
        printf("Failed to create basic calculator!\n");
        return 1;
    }

    printf("Basic Calculator Operations:\n");
    double result;
    CalculatorError err;

    // 基本运算
    err = calculator_add(basic_calc, 25.5, 14.7, &result);
    if (err == CALC_SUCCESS) {
        printf("  25.5 + 14.7 = %.2f\n", result);
    }

    err = calculator_multiply(basic_calc, 8.0, 9.0, &result);
    if (err == CALC_SUCCESS) {
        printf("  8.0 * 9.0 = %.2f\n", result);
    }

    // 显示历史记录
    size_t history_count = calculator_get_history_count(basic_calc);
    printf("  Calculation history (%zu entries):\n", history_count);
    for (size_t i = 0; i < history_count; ++i) {
        char history_buffer[100];
        err = calculator_get_history_entry(basic_calc, i, history_buffer, sizeof(history_buffer));
        if (err == CALC_SUCCESS) {
            printf("    %s\n", history_buffer);
        }
    }

    calculator_destroy(basic_calc);

    // 创建高级计算器
    AdvancedCalculatorHandle* adv_calc = advanced_calculator_create();
    if (!adv_calc) {
        printf("Failed to create advanced calculator!\n");
        return 1;
    }

    printf("\nAdvanced Calculator Operations:\n");

    // 科学运算
    err = advanced_calculator_power(adv_calc, 3.0, 4, &result);
    if (err == CALC_SUCCESS) {
        printf("  3^4 = %.0f\n", result);
    }

    err = advanced_calculator_square_root(adv_calc, 144.0, &result);
    if (err == CALC_SUCCESS) {
        printf("  √144 = %.0f\n", result);
    }

    err = advanced_calculator_factorial(adv_calc, 5, &result);
    if (err == CALC_SUCCESS) {
        printf("  5! = %.0f\n", result);
    }

    err = advanced_calculator_sine(adv_calc, 30.0, &result);
    if (err == CALC_SUCCESS) {
        printf("  sin(30°) = %.6f\n", result);
    }

    // 数组操作
    int32_t int_array[] = {15, 42, 8, 23, 91, 34};
    size_t int_array_size = sizeof(int_array) / sizeof(int_array[0]);

    int64_t array_sum;
    err = advanced_calculator_sum_array_int32(adv_calc, int_array, int_array_size, &array_sum);
    if (err == CALC_SUCCESS) {
        printf("  Integer array sum [%d, %d, %d, %d, %d, %d] = %lld\n",
               int_array[0], int_array[1], int_array[2], int_array[3],
               int_array[4], int_array[5], array_sum);
    }

    int32_t array_max;
    err = advanced_calculator_max_element_int32(adv_calc, int_array, int_array_size, &array_max);
    if (err == CALC_SUCCESS) {
        printf("  Integer array max = %d\n", array_max);
    }

    // 双精度数组操作
    double double_array[] = {3.14, 2.71, 1.41, 1.73};
    size_t double_array_size = sizeof(double_array) / sizeof(double_array[0]);

    err = advanced_calculator_sum_array_double(adv_calc, double_array, double_array_size, &result);
    if (err == CALC_SUCCESS) {
        printf("  Double array sum [%.2f, %.2f, %.2f, %.2f] = %.2f\n",
               double_array[0], double_array[1], double_array[2], double_array[3], result);
    }

    // 批量操作
    double batch_values[] = {10.0, 20.0, 30.0, 40.0};
    double batch_results[4];
    err = advanced_calculator_batch_add(adv_calc, batch_values, 4, 5.0, batch_results);
    if (err == CALC_SUCCESS) {
        printf("  Batch add 5.0: [%.1f, %.1f, %.1f, %.1f] -> [%.1f, %.1f, %.1f, %.1f]\n",
               batch_values[0], batch_values[1], batch_values[2], batch_values[3],
               batch_results[0], batch_results[1], batch_results[2], batch_results[3]);
    }

    // 错误处理演示
    err = advanced_calculator_divide(adv_calc, 10.0, 0.0, &result);
    if (err != CALC_SUCCESS) {
        printf("  Error handling: %s\n", calculator_error_to_string(err));
    }

    err = advanced_calculator_square_root(adv_calc, -16.0, &result);
    if (err != CALC_SUCCESS) {
        printf("  Error handling: %s\n", calculator_error_to_string(err));
    }

    advanced_calculator_destroy(adv_calc);

    printf("\n");

    // ==========================================
    // 综合演示：结合所有库的功能
    // ==========================================
    printf("4. Integrated Demo (Combining All Libraries)\n");
    printf("---------------------------------------------\n");

    // 使用C库生成数据
    int32_t data[10];
    for (int i = 0; i < 10; ++i) {
        data[i] = mul_int(i + 1, 2);  // 生成2, 4, 6, ..., 20
    }

    // 使用汇编库处理数据
    uint64_t data_sum = 0;
    for (int i = 0; i < 10; ++i) {
        data_sum = asm_add(data_sum, data[i]);
    }

    // 使用C++库进行最终计算
    AdvancedCalculatorHandle* final_calc = advanced_calculator_create();
    double final_result;
    advanced_calculator_square_root(final_calc, (double)data_sum, &final_result);

    printf("Integrated computation:\n");
    printf("  Generated data: [");
    for (int i = 0; i < 10; ++i) {
        printf("%d", data[i]);
        if (i < 9) printf(", ");
    }
    printf("]\n");
    printf("  Sum (via assembly): %llu\n", data_sum);
    printf("  Square root of sum (via C++): %.2f\n", final_result);

    advanced_calculator_destroy(final_calc);

    printf("\n");
    printf("Successfully demonstrated mixed-language programming!\n");
    printf("   - C Library: Basic math operations\n");
    printf("   - Assembly Library: High-performance calculations\n");
    printf("   - C++ Library: Object-oriented features via C wrapper\n");

    return 0;
}