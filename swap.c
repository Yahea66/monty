#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to a pointer to a stack. 
 * @line_number: the line being parsed 
 *
 * Return: void 
 */
void swap(stack_t **stack, unsigned int line_number)
{
stack_t *first;
stack_t *second;
if (!(*stack) || !(*stack)->next) 
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE); 
} 
first = *stack;
second = (*stack)->next; 
first->next = second->next;
if (second->next) 
{
(second->next)->prev = first;
} 
second->prev = NULL;
second->next = first;
first->prev = second;
*stack = second;
}
