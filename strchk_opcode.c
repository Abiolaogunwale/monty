#include "monty.h"

/**
 * strchk_opcode - Checks if the string contains only digits.
 *
 * @s: Pointer to the string to check.
 *
 * Return: 1 if only digits, 0 otherwise.
 */

int strchk_opcode(char *s)
{
	/* Initialize a counter variable.*/
	int i = 0;

	while (*(s + i) != '\0')
	{
		/* Check if the character is not a digit.*/
		if (*(s + i) != '-' && !isdigit(*(s + i)))
			return (0);
		i++;
	}
	return (1);
}
