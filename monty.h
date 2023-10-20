#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int value;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void stack_f(stack_t **stack);
void pushi_elemt(stack_t **stack, unsigned int line_nmer);
void palli_elemt(stack_t **stack, unsigned int line_number);
void pinti_elemt(stack_t **stack, unsigned int line_number);
void popi_elemt(stack_t **stack, unsigned int line_number);
void swapi_elemt(stack_t **stack, unsigned int line_number);
void addi_elemt(stack_t **stack, unsigned int line_number);
void nopi_elemt(stack_t **stack, unsigned int line_number);
void muli_elemt(stack_t **stack, unsigned int line_number);
void modi_elemt(stack_t **stack, unsigned int line_number);
void divi_elemt(stack_t **stack, unsigned int line_number);
void subi_elemt(stack_t **stack, unsigned int line_number);
void executor_instructs(char *opcode, stack_t **stack,
		unsigned int line_number, char *line, FILE *file);
int is_numerico(const char *s);
void str_trim(char *s);
char *cstm_basename(char *path_file);
void pchari_elemt(stack_t **stack, unsigned int line_number);
void pstri_elemt(stack_t **stack, unsigned int line_number);
void rotli_elemt(stack_t **stack, unsigned int line_number)
#endif /* MONTY_H */
