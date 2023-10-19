#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * pchari_elemt - function that prints the character at the top of the stack
 * @stack: points to the head of the stack
 * @line_number: Line number in the Monty file
 */
void pchari_elemt(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
/**
 * pstri_elemt - function that prints the string starting
 *                  from the top of the stack
 * @stack: points to the head of the stack
 * @line_number: the Monty file line number
 */
void pstri_elemt(stack_t **stack, unsigned int line_number)
{
	stack_t *c = *stack;

	while (c != NULL && c->n != 0 && (c->n > 0 && c->n <= 127))
	{
		printf("%c", c->n);
		c = c->next;
	}
	printf("\n");

	(void)line_number;
}
