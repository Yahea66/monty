#include "monty.h"
/**
* pop - removes the top element of the stack.
* @stack: pointer to a pointer to a stack.
* @line_number: the line being parsed
*
* Return: void
*/
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
if (!(*stack))
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
tmp = *stack;
*stack = (*stack)->next;
if (*stack)
{
(*stack)->prev = NULL;
}
free(tmp);
}
