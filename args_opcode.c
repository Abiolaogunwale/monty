#include "monty.h"

/**
 * args_count - Validate argument count.
 *
 * @argc: Pointer to argument count.
 *
 * Return: Nothing.
 */

void args_count(int argc)
{
	/* Check if the number of command-line arguments is not 2.*/
	if (argc != 2)
	{
		/* Print an error message to stderr.*/
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
