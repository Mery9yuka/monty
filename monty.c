#include "monty.h"
#include <string.h>

/**
 * main - entry point for the Monty interpreter
 * @argc: the number of command-line arguments
 * @argv: an array of command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	char *file_name = cstm_basename(argv[1]);
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = NULL;
	char *line = NULL;
	size_t length = 0;
	unsigned int line_number = 0;
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &length, file) != -1)
	{
		line_number++;
		str_trim(line);
		opcode = strtok(line, " \t\n");

		if (opcode != NULL && opcode[0] != '#')
		{
			executor_instructs(opcode, &stack, line_number, line, file);
		}
	}

	free(line);
	fclose(file);
	stack_f(&stack);
	return (EXIT_SUCCESS);
}

/**
 * executor_instructs - function that executes
 *						the appropriate instruction based on opcode
 * @opcode: the operation code
 * @stack: it's a double pointer to the stack
 * @line_number: the line number in the Monty byte-code file
 * @line: the current line being processed
 * @file: it's a pointer to the Monty byte-code file
 */
void executor_instructs(char *opcode, stack_t **stack,
		unsigned int line_number, char *line, FILE *file)
{
	if (strcmp(opcode, "push") == 0)
		pushi_elemt(stack, line_number);
	else if (strcmp(opcode, "pall") == 0)
		palli_elemt(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pinti_elemt(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		popi_elemt(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swapi_elemt(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		addi_elemt(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nopi_elemt(stack, line_number);
	else if (strcmp(opcode, "mul") == 0)
		muli_elemt(stack, line_number);
	else if (strcmp(opcode, "mod") == 0)
		modi_elemt(stack, line_number);
	else if (strcmp(opcode, "sub") == 0)
		subi_elemt(stack, line_number);
	else if (strcmp(opcode, "div") == 0)
		divi_elemt(stack, line_number);
	else if (strcmp(opcode, "pchar") == 0)
		pchari_elemt(stack, line_number);
	else if (strcmp(opcode, "pstr") == 0)
		pstri_elemt(stack, line_number);
	else if (strcmp(opcode, "rotl") == 0)
		rotli_elemt(stack, line_number);
	else if (strcmp(opcode, "rotl") == 0)
		rotri_elemt(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		free(line);
		fclose(file);
		stack_f(stack);
		exit(EXIT_FAILURE);
	}
}
