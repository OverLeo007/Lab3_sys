#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



char *input_string() {
    size_t size = 80;
    size_t curr = 0;
    char *buffer = malloc(size);
    while (fgets(buffer + curr, size - curr, stdin)) {
        if (strchr(buffer + curr, '\n')) {
            buffer[strcspn(buffer, "\n")] = '\0';
            return buffer;
        }

        curr = size - 1;
        size *= 2;
        char *tmp = realloc(buffer, size);
        free(buffer);
        buffer = tmp;
    }

    return buffer;
}


int input_int_check(const char value_array[]) {
    size_t len = strlen(value_array);
    if (len > 1 && value_array[0] == '-') return 1; // Проверка на отрицательное число
    for (size_t i = 0; i < len - 1; ++i) {
        if (value_array[i] < '0' || value_array[i] > '9') {
            return 1;
        }
    }
    return 0;
}

long input_long() {
    char str_array_len[23]; // Необходимый памятный объем, чтобы принять INT_MAX и \n
    if (fgets(str_array_len, sizeof(str_array_len), stdin) == NULL) {
        return LONG_MIN;  // Ошибка чтения
    }
    size_t len = strlen(str_array_len);

    if (len == 1 || str_array_len[len-1] != '\n' || input_int_check(str_array_len)) {
        return LONG_MIN; // Ошибка ввода
    }

    if (len == 2 && str_array_len[0] == '-') {
        return LONG_MIN; // Ошибка ввода
    }

    str_array_len[len-1] = '\0'; // Удаляем символ перевода строки
    long long_value = strtol(str_array_len, NULL, 10);
    if (long_value < LONG_MIN || long_value > LONG_MAX) {
        return LONG_MIN; // Значение выходит за пределы диапазона int
    }

    return long_value;
}