/**
 * @brief Analyzes patterns in an array of strings and replaces values.
 *
 * @param info General information about the shell.
 * @param arguments Array of strings to analyze and modify.
 */
void analyze_patterns(general_t *info, char **arguments)
{
    int i;

    for (i = 0; arguments[i] != NULL; i++)
        arguments[i] = pattern_handler(info, arguments[i]);
}

/**
 * @brief Handles patterns by replacing values in a string.
 *
 * @param info General information about the shell.
 * @param string The input string.
 * @return The modified string.
 */
char *pattern_handler(general_t *info, char *string)
{
    int i;

    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '$' && string[i + 1] != '\0')
            string = replace_value(info, &i, string);
    }

    return string;
}

/**
 * @brief Replaces a pattern value in a string.
 *
 * @param info General information about the shell.
 * @param index Pointer to the current index in the string.
 * @param string The input string.
 * @return The modified string.
 */
char *replace_value(general_t *info, int *index, const char *string)
{
    int i;
    char *value;

    i = *index;
    i++;

    value = replacement(info, index, string + i);
    if (value == NULL)
    {
        // Handle the case where replacement fails
        return _strcpy("", "");
    }

    int old_s = _strlen(string);
    int new_s = _strlen(value) + 1;

    char *new_string = _realloc(string, old_s, new_s);
    new_string = _strcpy(new_string, value);

    free_memory_p(value);
    *index = i;

    return new_string;
}
