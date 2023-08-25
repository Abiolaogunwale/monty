#include "monty.h"

/**
 * my_add - Adds the top two element of the stack.
 *
 * @h: Pointer to the head of the stack.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothing.
 */

void my_add(stack_t **h, unsigned int errLine)
{
	if (!h || !*h || stack_len(*h) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", errLine);
		global_vars.exec_failed = 1;
		return;
	}
	(*h)->next->n = (*h)->next->n + (*h)->n;

	/* Remove the top element from the stack.*/
	my_pop(h, errLine);
}

/**
 * my_sub - Subtract the top two elements of the stack.
 *
 * @h: Pointer to the head of the stack.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothing.
 */

void my_sub(stack_t **h, unsigned int errLine)
{
	if (!h || !*h || stack_len(*h) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", errLine);
		global_vars.exec_failed = 1;
		return;
	}
	(*h)->next->n = (*h)->next->n - (*h)->n;

	/* Remove the top element from the stack.*/
	my_pop(h, errLine);
}

/**
 * my_div - Divides the top two elements of the stack.
 *
 * @h: Pointer to the head of the stack.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothing.
 */

void my_div(stack_t **h, unsigned int errLine)
{
	if (!h || !*h || stack_len(*h) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", errLine);
		global_vars.exec_failed = 1;
		return;
	}
	if ((*h)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", errLine);
		global_vars.exec_failed = 1;
		return;
	}
	(*h)->next->n = (*h)->next->n / (*h)->n;

	/* Remove the top element from the stack.*/
	my_pop(h, errLine);
}

/**
 * my_mul - Multiplies the top two elements of the stack.
 *
 * @h: Pointer to the head of the stack.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothing..
 */

void my_mul(stack_t **h, unsigned int errLine)
{
	if (!h || !*h || stack_len(*h) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", errLine);
		global_vars.exec_failed = 1;
		return;
	}
	(*h)->next->n = (*h)->next->n * (*h)->n;

	/* Remove the top element from the stack.*/
	my_pop(h, errLine);
}

/**
 * my_mod - Modulus of the top two elements of the stack.
 *
 * @h: Pointer to the head of the stack.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothing.
 */

void my_mod(stack_t **h, unsigned int errLine)
{
	if (!h || !*h || stack_len(*h) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", errLine);
		global_vars.exec_failed = 1;
		return;
	}
	if ((*h)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", errLine);
		global_vars.exec_failed = 1;
		return;
	}
	(*h)->next->n = (*h)->next->n % (*h)->n;

	/* Remove the top element from the stack.*/
	my_pop(h, errLine);
}
