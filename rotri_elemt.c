#include "monty.h"
/**
 * rotri_elemt - function that rotates the top
 *  element of the stack to the bottom.
 * @stack: it's a points to the head of stack
 * @line_number: the Monty file Line number
 */
void rotri_elemt(stack_t **stack, unsigned int line_number)
{
    stack_t *bottom, *snd_bottom;
    (void)line_number;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    bottom = *stack;

    while (bottom->next != NULL)
    {
        bottom = bottom;
        bottom = bottom->next;
    }

    snd_bottom->next = NULL;
    bottom->prev = NULL;
    bottom->next = *stack;
    (*stack)->prev = bottom;
    *stack = bottom;
}