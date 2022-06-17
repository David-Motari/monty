#include "monty.h"

/**
 * get_ops - matches opcode to function
 *
 * @opcode: opcode pointing to function
 * Return: opcode function
 */
void (*get_ops(char *opcode))(stack_t **stack, unsigned int nline)
{
	unsigned int i;
	instruction_t op_list[] = {
		{ "push", push },
		{ "pall", pall },
		{ "pint", pint },
		{ "swap", swap },
		{ "add", add },
		{ "nop", nop },
		{ "pop", pop },
		{ "sub", sub },
		{ "div", o_div },
		{ "mul", mul },
		{ "mod", mod },
		{ "pchar", pchar },
		{ "pstr", pstr },
		{ "rotl", rotl },
		{ "rotr", rotr },
		{ "stack", o_stack },
		{ "queue", o_queue },
		{ NULL, NULL }
	};

	for (i = 0; op_list[i].opcode; i++)
	{
		if (strcmp(opcode, op_list[i].opcode) == 0)
			return (op_list[i].f);
	}
	return (NULL);
}

/**
 * _isdigit - prints the return value is digit or not
 * @str: string to check
 * Return: 1 if it's digit and 0 otherwise
 */
int _isdigit(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
	}
	return (1);
}
