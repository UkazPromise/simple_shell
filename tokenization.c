#include "text.h"

/**
 * split_words - Split a line into words
 *
 * @line: Line to split
 * @sep: Delimiters for splitting the words
 *
 * Return: Set of words
 **/
char **split_words(char *line, const char *sep)
{
	char **words = NULL, **tmp = NULL, *token = NULL;
	size_t new_size = 1, old_size = sizeof(char *);

	words = malloc(old_size);
	if (words == NULL)
		return (NULL);

	token = strtok(line, sep);
	while (token)
	{
		if (token[0] == '#')
			break;

		tmp = _realloc(words, old_size, (new_size + 1) * sizeof(char *));
		if (tmp == NULL)
		{
			free_memory_pp((void **)words);
			return (NULL);
		}

		words = tmp;
		++new_size;

		words[new_size - 2] = _strdup(token);
		if (words[new_size - 2] == NULL)
		{
			free_memory_pp((void **)words);
			return (NULL);
		}

		token = strtok(NULL, sep);
	}

	words[new_size - 1] = NULL;
	return (words);
}

/**
 * join_words - Join 3 words with a separator
 *
 * @word1: Word1 to join
 * @word2: Word2 to join
 * @word3: Word3 to join
 * @sep: Separator between the words
 *
 * Return: Line composed by 3 parts followed by a separator and
 * end by a new line
 **/
char *join_words(char *word1, char *word2, char *word3, const char *sep)
{
	char *aux = NULL;
	int size_str1 = 0, size_str2 = 0, size_str3 = 0, size_sep = 0;

	if (word1 != NULL)
		size_str1 = _strlen(word1);

	if (word2 != NULL)
		size_str2 = _strlen(word2);

	if (word3 != NULL)
		size_str3 = _strlen(word3);

	if (sep != NULL)
		size_sep = _strlen((char *)sep);

	aux = malloc(size_str1 + size_str2 + size_sep + size_str3 + size_sep + 2);
	if (aux == NULL)
		return (NULL);

	aux = _strcpy(aux, word1);
	aux = _strcat(aux, (char *)sep);
	aux = _strcat(aux, word2);
	aux = _strcat(aux, (char *)sep);
	aux = _strcat(aux, word3);
	aux = _strcat(aux, "\n");

	return (aux);
}
