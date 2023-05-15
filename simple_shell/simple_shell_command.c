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

while (a[length] != '\0')
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
pid_t pid;
char user__input[1024];
ssize_t xrd;
char *error[1024], *new[1024];

do {
prompt();
xrd = read(STDIN_FILENO, user__input, 1024);
if (xrd == -1)
{
error[BUFFER_SIZE] = "read ERROR\\n";
write(STDERR_FILENO, error, sizeof(error) - 1);
exit(EXIT_FAILURE);
}
else if (xrd == 0)
{
new[BUFFER_SIZE] = "\n";
write(STDOUT_FILENO, new, sizeof(new) - 1);
break;
}
user__input[xrd - 1] = '\0';
pid = fork();
if (pid == -1)
{
error[BUFFER_SIZE] = "fork error\\n";
write(STDERR_FILENO, error, sizeof(error) - 1);
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execlp(user__input, user__input, (char *)NULL);
error[BUFFER_SIZE] = "execlp error\\n";
write(STDERR_FILENO, error, sizeof(error) - 1);
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}
while (1);
exit(EXIT_SUCCESS);
}
