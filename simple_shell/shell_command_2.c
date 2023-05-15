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
char *args[ARG_SIZE] = {NULL};
int arg_count = 0;
char *token = strtok(user_input, " ");
while (token && arg_count < ARG_SIZE - 1)
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
char buffer[BUFFER_SIZE];
ssize_t read_count;
pid_t child_pid;
int child_status;
while (1)
{
prompt();
read_count = read(STDIN_FILENO, buffer, BUFFER_SIZE);
if (read_count == -1)
{
perror("read error");
exit(EXIT_FAILURE);
}
else if (read_count == 0)
{
printf("\n");
break;
}
buffer[read_count - 1] = '\0';
int command_exists = access(buffer, X_OK);
if (command_exists == -1)
{
perror("command does not exist");
continue;
}
child_pid = fork();
if (child_pid == -1)
{
perror("fork error");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
execute_command(input_buffer);
exit(EXIT_FAILURE);
}
else
{
waitpid(child_pid, &child_status, 0);
}
}
exit(EXIT_SUCCESS);
}
