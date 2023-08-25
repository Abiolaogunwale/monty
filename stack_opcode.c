#include "monty.h"

/**
 * free_stack - Frees the stack.
 *
 * @h: Pointer to head of the stack.
 *
 * Return: Nothing.
 */

void free_stack(stack_t *h)
{
	/* Pointer to the current element being freed*/
	stack_t *curr_element = NULL;

	if (!h)
		return;

	curr_element = h;

	while (h->next)
	{
		/* Move to the next element in the stack*/
		h = h->next;
		/* Free the current element*/
		free(curr_element);
		/* Update the current element to the next*/
		curr_element = h;
	}
	/* Free the last element of the stack*/
	free(h);
}
