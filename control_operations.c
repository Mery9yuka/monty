#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * popi_elemt - opcode that removes the top element of the stack.
 * @stack: points to the Doubly linked list that represent the stack.
 * @line_number: the current instruction line number
 * Return: Void
 */
void popi_elemt(stack_t **stack, unsigned int line_number)
{
	stack_t *buf;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	buf = *stack;
	*stack = (*stack)->next;
	free(buf);
}

/**
 * nopi_elemt - opcodes that does nothing it's a no-operation
 *       (placeholder) instruction.
 * @stack: points to the D linked list that represent the not used stack
 * @line_number: current instruction line number (not used).
 * Return: Void
 */
void nopi_elemt(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swapi_elemt - opcode that swaps the top two elements of the stack.
 * @stack: point to the D linked list that represent the stack.
 * @line_number: current instruction line number.
 * Return: Void
 */
void swapi_elemt(stack_t **stack, unsigned int line_number)
{
	int buf = (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = buf;
}
