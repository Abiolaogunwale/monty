#include "monty.h"

/**
 * my_push - Adds a new node at the beginning of the stack.
 *
 * @h: Pointer to the head of the stack.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothing.
 */

void my_push(stack_t **h, unsigned int errLine)
{
	stack_t *current_element = NULL;

	/* Check if the push argument is valid and a valid integer*/
	if (!global_vars.push_arg || !strchk_opcode(global_vars.push_arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", errLine);
		/* Set error flag*/
		global_vars.exec_failed = 1;
		return;
	}
	/* Allocate memory for the new node*/
	current_element = malloc(sizeof(stack_t));
	/* Check if malloc was successful*/
	malloc_stack_check(current_element);

	/* Convert the argument to an integer*/
	current_element->n = atoi(global_vars.push_arg);
	current_element->next = NULL;
	current_element->prev = NULL;

	/* If the stack is empty, set the new node as the head*/
	if (!*h)
		*h = current_element;
	else
	{
		/* If the stack is not empty, update the links to insert at the beginning*/
		current_element->next = *h;
		(*h)->prev = current_element;
		*h = current_element;
	}
}
