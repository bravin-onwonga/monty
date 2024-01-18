#include "monty.h"

int get_spaces_count(char *str);

/**
 * split_string - splits a string into an array
 *
 * @str: string to split
 * Return: array of strings
 */

char **split_string(char *str)
{
	int i, count = 0, j = 0;
	char **arr;
	char *token;
	const char *delim = " ";

	count = get_spaces_count(str);

	arr = malloc(sizeof(char *) * (count + 1));

	if (arr == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);

	i = 0;
	while (token != NULL)
	{
		arr[i] = malloc(strlen(token) + 1);
		if (arr[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(arr[j]);
			}
			free(arr);
			perror("Malloc fail");
			exit(EXIT_FAILURE);
		}
		strcpy(arr[i], token);

		token = strtok(NULL, delim);
		i++;
	}

	arr[count] = NULL;

	return (arr);
}

/**
 * get_spaces_count - gets numberof spaces in a string
 *
 * @str: string
 * Return: number of spaces(success)
 */

int get_spaces_count(char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			count++;
	}
	count++;

	return (count);
}
