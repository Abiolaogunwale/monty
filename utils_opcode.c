#include "monty.h"

/**
 * my_pop - Deletes the top element of the stack.
 *
 * @h: Pointer to the head of the stack.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothing.
 */

void my_pop(stack_t **h, unsigned int errLine)
{
	stack_t *temp = NULL;

	/* Check if the stack or head pointer is NULL, indicating an empty stack.*/
	if (!h || !*h)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", errLine);
		global_vars.exec_failed = 1;
		return;
	}
	/* Handle the special case when there is only one element in the stack.*/
	if (!(*h)->next)
	{
		free(*h);
		*h = NULL;
	}
	else
	{
		temp = *h;
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(temp);
	}
}

/**
 * my_swap - Swaps the top two elements of the stack.
 *
 * @h: Pointer to the head of the stack.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothing.
 */

void my_swap(stack_t **h, unsigned int errLine)
{
	stack_t *temp = NULL;

	/* Check if the stack, head pointer, or if the stack is too short.*/
	if (!h || !*h || stack_len(*h) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", errLine);
		global_vars.exec_failed = 1;
		return;
	}
	/* Handle the case when there are only two elements in the stack.*/
	if (stack_len(*h) == 2)
	{
		temp = *h;
		*h = (*h)->next;
		(*h)->prev = NULL;
		(*h)->next = temp;
		temp->next = NULL;
		temp->prev = *h;

	}
	else
	{
		temp = *h;
		*h = (*h)->next;
		(*h)->prev = NULL;
		temp->next = (*h)->next;
		temp->prev = *h;
		(*h)->next = temp;
		temp->next->prev = temp;

	}
}

/**
 * my_nop - Do nothing.
 *
 * @h: Pointer to the head of the stack.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothing.
 */

void my_nop(stack_t **h, unsigned int errLine)
{
	(void)h;
	(void)errLine;
}

/**
 * nop_comment - Truncates everything after the #.
 *
 * @s: Pointer to the string to be truncated.
 *
 * Return: Nothing.
 */


void nop_comment(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (i != 0 && !isspace(s[i - 1]))
				return;
			s[i] = '\0';
		}
		i++;
	}
}

/**
 * stack_len - Returns the number of elements in the stack.
 *
 * @h: Pointer to the head of the stack.
 *
 * Return: number of elements in the list
 */

size_t stack_len(const stack_t *h)
{
	size_t length = 0;
	const stack_t *current_element = NULL;

	if (!h)
		return (length);
	current_element = h;
	while (current_element)
	{
		length++;
		current_element = current_element->next;
	}
	return (length);
}
