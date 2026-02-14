#include <stdio.h>
#include "c_math_ops/math_ops.h"

int main()
{
    // 测试基本运算
    printf("Add: %d + %d = %d\n", 5, 3, add_int(5, 3));
    printf("Multiply: %d * %d = %d\n", 4, 7, mul_int(4, 7));

    // 测试位运算
    printf("Bitwise AND: %u & %u = %u\n", 15, 10, bitwise_and(15, 10));
    printf("Left shift: %u << 2 = %u\n", 8, left_shift(8, 2));

    // 测试数组操作
    int32_t arr[] = {1, 5, 3, 9, 2};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    printf("Array sum: %lld\n", sum_array(arr, size));
    printf("Array max: %d\n", find_max(arr, size));
    printf("Array min: %d\n", find_min(arr, size));

    // 测试字符串操作
    const char *test_str = "Hello, World!";
    printf("String length: %zu\n", string_length(test_str));

    char dest[20];
    string_copy(dest, test_str, sizeof(dest));
    printf("String copy: %s\n", dest);

    printf("C library test completed successfully!\n");
    return 0;
}