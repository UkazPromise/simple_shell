#include "builtins.h"

/**
 * bin_env - Implementation of the env built-in
 *
 * @info: General information about the shell
 * @arguments: Command arguments
 **/
void bin_env(general_t *info, char **arguments)
{
    (void)info;
    (void)arguments;

    get_full_env();
}
