#include "monty.h"

/**
 * handle_free - frees and array
 *
 * @arr: array to free
 */

void handle_free(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}
