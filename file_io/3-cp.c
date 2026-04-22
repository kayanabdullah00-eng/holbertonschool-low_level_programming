#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

void close_fd(int fd);
void copy_file(int fd_from, int fd_to, char *file_from, char *file_to);

/**
 * main - copies content of one file to another
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success, exit codes on failure
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		close(fd_from);
		exit(99);
	}

	copy_file(fd_from, fd_to, av[1], av[2]);

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}

/**
 * copy_file - copies data from one file to another
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_from: name of source file
 * @file_to: name of destination file
 *
 * Return: void
 */
void copy_file(int fd_from, int fd_to, char *file_from, char *file_to)
{
	char buffer[BUF_SIZE];
	ssize_t r, w;

	while ((r = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close(fd_from);
		close(fd_to);
		exit(98);
	}
}

/**
 * close_fd - closes a file descriptor safely
 * @fd: file descriptor to close
 *
 * Return: void
 */
void close_fd(int fd)
{
	int c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
