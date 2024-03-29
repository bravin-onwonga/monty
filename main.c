#include "monty.h"

stack_t **stack = NULL;

void process_opcode(char *str, int fileline);
char *remove_spaces(char *str);

/**
 * main - entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 success; otherwise (EXIT_FAILURE)
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *filename = argv[1];
	char *opcode = NULL;
	size_t opcode_size = 0;
	int fileline = 0;
	stack_t *top = NULL;
	ssize_t read = 1;

	stack = &top;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&opcode, &opcode_size, file)) != -1)
	{
		fileline = fileline + 1;
		if (strlen(opcode) != 1)
			process_opcode(opcode, fileline);
	}

	fclose(file);

	exit(EXIT_SUCCESS);
}

/**
 * process_opcode - processes the opcode string
 *
 * @str: opcode string
 * @fileline: current fileline
 */

void process_opcode(char *str, int fileline)
{
	char *new_str;
	char **opcode_arr;
	void (*func_ptr)(stack_t **, unsigned int);

	new_str = remove_spaces(str);

	if (new_str[0] == '\0')
		return;

	opcode_arr = split_string(new_str);

	if (strcmp(opcode_arr[0], "push") == 0)
	{
		*stack = _push(opcode_arr, fileline);
	}

	else
	{
		if (opcode_arr)
		{
			func_ptr = get_func(opcode_arr[0]);

			if (!(func_ptr))
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", fileline, new_str);
				exit(EXIT_FAILURE);
			}
			func_ptr(stack, fileline);
		}
	}
}

/**
 * remove_spaces - handle the case where spaces are in string
 *
 * @str: opcode string
 * Return: opcode with no spaces
 */

char *remove_spaces(char *str)
{
	int len = 0, i, j = 0;
	char *s;

	for (i = 0; str[i] != '\n'; i++)
	{
		if (str[i] != ' ')
			len++;
		if ((str[i] == ' ') && (str[i + 1] != ' ' && str[i + 1] != '\n'))
			len++;
	}

	if (len == 0)
	{
		s = malloc(1);
		s[0] = '\n';
	}

	else
	{

		s = malloc(sizeof(char) * len);

		if (s == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] != ' ' && str[i] != '\n')
			{
				s[j] = str[i];
				j++;
			}
			if (str[i] == ' ' && str[i + 1] != ' ')
			{
				s[j] = str[i];
				j++;
			}
		}
	}

	return (s);
}
