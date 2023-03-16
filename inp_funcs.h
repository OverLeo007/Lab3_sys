//
// Created by stud on 16.03.23.
//

#ifndef LAB3_INP_FUNCS_H
#define LAB3_INP_FUNCS_H

/**
 * @brief Функция ввода строки, не ограниченной по размеру
 * @return массив типа char, содержащий все символы строки
 */
char *input_string();


/**
 * @brief Проверяет, является ли строка value_array корректным представлением целого числа.
 * @param value_array строка, которую нужно проверить на соответствие целому числу.
 * @return 0, если строка является корректным представлением целого числа, 1 - в противном случае.
 */
int input_int_check(const char value_array[]);


/**
 * @brief Запрос на ввод целого числа.
 * @return Значение введенного целого числа, или LONG_MIN в случае ошибки чтения,
 * ввода или выхода за пределы диапазона int.
 */
long input_long();

#endif //LAB3_INP_FUNCS_H
