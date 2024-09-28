#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to a pointer to a stack. 
 * @line_number: the line being parsed 
 *
 * Return: void 
 */
void add(stack_t **stack, unsigned int line_number)
{
stack_t *first;
stack_t *second;
int sum;
if (!(*stack) || !(*stack)->next) 
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE); 
} 
first = *stack;
second = (*stack)->next;
sum = first->n + second->n;
second->n = sum;

second->prev = NULL;
*stack = second;
free(first);
} 
