#include "monty.h"

/*char *push_arg = NULL;*/
/*char *opcode = NULL;*/
/*int execution_failed = 0;*/
void nothing(void);
vars global_vars = {0, NULL, NULL};

/**
 * main - program starting point.
 *
 * @argc: argument's count.
 * @argv: argument's values.
 *
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	FILE *file = NULL;
	char buffer[BUFFER_SIZE] = {0};
	unsigned int errLine = 1;
	stack_t *h = NULL;
	void (*exec_instruction)(stack_t **, unsigned int) = NULL;

	/* Check if the argument count is correct.*/
	args_count(argc);
	/* Open the file specified by the second command-line argument.*/
	open_file(argv[1], &file);

	while (fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		/* Remove comments and NOPs from the buffer.*/
		nop_comment(buffer);
		/* Parse the opcode from the buffer.*/
		global_vars.opcode = parse_opcode(buffer);
		/*If opcode is NULL, continue to the next line.*/
		if (!global_vars.opcode)
		{
			errLine++;
			continue;
		}
		/* Check if the opcode is valid.*/
		check_valid_opcode(global_vars.opcode, errLine);
		/* f an error occurred, exit with failure.*/
		if (global_vars.exec_failed)
			close_exit_file_failure(h, file);

		/* Get the function pointer corresponding to the opcode.*/
		exec_instruction = get_opcode_func(global_vars.opcode);
		/* Execute the instruction.*/
		exec_instruction(&h, errLine);
		/* If an error occurred during execution, exit with failure.*/
		if (global_vars.exec_failed)
			close_exit_file_failure(h, file);
		errLine++;
		free(global_vars.opcode);
		global_vars.opcode = NULL;
		if (global_vars.push_arg != NULL)
			free(global_vars.push_arg);
		global_vars.push_arg = NULL;
	}
	/* Free the stack and close the file.*/
	free_stack(h);
	fclose(file);

	return (0);
}
