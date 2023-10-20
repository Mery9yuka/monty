#include "monty.h"
/**
 * rotri_elemt - function that rotates the top
 *  element of the stack to the bottom.
 * @stack: points to the head of stack
 * @line_number: the Monty file Line number
 */
void rotri_elemt(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *prev_last;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;

	while (last->next != NULL)
	{
		prev_last = last;
		last = last->next;
	}

	prev_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
