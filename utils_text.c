#include "text.h"

/**
 * _strlen - Return the length of a string
 *
 * @msg: String to calculate length
 *
 * Return: Length of the string
 **/
int _strlen(char *msg)
{
    int i;
    for (i = 0; msg[i] != '\0'; i++)
        ;
    return i;
}

/**
 * _strcat - Concatenates two strings
 *
 * @dest: String concatenate
 * @src: Source string
 *
 * Return: A string concatenate
 */
char *_strcat(char *dest, char *src)
{
    int l_dest = _strlen(dest);
    int i;
    for (i = 0; src[i] != '\0'; i++)
        dest[l_dest + i] = src[i];
    dest[l_dest + i] = '\0';
    return dest;
}

/**
 * _strcpy - Copy a string to another
 *
 * @dest: Destination copy
 * @src: Source for copy
 *
 * Return: Return the value of dest
 */
char *_strcpy(char *dest, char *src)
{
    int i;
    for (i = 0; (dest[i] = src[i]) != '\0'; i++)
        ;
    return dest;
}

/**
 * _strdup - Pointer to a newly allocated space in memory
 *
 * @str: String to copy
 *
 * Return: String copied
 **/
char *_strdup(char *str)
{
    if (str == NULL)
        return NULL;
    int size = _strlen(str) + 1;
    char *dest = malloc(size);
    if (dest != NULL)
        _strcpy(dest, str);
    return dest;
}

/**
 * _strcmp - Compare two strings
 *
 * @s1: String 1
 * @s2: String 2
 *
 * Return: Integer
 */
int _strcmp(char *s1, char *s2)
{
    for (; *s1 && (*s1 == *s2); s1++, s2++)
        ;
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}
