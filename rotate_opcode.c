#include "monty.h"

/**
 * my_rotl - Move top element to bottom of the stack.
 *
 * @h: Pointer to the head of the stack.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothing.
 */

void my_rotl(stack_t **h, unsigned int errLine)
{
	stack_t *temp = NULL;
	stack_t *current_element = NULL;
	(void)errLine;

	if (!h || !*h || !(*h)->next)
		/* Nothing to rotate if the stack is empty or has only one element*/
		return;

	/* Save the current top element*/
	temp = *h;
	/* Update the head to the next element*/
	*h = (*h)->next;
	/* The new top element's previous should be NULL*/
	(*h)->prev = NULL;
	/* The old top element will be the new bottom.*/
	temp->next = NULL;

	current_element = *h;

	while (current_element->next)
		/* Find the current last element*/
		current_element = current_element->next;
	current_element->next = temp;
	temp->prev = current_element;
}

/**
 * my_rotr - Move bottom elements to the top of the stack.
 *
 * @h: Pointer to the head of the stack.
 * @errLine: Pointer to the error line.
 *
 * Return: Nothing.
 */

void my_rotr(stack_t **h, unsigned int errLine)
{
	stack_t *current_element = NULL;
	(void)errLine;

	if (!h || !*h || !(*h)->next)
		/* Nothing to rotate if the stack is empty or has only one element*/
		return;

	current_element = *h;
	while (current_element->next)
		/* Find the current last element*/
		current_element = current_element->next;
	current_element->prev->next = NULL;
	current_element->prev = NULL;

	current_element->next = *h;
	(*h)->prev = current_element;
	*h = current_element;
}
