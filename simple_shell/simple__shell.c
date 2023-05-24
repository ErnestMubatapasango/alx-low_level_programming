#include "main.h"
/**
 * _strlen - Calculates the length of a string
 *
 * @a: Pointer to the null-terminated string to be measured.
 *
 * Return: The number of characters that precede the null character.
 */
size_t _strlen(char *a)
{
size_t length;

while (a[length != '\0'])
length++;

return (length);
}

/**
 * prompt - Prints a prompt to the standard output
 */

void prompt(void)
{
char prompt_str[] = "$ ";
write(STDOUT_FILENO, prompt_str, _strlen(prompt_str));
fflush(stdout);
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
size_t size = 1024;
ssize_t chars;
char **args;
int i;
pid_t pid;
char *user__input = (char *)malloc(1024 * sizeof(char));
bool from_pipe = false;
if (!user__input)
{
perror("Memory allocation failed");
exit(EXIT_FAILURE);
}

while (1)
{
if (isatty(STDIN_FILENO) == 0)
from_pipe = true;

prompt();

chars = getline(&user__input, &size, stdin);
if (chars == -1)
{
perror("Input reading failed");
exit(EXIT_FAILURE);
}
args = malloc(1024 * sizeof(char *));
if (!args)
{
perror("Memory allocation failed");
exit(EXIT_FAILURE);
}

args[0] = strtok(user__input, " \n");
i = 1;
while (i < 1024  && (args[i] = strtok(NULL, " \n")))
i++;

pid = fork();
if (pid == -1)
{
perror("Child process creation failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execve(args[0], args, NULL) == -1)
{
perror("Command execution failed");
exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
}

free(args);
}

free(user__input);
return (0);
}
