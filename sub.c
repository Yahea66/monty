#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element of the stack.
 * @stack: pointer to a pointer to a stack. 
 * @line_number: the line being parsed 
 *
 * Return: void 
 */
void sub(stack_t **stack, unsigned int line_number)
{
stack_t *first;
stack_t *second;
int sub;
if (!(*stack) || !(*stack)->next) 
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
exit(EXIT_FAILURE); 
} 
first = *stack;
second = (*stack)->next;
sub = second->n - first->n;
second->n = sub;

second->prev = NULL;
*stack = second;
free(first);
} 
