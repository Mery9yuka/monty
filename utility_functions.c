#include "monty.h"
#include <stdlib.h>

/**
 * is_numerico - function checks if a string represents a numeric value
 * @s: the input string
 * Return: 1 if numeric, 0 if not
 */
int is_numerico(const char *s)
{
	if (*s == '-' && isdigit(*(s + 1)))
		s++;

	while (*s)
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

/**
 * str_trim - function trims leading and trailing spaces from a string
 * @s: the input string
 */
void str_trim(char *s)
{
	int first = 0, last = strlen(s) - 1;
	int a, b;

	while (s[first] && isspace(s[first]))
	{
		first++;
	}

	while (last >= 0 && isspace(s[last]))
	{
		last--;
	}

	for (a = first, b = 0; a <= last; a++, b++)
	{
		s[b] = s[a];
	}

	s[b] = '\0';
}

/**
 * stack_f - function frees a stack_t linked list
 * @stack: it's a double pointer to the head of the stack
 */
void stack_f(stack_t **stack)
{
	while (*stack != NULL)
	{
		stack_t *buf = *stack;
		*stack = (*stack)->next;
		free(buf);
	}
}

/**
 * cstm_basename - function extracts the filename from a given path
 * @path_file: the input path
 * Return: the pointer to the extracted filename
 */
char *cstm_basename(char *path_file)
{
	char *file_name = strrchr(path_file, '/');

	if (file_name == NULL)
		return (path_file);
	else
		return (file_name + 1);
}
