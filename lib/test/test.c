
#include "../lib.h"

#define SIZE 5

static int flag = 0;

#define CHECK_ARR_EQ(FIRST, SECOND, ARR_SIZE) \
    flag = 0;                                 \
    for (int i = 0; i < ARR_SIZE; i++) {      \
        if (FIRST[i] != SECOND[i]) {          \
            printf("NOT OK\n");               \
            flag = 1;                         \
            break;                            \
        }                                     \
    }                                         \
    if (!flag)                                \
    printf("OK\n")

#define CHECK_NUM_EQ(FIRST, SECOND) \
    if (FIRST == SECOND)            \
        printf("OK\n");             \
    else                            \
        printf("NOT OK\n");

int main() {
    printf("TEST1\n\t");
    char arr1[10] = {0};
    memcpy(arr1, "test", 5);
    CHECK_ARR_EQ(arr1, "test", 5);

    printf("TEST2\n\t");
    char arr2[10] = {0};
    memcpy(arr1, "abc", 4);
    CHECK_ARR_EQ(arr1, "abc", 4);

    printf("TEST3\n\t");
    int arr3[10] = {0};
    int arr4[] = {1, 2, 3, 4};
    memcpy(arr3, arr4, 4 * sizeof(arr4));
    CHECK_ARR_EQ(arr3, arr4, 4);

    printf("TEST4\n\t");
    float arr5[10] = {0};
    float arr6[] = {1, 2, 3.13, 4, 55, 1};
    memcpy(arr5, arr6, 6 * sizeof(arr6));
    CHECK_ARR_EQ(arr5, arr6, 6);

    printf("TEST5\n\t");
    char arr7[10];
    char arr8[] = "123456";
    memcpy(arr7, arr8, 6 * sizeof(arr8));
    CHECK_ARR_EQ(arr7, arr8, 6);

    printf("TEST6\n\t");
    char arr9[40] = "almost every programmer...";
    char arr10[40] = "------ every programmer...";
    memset(arr9, '-', 6);
    CHECK_ARR_EQ(arr9, arr10, 15);

    printf("TEST7\n\t");
    char arr11[40] = "almost every programmer...";
    char arr12[40] = "-------every programmer...";
    memset(arr11, '-', 7);
    CHECK_ARR_EQ(arr11, arr12, 15);

    printf("TEST8\n\t");
    char arr13[40] = "almost every programmer...";
    char arr14[40] = "!lmost every programmer...";
    memset(arr13, '!', 1);
    CHECK_ARR_EQ(arr13, arr14, 15);

    printf("TEST9\n\t");
    int result1 = memcmp("ala ma kota", "ala ma kota", 1);
    CHECK_NUM_EQ(result1, 0);

    printf("TEST10\n\t");
    int result2 = memcmp("ala ma kota", "ala ma kota", 10);
    CHECK_NUM_EQ(result1, 0);
}