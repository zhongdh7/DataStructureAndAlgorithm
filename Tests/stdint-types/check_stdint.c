/* 目的：验证 <stdint.h> 里那些“新类型”到底是什么，以及它们在本机上的实际宽度。
 * 编译：gcc -std=c11 -Wall -Wextra -g check_stdint.c -o check_stdint.exe
 */
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/* 用 _Generic 看某个 typedef 背后对应哪个内置整数类型 */
#define TYPE_NAME(x) _Generic((x),                    \
    signed char:        "signed char",                \
    unsigned char:      "unsigned char",              \
    short:              "short",                      \
    unsigned short:     "unsigned short",             \
    int:                "int",                        \
    unsigned int:       "unsigned int",               \
    long:               "long",                       \
    unsigned long:      "unsigned long",              \
    long long:          "long long",                  \
    unsigned long long: "unsigned long long",         \
    default:            "其他")

int main(void)
{
    puts("== 精确宽度类型（exact-width）==");
    printf("int8_t    -> %-20s size=%zu\n", TYPE_NAME((int8_t)0), sizeof(int8_t));
    printf("int16_t   -> %-20s size=%zu\n", TYPE_NAME((int16_t)0), sizeof(int16_t));
    printf("int32_t   -> %-20s size=%zu\n", TYPE_NAME((int32_t)0), sizeof(int32_t));
    printf("int64_t   -> %-20s size=%zu\n", TYPE_NAME((int64_t)0), sizeof(int64_t));
    printf("uint8_t   -> %-20s size=%zu\n", TYPE_NAME((uint8_t)0), sizeof(uint8_t));
    printf("uint16_t  -> %-20s size=%zu\n", TYPE_NAME((uint16_t)0), sizeof(uint16_t));
    printf("uint32_t  -> %-20s size=%zu\n", TYPE_NAME((uint32_t)0), sizeof(uint32_t));
    printf("uint64_t  -> %-20s size=%zu\n", TYPE_NAME((uint64_t)0), sizeof(uint64_t));

    puts("\n== 最小宽度 / 最快宽度类型 ==");
    printf("int_least8_t  size=%zu   int_fast8_t  size=%zu\n", sizeof(int_least8_t), sizeof(int_fast8_t));
    printf("int_least16_t size=%zu   int_fast16_t size=%zu\n", sizeof(int_least16_t), sizeof(int_fast16_t));
    printf("int_least32_t size=%zu   int_fast32_t size=%zu\n", sizeof(int_least32_t), sizeof(int_fast32_t));
    printf("int_least64_t size=%zu   int_fast64_t size=%zu\n", sizeof(int_least64_t), sizeof(int_fast64_t));

    puts("\n== 指针宽度 / 最大宽度类型 ==");
    printf("intptr_t  -> %-20s size=%zu\n", TYPE_NAME((intptr_t)0), sizeof(intptr_t));
    printf("uintptr_t -> %-20s size=%zu\n", TYPE_NAME((uintptr_t)0), sizeof(uintptr_t));
    printf("intmax_t  -> %-20s size=%zu\n", TYPE_NAME((intmax_t)0), sizeof(intmax_t));
    printf("uintmax_t -> %-20s size=%zu\n", TYPE_NAME((uintmax_t)0), sizeof(uintmax_t));

    puts("\n== 配套的极限值宏 ==");
    printf("INT8_MIN=%d  INT8_MAX=%d  UINT8_MAX=%u\n", (int)INT8_MIN, (int)INT8_MAX, (unsigned)UINT8_MAX);
    printf("INT16_MIN=%d  INT16_MAX=%d\n", (int)INT16_MIN, (int)INT16_MAX);
    printf("INT32_MIN=%" PRId32 "  INT32_MAX=%" PRId32 "\n", INT32_MIN, INT32_MAX);
    printf("INT64_MIN=%" PRId64 "  INT64_MAX=%" PRId64 "\n", INT64_MIN, INT64_MAX);
    printf("UINT64_MAX=%" PRIu64 "\n", UINT64_MAX);
    printf("INTPTR_MAX=%" PRIdPTR "  UINTPTR_MAX=%" PRIuPTR "\n", INTPTR_MAX, UINTPTR_MAX);
    printf("INTMAX_MAX=%" PRIdMAX "\n", INTMAX_MAX);

    return 0;
}
