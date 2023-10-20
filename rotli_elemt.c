#include "monty.h"
/**
 * rotli_elemt - function that rotates the stack to the top.
 * @stack: points to the head of  stack
 * @line_number: Monty fileLine number
 */
void rotli_elemt(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *middle, *bottom;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	top = *stack;
	middle = top->next;
	bottom = *stack;

	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}

	bottom->next = top;
	top->prev = bottom;
	top->next = NULL;
	middle->prev = NULL;
	*stack = middle;
}
