#include "monty.h" 

int global_push_arg = 0;
void push(stack_t **stack, unsigned int line_number, int n) 
{
stack_t *new_node;
(void)line_number;
new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = n;
new_node->prev = NULL;
new_node->next = *stack;
if (*stack) 
{
(*stack)->prev = new_node;
} 
*stack = new_node;
}

void push_wrapper(stack_t **stack, unsigned int line_number)
{
push(stack, line_number, global_push_arg);
} 

void pall(stack_t **stack, unsigned int line_number) 
{
stack_t *current;
(void)line_number;
current = *stack;
while (current)
{
printf("%d\n", current->n);
current = current->next;
} 
} 
