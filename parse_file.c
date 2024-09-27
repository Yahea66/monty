#include "monty.h"
void parse_file(char *file_path)
{
char line[1024];
unsigned int line_number = 1;
stack_t *stack = NULL;
FILE *file = fopen(file_path, "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", file_path);
exit(EXIT_FAILURE);
}
while (fgets(line, sizeof(line), file) != NULL)
{
line[strcspn(line, "\n")] = 0;
execute_line(line, &stack, line_number);
line_number++;
}
fclose(file);
}
