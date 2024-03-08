#include "general.h"
#include "main.h"
#include "text.h"
#include <stdio.h>

/**
 * start_prompt - Handle the interactive prompt
 *
 * @info: Struct of information about the shell
 **/
void start_prompt(general_t *info)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    do {
        // Display prompt
        print("($) ");
        
        // Read a line from the user
        read = getline(&line, &len, stdin);

        if (read == -1) {
            perror("getline");
            break;
        }

        // Process the input line
        process_input_line(line, info);

    } while (read != -1);

    // Free allocated memory
    free_memory_p(line);
}

/**
 * process_input_line - Process the input line
 *
 * @line: Input line from the user
 * @info: Struct of information about the shell
 **/
void process_input_line(char *line, general_t *info)
{
    print("Received input: ");
    print(line);
}
