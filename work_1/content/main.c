#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define NUM_COUNT 5

int main() {
    srand(time(NULL));
    FILE* input_file = fopen("input.txt", "w");
    if (!input_file) return perror("无法打开input.txt"), 1;

    uint32_t num;
    float sum = 0;
    printf("生成的随机数: ");

    for (int i = 0; i < NUM_COUNT; i++) {
        num = (uint32_t)rand() << 16 | rand();
        fprintf(input_file, i ? " %u" : "%u", num);
        printf(i ? " %u" : "%u", num);
        sum += num;
    }
    fputc('\n', input_file);
    fclose(input_file);
    putchar('\n');

    float mean = sum / NUM_COUNT;
    FILE* output_file = fopen("output.txt", "w");
    if (!output_file) return perror("无法打开output.txt"), 1;

    fprintf(output_file, "%.6f\n", mean);
    fclose(output_file);
    printf("计算得到的均值: %.6f\n", mean);

    return 0;
}