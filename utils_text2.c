#include "text.h"

/**
 * digits - Count the number of digits in a number
 *
 * @n: Number
 *
 * Return: Digits
 **/
int digits(int n)
{
    int i;
    for (i = 0; n != 0; i++, n /= 10)
        ;
    return i;
}

/**
 * to_string - Convert @number to string
 *
 * @number: Number to convert
 *
 * Return: Number as string
 **/
char *to_string(int number)
{
    int n_digits = digits(number);
    char *_number = malloc(n_digits + 1);
    
    if (number == 0)
        _number[0] = '0';
    else
    {
        _number[n_digits] = '\0';
        for (int i = n_digits - 1; number != 0; number /= 10, i--)
            _number[i] = (number % 10) + '0';
    }

    return _number;
}

/**
 * is_numerical - Check if is a digit
 *
 * @n: Number
 *
 * Return: If is a number, return 1 else return 0
 */
int is_numerical(unsigned int n)
{
    return (n >= '0' && n <= '9');
}

/**
 * _atoi - Convert a string to a number
 *
 * @s: String to convert
 *
 * Return: Return the number
 */
int _atoi(char *s)
{
    int number = 0;
    int sign = 1;

    while (*s)
    {
        if (is_numerical(*s))
        {
            number = (*s - '0') + number * 10;

            if (*(s + 1) == ' ')
                break;
        }
        else if (*s == '-')
            sign *= -1;

        s++;
    }

    return number * sign;
}

/**
 * contains_letter - Search non-digits in a string
 *
 * @s: String for search
 *
 * Return: If a non-digit was found, return _TRUE
 * if not, return _FALSE
 **/
int contains_letter(char *s)
{
    while (*s)
    {
        if (!is_numerical(*s))
            return _TRUE;
        s++;
    }

    return _FALSE;
}
