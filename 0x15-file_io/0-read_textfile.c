#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * read_textfile - reads a text file and prints
 * it to POSIX stdout.
 * @filename: a pointer to the name of the file
 * @letters: the number of letters the function
 * should read and print
 * Return: if the function fails or filename is NULL - 0
 * Otherwise - the actual number of bytes the function
 * can read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
if (filename == NULL)
{
return (0);
}
int fd = open(filename, O_RDONLY);
if (fd == -1)
{
return (0);
}
char buffer[1024];
ssize_t total_read = 0;
ssize_t n;

while (total_read < letters && (n = read(fd, buffer, sizeof(buffer))) > 0)
{
ssize_t nwritten = write(STDOUT_FILENO, buffer, n);
if (nwritten != n)
{
close(fd);
return (0);
}
total_read += nwritten;
}
close(fd);
return (total_read);
}

