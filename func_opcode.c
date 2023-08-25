#include "monty.h"

/**
 * get_opcode_func - Selects the correct function to execute opcode.
 *
 * @s: Pointer to opcode passed as argument to the program.
 *
 * Return: A pointer to the func that corresponds to the opcode given
 */

void (*get_opcode_func(char *s))(stack_t **, unsigned int)
{
	/* Array of instruction_t structures mapping opcodes to functions.*/
	instruction_t instructions[] = {
	    {"push", my_push},
	    {"pall", my_pall},
	    {"pint", my_pint},
	    {"pop", my_pop},
	    {"swap", my_swap},
	    {"add", my_add},
	    {"nop", my_nop},
	    {"sub", my_sub},
	    {"div", my_div},
	    {"mul", my_mul},
	    {"mod", my_mod},
	    {"pchar", my_pchar},
	    {"pstr", my_pstr},
	    {"rotl", my_rotl},
	    {"rotr", my_rotr},
	    {NULL, NULL}};
	int i;

	i = 0;

	while (instructions[i].opcode != NULL)
	{
		/* Compare the input opcode 's' with the opcode in the instruction_t array.*/
		if (strcmp(s, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}

/**
 * check_valid_opcode - Checks if the opcode is valid.
 *
 * @opcode: Pointer to the opcode.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothings if the opcode is not valid.
 */

void check_valid_opcode(char *opcode, unsigned int errLine)

{
	/* Array of valid opcode strings.*/
	char *opcodes[] = {"push", "pall", "pint", "pop", "swap", "add", "nop", "sub",
					 "div", "mul", "mod", "pchar", "pstr", "rotl", "rotr", NULL};
	int i = 0;
	int is_valid = 0;

	while (opcodes[i] != NULL)
	{
		/* Compare the input opcode with the valid opcode strings.*/
		if (strcmp(opcode, opcodes[i]) == 0)
		{
			is_valid = 1;
			break;
		}
		i++;
	}
	/* If the opcode is not valid, print an error message and set 'exec_failed'.*/
	if (!is_valid)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", errLine, opcode);
		global_vars.exec_failed = 1;
		return;
	}
}
