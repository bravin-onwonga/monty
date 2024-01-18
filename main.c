#include "monty.h"

#define MAX_LINE_LENGTH 256

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
	char opcode[MAX_LINE_LENGTH];
	int fileline = 0;
	stack_t **stack = NULL;
	stack_t *top = NULL;

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

	while (fgets(opcode, MAX_LINE_LENGTH, file) != NULL)
	{
		fileline = fileline + 1;
		process_opcode(opcode, fileline);
	}

	fclose(file);

	return (0);
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
	int i = 0;
	void (*func_ptr)(stack_t **, unsigned int);

	new_str = remove_spaces(str);

	opcode_arr = split_string(new_str);

	i = 0;
	while (opcode_arr[i])
	{
		if (strcmp(opcode_arr[i], "push") == 0)
		{
			*stack = _push(opcode_arr, fileline);
			break;
		}

		else
		{
			func_ptr = get_func(opcode_arr[i]);

			if (!(func_ptr))
			{
				fprintf(stderr, "L%d: unknown instruction <opcode>\n", fileline);
				exit(EXIT_FAILURE);
			}
			func_ptr(stack, fileline);
			break;
		}
		break;
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

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
			len++;
		if (str[i] == ' ' && str[i + 1] != ' ')
			len++;
	}

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

	return (s);
}
