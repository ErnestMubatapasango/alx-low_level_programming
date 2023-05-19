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
 * is_exit_user_input -  tokenize
 * @user_input: input given by the user
 */
int is_exit_user_input(char *user_input)
{
size_t i = 0;
const char exit_user_input[] = "exit";
while (user_input[i] && exit_user_input[i])
{
if (user_input[i] != exit_user_input[i])
{
return (0);
}
i++;
}
return user_input[i] == '\0' && exit_user_input[i] == '\0';
}
/**
 * handle_exit - Prints a prompt to the standard output
 */
void handle_exit(void)
{
exit(EXIT_SUCCESS);
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
char input_buffer[BUFFER_SIZE];
ssize_t xrd;
pid_t child_pid;
int child_status;
while (1)
{
prompt();
xrd = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
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
input_buffer[xrd - 1] = '\0';
int command_exists = access(input_buffer, X_OK);
if (command_exists == -1)
{
perror("command does not exist");
continue;
}
if (is_exit_user_input(input_buffer))
{
handle_exit();
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
