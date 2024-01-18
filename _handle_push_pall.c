#include "monty.h"

stack_t *add_dnodeint(stack_t **head, const int n);
char *arr_to_str(char **arr);

/**
 * print_all - prints all the elements of a dlistint_t list.
 *
 * @h: head node
 * @line_number: line number of command in file
 * Return: the number of nodes
 */

void print_all(stack_t **h, unsigned int line_number)
{
	stack_t *curr;

	(void)(line_number);

	if (h)
	{
		curr = *h;

		while (curr != NULL)
		{
			fprintf(stdout, "%d\n", curr->n);
			curr = curr->next;
		}
	}
}

/**
 * _push - adds a new element on top of a stack
 *
 * @arr: arr of push command and integer to be added
 * @line_number: line number of command in file
 * Return: pointer to head node of updated stack
 */

stack_t *_push(char **arr, unsigned int line_number)
{
	int j, n;
	char *s, *err_str;

	if (arr[1])
	{
		s = arr[1];
		for (j = 0; s[j] != '\0'; j++)
		{
			if (s[j] < '0' || s[j] > '9')
			{
				err_str = arr_to_str(arr);
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, err_str);
				exit(EXIT_FAILURE);
			}
		}
		n = atoi(s);
	}

	*stack = add_dnodeint(stack, n);

	return (*stack);
}

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 *
 * @head: address head node
 * @n: integer element for the new node
 * Return: address of new node; otherwise NULL
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node, *temp;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = *head;
		*head = new_node;
		new_node->prev = NULL;
	}

	else
	{
		temp = *head;
		temp->prev = new_node;
		new_node->next = *head;
		*head = new_node;
		new_node->prev = NULL;
	}

	return (*head);
}

/**
 * arr_to_str - reverts array back to string
 *
 * @arr: array
 * Return: string
 */

char *arr_to_str(char **arr)
{
	char *s;
	int len = 0, i = 0, j = 0, k;

	while (arr[i])
	{
		len += strlen(arr[i]);
		i++;
	}
	len += i;

	s = malloc(sizeof(char) * len);

	if (s == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	i = 0;
	while (arr[i])
	{
		k = 0;
		while (arr[i][k])
		{
			s[j] = arr[i][k];
			j++;
			k++;
		}
		i++;
		if (arr[i])
		{
			s[j] = ' ';
			j++;
		}
	}
	return (s);
}
