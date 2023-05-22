#include "main.h"
/**
 * read_input_line - tokenize
 * Return: value
 */
char *read_input_line()
{
static char buffer[BUFFER_SIZE];
static ssize_t buffer_pos;
static ssize_t nread;
char *line = NULL;
size_t line_pos = 0;
int found_newline = 0;
while (!found_newline)
{
if (buffer_pos >= nread)
{
nread = read(STDIN_FILENO, buffer, BUFFER_SIZE);
buffer_pos = 0;
if (nread <= 0)
{
if (line != NULL)
{
free(line);
line = NULL;
}
break;
}
}
while (buffer_pos < nread)
{
char c = buffer[buffer_pos++];
if (c == '\n')
{
found_newline = 1;
break;
}
line = realloc(line, (line_pos + 1) * sizeof(char));
line[line_pos++] = c;
}
}
if (line != NULL)
{
line = realloc(line, (line_pos + 1) * sizeof(char));
line[line_pos] = '\0';
}
return (line);
}
/**
 * custom_output - tokenize
 * @message: input given by the user
 */
void custom_output(const char *message)
{
size_t i = 0;
while (message[i] != '\0')
{
write(STDOUT_FILENO, &message[i], 1);
i++;
}
}
/**
 * main - Entry point
 *
 * Description: Simple shell program that reads commands from standard input
 * and executes them using the execve system call.
 *
 * Return: Always 0
 */
int main(void)
{
char *line;
while (1)
{
line = read_input_line();
if (line == NULL)
break;
custom_output("User Input: ");
custom_output(line);
custom_output("\n");
free(line);
}
return (0);
}

