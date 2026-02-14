#include "cpp_calculator/c_wrapper.h"
#include "cpp_calculator/Calculator.h"
#include <cstring>
#include <new>

// 结构体定义（隐藏C++对象）
HANDLE_DEF(Calculator)
HANDLE_DEF(AdvancedCalculator)

// 错误处理辅助函数
static CalculatorError cpp_exception_to_c_error(const CalculatorException& e) {
    std::string msg = e.what();
    if (msg.find("Division by zero") != std::string::npos) {
        return CALC_ERROR_DIVISION_BY_ZERO;
    } else if (msg.find("negative number") != std::string::npos) {
        return CALC_ERROR_SQUARE_ROOT_NEGATIVE;
    } else if (msg.find("undefined") != std::string::npos) {
        return CALC_ERROR_FACTORIAL_NEGATIVE;
    } else if (msg.find("empty") != std::string::npos) {
        return CALC_ERROR_ARRAY_EMPTY;
    } else {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

// 基础计算器函数实现
CalculatorHandle* calculator_create() {
    try {
        CalculatorHandle* handle = new CalculatorHandle();
        handle->calculator = new Calculator();
        return handle;
    } catch (const std::bad_alloc&) {
        return nullptr;
    }
}

void calculator_destroy(CalculatorHandle* handle) {
    if (handle) {
        delete handle->calculator;
        delete handle;
    }
}

CalculatorError calculator_add(CalculatorHandle* handle, double a, double b, double* result) {
    if (!handle || !result) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        *result = handle->calculator->add(a, b);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError calculator_subtract(CalculatorHandle* handle, double a, double b, double* result) {
    if (!handle || !result) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        *result = handle->calculator->subtract(a, b);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError calculator_multiply(CalculatorHandle* handle, double a, double b, double* result) {
    if (!handle || !result) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        *result = handle->calculator->multiply(a, b);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError calculator_divide(CalculatorHandle* handle, double a, double b, double* result) {
    if (!handle || !result) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        *result = handle->calculator->divide(a, b);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

double calculator_get_last_result(CalculatorHandle* handle) {
    return handle ? handle->calculator->getLastResult() : 0.0;
}

size_t calculator_get_history_count(CalculatorHandle* handle) {
    return handle ? handle->calculator->getHistory().size() : 0;
}

CalculatorError calculator_get_history_entry(CalculatorHandle* handle, size_t index, char* buffer, size_t buffer_size) {
    if (!handle || !buffer || buffer_size == 0) return CALC_ERROR_INVALID_ARGUMENT;

    const auto& history = handle->calculator->getHistory();
    if (index >= history.size()) return CALC_ERROR_INVALID_ARGUMENT;

    const std::string& entry = history[index];
    if (entry.size() >= buffer_size) return CALC_ERROR_INVALID_ARGUMENT;

    std::strncpy(buffer, entry.c_str(), buffer_size - 1);
    buffer[buffer_size - 1] = '\0';
    return CALC_SUCCESS;
}

void calculator_clear_history(CalculatorHandle* handle) {
    if (handle) {
        handle->calculator->clearHistory();
    }
}

// 高级计算器函数实现
AdvancedCalculatorHandle* advanced_calculator_create() {
    try {
        AdvancedCalculatorHandle* handle = new AdvancedCalculatorHandle();
        handle->calculator = new AdvancedCalculator();
        return handle;
    } catch (const std::bad_alloc&) {
        return nullptr;
    }
}

void advanced_calculator_destroy(AdvancedCalculatorHandle* handle) {
    if (handle) {
        delete handle->calculator;
        delete handle;
    }
}

CalculatorError advanced_calculator_add(AdvancedCalculatorHandle* handle, double a, double b, double* result) {
    if (!handle || !result) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        *result = handle->calculator->add(a, b);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError advanced_calculator_subtract(AdvancedCalculatorHandle* handle, double a, double b, double* result) {
    if (!handle || !result) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        *result = handle->calculator->subtract(a, b);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError advanced_calculator_multiply(AdvancedCalculatorHandle* handle, double a, double b, double* result) {
    if (!handle || !result) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        *result = handle->calculator->multiply(a, b);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError advanced_calculator_divide(AdvancedCalculatorHandle* handle, double a, double b, double* result) {
    if (!handle || !result) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        *result = handle->calculator->divide(a, b);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError advanced_calculator_power(AdvancedCalculatorHandle* handle, double base, int exponent, double* result) {
    if (!handle || !result) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        *result = handle->calculator->power(base, exponent);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError advanced_calculator_square_root(AdvancedCalculatorHandle* handle, double value, double* result) {
    if (!handle || !result) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        *result = handle->calculator->square_root(value);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError advanced_calculator_factorial(AdvancedCalculatorHandle* handle, int n, double* result) {
    if (!handle || !result) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        *result = handle->calculator->factorial(n);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError advanced_calculator_sine(AdvancedCalculatorHandle* handle, double angle, double* result) {
    if (!handle || !result) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        *result = handle->calculator->sine(angle);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError advanced_calculator_cosine(AdvancedCalculatorHandle* handle, double angle, double* result) {
    if (!handle || !result) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        *result = handle->calculator->cosine(angle);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

// 数组操作实现
CalculatorError advanced_calculator_sum_array_int32(AdvancedCalculatorHandle* handle, const int32_t* arr, size_t size, int64_t* result) {
    if (!handle || !arr || !result || size == 0) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        std::vector<int32_t> vec(arr, arr + size);
        *result = handle->calculator->sum_array(vec);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError advanced_calculator_max_element_int32(AdvancedCalculatorHandle* handle, const int32_t* arr, size_t size, int32_t* result) {
    if (!handle || !arr || !result || size == 0) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        std::vector<int32_t> vec(arr, arr + size);
        *result = handle->calculator->max_element(vec);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError advanced_calculator_min_element_int32(AdvancedCalculatorHandle* handle, const int32_t* arr, size_t size, int32_t* result) {
    if (!handle || !arr || !result || size == 0) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        std::vector<int32_t> vec(arr, arr + size);
        *result = handle->calculator->min_element(vec);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError advanced_calculator_sum_array_double(AdvancedCalculatorHandle* handle, const double* arr, size_t size, double* result) {
    if (!handle || !arr || !result || size == 0) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        std::vector<double> vec(arr, arr + size);
        *result = handle->calculator->sum_array(vec);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError advanced_calculator_max_element_double(AdvancedCalculatorHandle* handle, const double* arr, size_t size, double* result) {
    if (!handle || !arr || !result || size == 0) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        std::vector<double> vec(arr, arr + size);
        *result = handle->calculator->max_element(vec);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError advanced_calculator_min_element_double(AdvancedCalculatorHandle* handle, const double* arr, size_t size, double* result) {
    if (!handle || !arr || !result || size == 0) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        std::vector<double> vec(arr, arr + size);
        *result = handle->calculator->min_element(vec);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

CalculatorError advanced_calculator_batch_add(AdvancedCalculatorHandle* handle,
                                             const double* values, size_t count,
                                             double addend, double* results) {
    if (!handle || !values || !results || count == 0) return CALC_ERROR_INVALID_ARGUMENT;

    try {
        std::vector<double> input_vec(values, values + count);
        auto output_vec = handle->calculator->batch_add(input_vec, addend);
        std::copy(output_vec.begin(), output_vec.end(), results);
        return CALC_SUCCESS;
    } catch (const CalculatorException& e) {
        return cpp_exception_to_c_error(e);
    } catch (...) {
        return CALC_ERROR_INVALID_ARGUMENT;
    }
}

double advanced_calculator_get_last_result(AdvancedCalculatorHandle* handle) {
    return handle ? handle->calculator->getLastResult() : 0.0;
}

size_t advanced_calculator_get_history_count(AdvancedCalculatorHandle* handle) {
    return handle ? handle->calculator->getHistory().size() : 0;
}

CalculatorError advanced_calculator_get_history_entry(AdvancedCalculatorHandle* handle, size_t index, char* buffer, size_t buffer_size) {
    if (!handle || !buffer || buffer_size == 0) return CALC_ERROR_INVALID_ARGUMENT;

    const auto& history = handle->calculator->getHistory();
    if (index >= history.size()) return CALC_ERROR_INVALID_ARGUMENT;

    const std::string& entry = history[index];
    if (entry.size() >= buffer_size) return CALC_ERROR_INVALID_ARGUMENT;

    std::strncpy(buffer, entry.c_str(), buffer_size - 1);
    buffer[buffer_size - 1] = '\0';
    return CALC_SUCCESS;
}

void advanced_calculator_clear_history(AdvancedCalculatorHandle* handle) {
    if (handle) {
        handle->calculator->clearHistory();
    }
}

// 工具函数
const char* calculator_error_to_string(CalculatorError error) {
    switch (error) {
        case CALC_SUCCESS: return "Success";
        case CALC_ERROR_DIVISION_BY_ZERO: return "Division by zero";
        case CALC_ERROR_INVALID_ARGUMENT: return "Invalid argument";
        case CALC_ERROR_OUT_OF_MEMORY: return "Out of memory";
        case CALC_ERROR_SQUARE_ROOT_NEGATIVE: return "Cannot calculate square root of negative number";
        case CALC_ERROR_FACTORIAL_NEGATIVE: return "Factorial of negative number is undefined";
        case CALC_ERROR_ARRAY_EMPTY: return "Array is empty";
        default: return "Unknown error";
    }
}