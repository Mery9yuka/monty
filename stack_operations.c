#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * pushi_elemt - opcode that pushes an int onto the stack.
 * @stack: point to the Doubly linked list that represent the stack.
 * @line_number: the current instruction's line number
 * Return: Void
 */
void pushi_elemt(stack_t **stack, unsigned int line_number)
{
	char *number = strtok(NULL, " \n");
	int value = atoi(number);
	stack_t *n_node = malloc(sizeof(stack_t));

	if (number == NULL || !is_numerico(number))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (n_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		stack_f(stack);
		exit(EXIT_FAILURE);
	}
	n_node->n = value;
	n_node->prev = NULL;
	n_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = n_node;
	}

	*stack = n_node;
}
/**
 * palli_elemt - Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number being interpreted from the Monty file
 */
void palli_elemt(stack_t **stack, unsigned int line_number)
{
	stack_t *c = *stack;

	(void)line_number;

	while (c != NULL)
	{
		printf("%d\n", c->n);
		c = c->next;
	}
}
/**
 * pinti_elemt - opcode that prints a value at the top of the stack.
 * @stack: points to the Doubly linked list that represent the stack.
 * @line_number: the current instruction line number
 * Return: Void
 */
void pinti_elemt(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
