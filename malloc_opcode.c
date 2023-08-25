#include "monty.h"

/**
 * malloc_stack_check - Checks if the stack allocation failed.
 *
 * @ptr: Pointer to the allocated memory.
 *
 * Return: Nothings if the stack allocation failed.
 */

void malloc_stack_check(stack_t *ptr)
{
	/* heck if the memory allocation for the stack has failed (ptr is NULL).*/
	if (ptr == NULL)
	{
		/* Print an error message to stderr.*/
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * malloc_char_check - Checks if the char allocation failed.
 *
 * @ptr: Pointer to the allocated memory.
 *
 * Return: Nothings if the stack allocation failed.
 */

void malloc_char_check(char *ptr)
{
	/* Check if the malloc for the character array has failed (ptr is NULL).*/
	if (ptr == NULL)

	{
		/* Print an error message to stderr.*/
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
