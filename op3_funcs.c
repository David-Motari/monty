#include "monty.h"

/**
 * push - adds node to top of stack
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void push(stack_t **stack, unsigned int nline)
{
	stack_t *new_node, *temp = *stack;
	int value;


	if (!monty.arg || !_isdigit(monty.arg))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", nline);
		exit(EXIT_FAILURE);
	}
	value = atoi(monty.arg);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		exit(EXIT_FAILURE);

	new_node->n = value, new_node->next = NULL, new_node->prev = NULL;

	if (!(*stack))
	{
		*stack = new_node;
		return;
	}

	if (strcmp("stack", monty.operate) == 0)	/* for (LIFO) */
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
		*stack = new_node;
		return;
	}

	if (!(*stack)->next)	/* for queue (FIFO) */
		temp->next = new_node, new_node->prev = temp;
	else
	{
		while (temp->next)
			temp = temp->next;

		temp->next = new_node, new_node->prev = temp;
	}
}

/**
 * pall - print all value of list
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void pall(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	(void)nline;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of stack
 *
 * @stack: first node in the list
 * @nline: line  currently on
 */
void pint(stack_t **stack, unsigned int nline)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", nline);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - deletes top item in stack
 *
 * @stack: head node in the list
 * @nline: current line
 */
void pop(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	temp = temp->next;
	free(*stack);
	if (temp)
		temp->prev = NULL;
	*stack = temp;
}

/**
 * swap - swaps two elements on-top  of stack
 *
 * @stack: head node in the list
 * @nline: current line
 */
void swap(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
temp = *stack;
	if (!temp || !temp->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp->prev = temp->next;
	temp->next->prev = NULL;
	if (temp->next->next)
		temp->next->next->prev = temp;
	temp->next = temp->next->next;
	temp->prev->next = temp;
	*stack = temp->prev;
}