#include "monty.h"

/**
 * get_func - chooses function based on input
 *
 * @str: opcode instruction
 * Return: pointer to func; otherwise NULL
 */

void (*get_func(char *str))(stack_t **, unsigned int)
{
	instruction_t _funcs[] = {
	    {"pop", pop},
	    {"pall", print_all},
	    {"pint", print_top},
	    {"swap", swap},
	};

	int i = 0;
	int func_count = 4;

	while (i < func_count)
	{
		if (strcmp(_funcs[i].opcode, str) == 0)
			return (_funcs[i].f);
		i++;
	}
	return (NULL);
}
