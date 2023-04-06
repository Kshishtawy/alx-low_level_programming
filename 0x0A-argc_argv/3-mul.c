#include <stdio.h>
#include "main.h"

/**
 * _atoi - converts a string to an integer
 *
 * @str: string to be converted
 *
 * Return: the integer converted from the string
 */
int _atoi(char *str)
{
        int i = 0, num_digits = 0, negative = 0, digit, number = 0, found_digit = 0;

        while (str[num_digits] != '\0')
                num_digits++;

        while (i < num_digits && found_digit == 0)
        {
                if (str[i] == '-')
                        negative++;
                if (str[i] >= '0' && str[i] <= '9')
                {
                        digit = str[i] - '0';
                        if (negative % 2)
                                digit = -digit;
                        number = number * 10 + digit;
                        found_digit = 1;
                        if (str[i + 1] < '0' || str[i + 1] > '9')
                                break;
                        found_digit = 0;
                }
                i++;
        }

        if (found_digit == 0)
                return (0);

        return (number);
}

/**
 * main - multiplies two numbers
 *
 * @argc: number of arguments
 *
 * @argv: array of arguments
 *
 * Return: 0 (Success), 1 (Error)
 */
int main(int argc, char *argv[])
{
        int result, num1, num2;

        if (argc != 3)
        {
                printf("Error\n");
                return (1);
        }

        num1 = _atoi(argv[1]);
        num2 = _atoi(argv[2]);
        result = num1 * num2;

        printf("%d\n", result);

        return (0);
}
