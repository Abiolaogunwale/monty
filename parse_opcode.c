#include "monty.h"

/**
 * parse_opcode - Get the opcodes from the given string.
 *
 * @s: Pointer to the string to parse.
 *
 * Return: pointer to allocated memory storing opcode.
 */

char *parse_opcode(char *s)
{
	char buffer[1024] = {0};
	char delim = ' ';
	int tokens_count = 0;
	int i = 0;

	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == delim || isspace(*s))
			s++;
		if (*s == '\0' || *s == '\n')
			break;
		while (*s != delim && !isspace(*s) && *s != '\0' && *s != '\n')
		{
			buffer[i] = *s;
			s++;
			i++;
		}
		buffer[i] = '\0';
		if (tokens_count == 0)
		{
			/* Allocate memory for opcode and copy it.*/
			global_vars.opcode = malloc(sizeof(char) * (strlen(buffer) + 1));
			malloc_char_check(global_vars.opcode);
			strcpy(global_vars.opcode, buffer);
			tokens_count = 1;
		}
		else if (tokens_count == 1)
		{
			/* Allocate memory for push_arg (if exists) and copy it.*/
			global_vars.push_arg = malloc(sizeof(char) * (strlen(buffer) + 1));
			malloc_char_check(global_vars.push_arg);
			strcpy(global_vars.push_arg, buffer);
			break;
		}
		i = 0;
	}
	return (global_vars.opcode);
}
