#include "monty.h"

/**
 * my_pint - Prints the top element of a stack.
 *
 * @h: Pointer to the head of the stack.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothing.
 */

void my_pint(stack_t **h, unsigned int errLine)
{
	/* Check if the stack or head is NULL*/
	if (!h || !*h)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", errLine);
		/* Set error flag*/
		global_vars.exec_failed = 1;
		return;
	}
	/* Print the top element*/
	printf("%d\n", (*h)->n);
}

/**
 * my_pall - Prints all the elements of a stack.
 *
 * @h: Pointer to the head of the stack.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothing.
 */

void my_pall(stack_t **h, unsigned int errLine)
{
	const stack_t *current_element = NULL;
	(void)errLine;

	current_element = *h;

	/* Iterate through the stack and print each element*/
	while (current_element)
	{
		printf("%d\n", current_element->n);
		current_element = current_element->next;
	}
}

/**
 * my_pchar - Prints the top elements of the stack.
 *
 * @h: Pointer to the head of the stack.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothing.
 */

void my_pchar(stack_t **h, unsigned int errLine)
{
	/* Check if the stack or head is NULL*/
	if (!h || !*h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", errLine);
		/* Set error flag*/
		global_vars.exec_failed = 1;
		return;
	}
	/* Check if the top element is within the valid ASCII range*/
	if ((*h)->n < 0 || (*h)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", errLine);
		/* Set error flag.*/
		global_vars.exec_failed = 1;
		return;
	}
	/* Print the top element as a character*/
	printf("%c\n", (*h)->n);
}

/**
 * my_pstr - Prints the string starting at top of stack.
 *
 * @h: Pointer to the head of the stack.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothing.
 */

void my_pstr(stack_t **h, unsigned int errLine)
{
	const stack_t *current_element = NULL;
	(void)errLine;

	/* Check if the stack or head is NULL*/
	if (!h || !*h)
	{
		/* Print a newline for an empty stack*/
		printf("\n");
		return;
	}

	current_element = *h;

	/* Iterate through the stack and print characters within the valid range*/
	while (current_element && current_element->n > 0 && current_element->n <= 127)
	{
		printf("%c", current_element->n);
		current_element = current_element->next;
	}
	/* Print a newline at the end*/
	printf("\n");
}
