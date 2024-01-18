#include "monty.h"

#define MAX_LINE_LENGTH 256

void process_opcode(char *str);
char *remove_spaces(char *str);

int main(int argc, char **argv)
{
	FILE *file;
	char *filename = argv[1];
	char opcode[MAX_LINE_LENGTH];

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
		process_opcode(opcode);
	}

	fclose(file);

	return 0;
}

void process_opcode(char *str)
{
	char *new_str;
	char **opcode_arr;
	int i = 0;

	new_str = remove_spaces(str);
	printf("%s\n", new_str);

	opcode_arr = split_string(new_str);

	while (opcode_arr[i])
	{
		printf("%s\n", opcode_arr[i]);
		i++;
	}
	putchar('\n');
	printf("--------------------------\n");
	putchar('\n');
}

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
		if (str[i] != ' ')
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
