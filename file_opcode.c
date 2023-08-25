#include "monty.h"

/**
 * open_file - Opens monty files for reading.
 *
 * @filename: Pointer to file path.
 * @file: Pointer to file to be opened.
 *
 * Return: Nothing.
 */

void open_file(char *filename, FILE **file)
{
	/* Attempt to open the file for reading.*/
	*file = fopen(filename, "r");
	/* Check if the file could not be opened.*/
	if (!*file)
	{
		/* Print an error message to stderr.*/
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * close_exit_file - Close file and exit file.
 *
 * @file: pointer to file to be closed.
 *
 * Return: Nothing.
 */

void close_exit_file(FILE **file)
{
	/* Check if the end-of-file indicator is set.*/
	if (feof(*file))
	{
		/* Close the file.*/
		fclose(*file);
		exit(EXIT_SUCCESS);
	}
	if (ferror(*file))
	{
		fclose(*file);
		exit(EXIT_FAILURE);
	}
}

/**
 * close_exit_file_failure - Cleanup files on failure and exit.
 *
 * @h: Pointer to the head of the stack.
 * @file: Pointer to file to be cleaned and closed.
 *
 * Return: Nothing.
 */

void close_exit_file_failure(stack_t *h, FILE *file)
{
	/* Free memory for the opcode string (if not NULL).*/
	free(global_vars.opcode);
	/* Free memory for the push_arg string (if not NULL).*/
	if (global_vars.push_arg != NULL)
		free(global_vars.push_arg);
	/* Free the stack.*/
	free_stack(h);
	/* Close the file.*/
	fclose(file);
	exit(EXIT_FAILURE);
}
