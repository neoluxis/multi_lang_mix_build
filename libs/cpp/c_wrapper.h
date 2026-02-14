#ifndef C_CALCULATOR_WRAPPER_H
#define C_CALCULATOR_WRAPPER_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HANDLE_DECL(name) \
    typedef struct name##Handle name##Handle;
#define HANDLE_DEF(name) \
    struct name##Handle { \
        name* calculator; \
    };
    
// 不透明指针类型，用于隐藏C++对象
HANDLE_DECL(Calculator)
HANDLE_DECL(AdvancedCalculator)

// 错误码定义
typedef enum {
    CALC_SUCCESS = 0,
    CALC_ERROR_DIVISION_BY_ZERO = 1,
    CALC_ERROR_INVALID_ARGUMENT = 2,
    CALC_ERROR_OUT_OF_MEMORY = 3,
    CALC_ERROR_SQUARE_ROOT_NEGATIVE = 4,
    CALC_ERROR_FACTORIAL_NEGATIVE = 5,
    CALC_ERROR_ARRAY_EMPTY = 6
} CalculatorError;

// 基础计算器函数
CalculatorHandle* calculator_create();
void calculator_destroy(CalculatorHandle* handle);

CalculatorError calculator_add(CalculatorHandle* handle, double a, double b, double* result);
CalculatorError calculator_subtract(CalculatorHandle* handle, double a, double b, double* result);
CalculatorError calculator_multiply(CalculatorHandle* handle, double a, double b, double* result);
CalculatorError calculator_divide(CalculatorHandle* handle, double a, double b, double* result);

double calculator_get_last_result(CalculatorHandle* handle);
size_t calculator_get_history_count(CalculatorHandle* handle);
CalculatorError calculator_get_history_entry(CalculatorHandle* handle, size_t index, char* buffer, size_t buffer_size);
void calculator_clear_history(CalculatorHandle* handle);

// 高级计算器函数
AdvancedCalculatorHandle* advanced_calculator_create();
void advanced_calculator_destroy(AdvancedCalculatorHandle* handle);

CalculatorError advanced_calculator_add(AdvancedCalculatorHandle* handle, double a, double b, double* result);
CalculatorError advanced_calculator_subtract(AdvancedCalculatorHandle* handle, double a, double b, double* result);
CalculatorError advanced_calculator_multiply(AdvancedCalculatorHandle* handle, double a, double b, double* result);
CalculatorError advanced_calculator_divide(AdvancedCalculatorHandle* handle, double a, double b, double* result);

// 高级数学函数
CalculatorError advanced_calculator_power(AdvancedCalculatorHandle* handle, double base, int exponent, double* result);
CalculatorError advanced_calculator_square_root(AdvancedCalculatorHandle* handle, double value, double* result);
CalculatorError advanced_calculator_factorial(AdvancedCalculatorHandle* handle, int n, double* result);
CalculatorError advanced_calculator_sine(AdvancedCalculatorHandle* handle, double angle, double* result);
CalculatorError advanced_calculator_cosine(AdvancedCalculatorHandle* handle, double angle, double* result);

// 数组操作函数 (int32_t)
CalculatorError advanced_calculator_sum_array_int32(AdvancedCalculatorHandle* handle, const int32_t* arr, size_t size, int64_t* result);
CalculatorError advanced_calculator_max_element_int32(AdvancedCalculatorHandle* handle, const int32_t* arr, size_t size, int32_t* result);
CalculatorError advanced_calculator_min_element_int32(AdvancedCalculatorHandle* handle, const int32_t* arr, size_t size, int32_t* result);

// 数组操作函数 (double)
CalculatorError advanced_calculator_sum_array_double(AdvancedCalculatorHandle* handle, const double* arr, size_t size, double* result);
CalculatorError advanced_calculator_max_element_double(AdvancedCalculatorHandle* handle, const double* arr, size_t size, double* result);
CalculatorError advanced_calculator_min_element_double(AdvancedCalculatorHandle* handle, const double* arr, size_t size, double* result);

// 批量操作
CalculatorError advanced_calculator_batch_add(AdvancedCalculatorHandle* handle,
                                             const double* values, size_t count,
                                             double addend, double* results);

double advanced_calculator_get_last_result(AdvancedCalculatorHandle* handle);
size_t advanced_calculator_get_history_count(AdvancedCalculatorHandle* handle);
CalculatorError advanced_calculator_get_history_entry(AdvancedCalculatorHandle* handle, size_t index, char* buffer, size_t buffer_size);
void advanced_calculator_clear_history(AdvancedCalculatorHandle* handle);

// 工具函数
const char* calculator_error_to_string(CalculatorError error);

#ifdef __cplusplus
}
#endif

#endif // C_CALCULATOR_WRAPPER_H