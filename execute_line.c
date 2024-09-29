#include "monty.h" 

instruction_t instructions[] = {
{"push", push_wrapper},
{"pall", pall},
{"pint", pint}, 
{"pop", pop}, 
{"swap", swap}, 
{"add", add}, 
{"nop", nop}, 
{"sub", sub}, 
{NULL, NULL}
};

void execute_line(char *line, stack_t **stack, unsigned int line_number) 
{
int i;
char *opcode = strtok(line, " \t\n");
char *arg = strtok(NULL, " \t\n");

if (!opcode) 
{
return;
}

if (strcmp(opcode, "push") == 0)
{
if (!arg)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
global_push_arg = atoi(arg);
}

for (i = 0; instructions[i].opcode; i++) 
{
if (strcmp(opcode, instructions[i].opcode) == 0) 
{
instructions[i].f(stack, line_number);
return;
}
}

fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
