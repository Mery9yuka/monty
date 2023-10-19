#include "monty.h"
#include <stdio.h>
/**
 * addi_elemt - opcode that adds the top two elements of the stack
 * @stack: it's point to the Doubly linked list representing the stack
 * @line_number: the current instruction line number
 * Return: Void
 */
void addi_elemt(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	popi_elemt(stack, line_number);
}

/**
 * subi_elemt - opcode that subtracts the top element from
 *       the 2nd top element of the stack
 * @stack: it's point to the Doubly linked list that represent the stack
 * @line_number: the current instruction's line number
 * Return: Void
 */
void subi_elemt(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	popi_elemt(stack, line_number);
}

/**
 * divi_elemt - opcode that divides the 2nd top element
 *			by the top element of the stack
 * @stack: it's point to the Doubly linked list that represent the stack
 * @line_number: the current instruction's line number
 * Return: Void
 */
void divi_elemt(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	popi_elemt(stack, line_number);
}

/**
 * muli_elemt - opcode multiplies the second top element of the stack
 *			with the top element
 * @stack: it's a double pointer to the head of the stack
 * @line_number: the line number being interpreted from the Monty file
 */
void muli_elemt(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		stack_f(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	popi_elemt(stack, line_number);
}

/**
 * modi_elemt - opcode computes the modulo of the second top element
 *				of the stack by the top element of the stack
 * @stack: it's a double pointer to the head of the stack
 * @line_number: the line number being interpreted from the Monty file
 */
void modi_elemt(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		stack_f(stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		stack_f(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	popi_elemt(stack, line_number);
}
