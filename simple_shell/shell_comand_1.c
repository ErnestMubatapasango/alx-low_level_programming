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
 * execute_user_input -  tokenize
 * @user_input: input given by the user
 */
void execute_user_input(char *user_input)
{

char *args[ARGS_SIZE] = {NULL};
int arg_count = 0;
char *token = strtok(user_input, " ");

while (token && arg_count < ARGS_SIZE - 1)
{
args[arg_count++] = token;
token = strtok(NULL, " ");
}
execvp(args[0], args);
perror("execvp error");
exit(EXIT_FAILURE);
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

char user_input[BUFFER_SIZE];
ssize_t xrd;
pid_t pid;
while (1)
{
prompt();
xrd = read(STDIN_FILENO, user_input,  BUFFER_SIZE);
if (xrd == -1)
{
perror("read error");
exit(EXIT_FAILURE);
}
else if (xrd == 0)
{
printf("\n");
break;
}
user_input[xrd - 1] = '\0';
pid = fork();
if (pid == -1)
{
perror("fork error");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execute_user_input(user_input);
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}
exit(EXIT_SUCCESS);
}
