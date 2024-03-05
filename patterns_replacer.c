/**
 * @brief Handles replacement of symbols in a string.
 *
 * @param info General information about the shell.
 * @param string The input string.
 * @return The modified string.
 */
char *replacement(general_t *info, char *string)
{
    char symbol = *string;

    // Unused parameter, remove if not needed
    (void)info;

    if (symbol != '?' && symbol != '$')
    {
        char *tmp = replace_env(info, string);
        return tmp;
    }

    return (symbol == '$') ? to_string(info->pid) : to_string(info->status_code);
}

/**
 * @brief Replaces an environment variable in a string.
 *
 * @param info General information about the shell.
 * @param environment The environment variable name.
 * @return The value of the environment variable or NULL if not found.
 */
char *replace_env(general_t *info, char *environment)
{
    // Check for NULL before returning
    char *env = _getenv(environment);
    return env;
}
