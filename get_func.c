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
	    {"pall", print_all},
	    {"pint", print_top},
	};

	int i;
	int func_count = sizeof(_funcs) / sizeof(_funcs[0]);

	i = 0;
	while (i < func_count)
	{
		if (strcmp(_funcs[i].opcode, str) == 0)
			return (_funcs[i].f);
		i++;
	}
	return (NULL);
}
