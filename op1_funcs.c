#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element of the
 * stack by the top element of the stack.
 *
 * @stack: first node linked list list
 * @nline: current line
 */
void mod(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	temp = *stack;
	if (!temp || !temp->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", nline);
		free_monty();
		exit(EXIT_FAILURE);
	}

	if (temp->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", nline);
		free_monty();
		exit(EXIT_FAILURE);
	}

    /*value of next update*/
	temp->next->n %= temp->n;	
	temp = temp->next;
	temp->prev = NULL;
	free(*stack);
	*stack = temp;
}

/**
 * pchar - prints the character at the top of the stack
 *
 * @stack: first node in linked list
 * @nline: current line
 */
void pchar(stack_t **stack, unsigned int nline)
{
	if (!stack || !*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", nline);
		free_monty();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", nline);
		free_monty();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints string from top of stack
 *
 * @stack: first node in linked list
 * @nline: current line
 */
void pstr(stack_t **stack, unsigned int nline)
{
	stack_t *current;
	(void) nline;

	current = *stack;
	while (current && (current->n > 0 && current->n <= 127))
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}

/**
 * rotl - rotate stack to top
 *
 * @stack: first node in linked list
 * @nline: current line
 */
void rotl(stack_t **stack, unsigned int nline)
{
	stack_t *current, *head;

	(void) nline;

	if (!*stack)
		return;

	current = head = *stack;
	while (current && current->next)
		current = current->next;

	/* Turn linked list circular*/
    current->next = head;
    /* move first node to second position*/
	*stack = head->next; 
	head->next = NULL;
	head->prev = current;
}

/**
 * rotr - rotates the stack to the top
 *
 * @stack: first node in the linked list
 * @nline: current line
 */
void rotr(stack_t **stack, unsigned int nline)
{
	stack_t *current, *head;

	(void) nline;

	if (!*stack)
		return;

	current = head = *stack;
	while (current && current->next)
		current = current->next;

	/*Turn linked list circular*/
    current->next = head; 
	head->prev = current;
	current->prev->next = NULL;
	current->prev = NULL;
	*stack = current;
}