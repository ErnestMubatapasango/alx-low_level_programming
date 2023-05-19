#include "main.h"
/**
 * read_input_line - read input
 * @line: input value
 * Return: value
 */
void read_input_line(char *line)
{
int pos = 0;
char d;
while (pos < BUFFER_SIZE - 1 && read(STDIN_FILENO, &d, 1) > 0)
{
if (d == '\n')
{
line[pos] = '\0';
return;
}
line[pos++] = d;
}
line[pos] = '\0';
}
/**
 * parse_user_input - parse input
 * @line: input given by the user
 * @argw: argw
 * @argd: argd
 */
void parse_user_input(char *line, char **argw, int *argd)
{
int i = 0;
int arg_pos = 0;
int is_arg = 0;

while (*line)
{
if (*line == ' ')
{
if (is_arg)
{
argv[i][arg_pos] = '\0';
i++;
arg_pos = 0;
is_arg = 0;
}
}
else
{
if (!is_arg)
{
argw[i] = malloc((MAX_ARGS + 1) * sizeof(char));
if (argw[i] == NULL)
{
perror("Allocation error");
exit(EXIT_FAILURE);
}
is_arg = 1;
}
argw[i][arg_pos++] = *line;
}
line++;
}
if (is_arg)
{
argw[i][arg_pos] = '\0';
i++;
}
argw[i] = NULL;
*argd = i;
}
/**
 * execute_user_input -  tokenize
 * @argw: input given by the user
 */
void execute_user_input(char **argw)
{
pid_t pid = fork();
if (pid < 0)
{
perror("Fork error");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execvp(argw[0], argw) < 0)
{
perror("Execution error");
exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
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
char line[BUFFER_SIZE];
char *argw[ARGS_ARGS + 1];
int argd;

while (1)
{
char prompt[] = "shell$ ";
write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
read_input_line(line);
if (line[0] == '\0')
break;

parse_user_input(line, argw, &argd);
if (argd > 0)
{
execute_user_input(argw);
}
for (int i = 0; i < argd; i++)
{
free(argw[i]);
}
}
return (0);
}

