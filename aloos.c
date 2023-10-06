#include "shell.h"
/**
 *ch_dir - Function to change directory
 *@line: Command line
 *@c: command structure
 *
 *Return: 0  success
 */
int ch_direc(char **line, __attribute__((unused))int c)
{
	int hool = -1;
	char cwd[PATH_MAX];

	if (line[1] == NULL)
		hool = chdir(getenv("HOME"));
	else if (my_strcmp(line[1], "-") == 0)
		hool = chdir(getenv("OLDPWD"));
	else
		hool = chdir(line[1]);
/* change directary */
	if (hool == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (hool != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 *print_env - Function to print env
 *@line: Line command
 *@s: command status
 *
 *Return: 0 sucess
 */
int print_enviro(__attribute__((unused)) char **line,
		__attribute__((unused)) int s)
{
	int val;
	size_t b;
/* environ command */
	for (b = 0; environ[b] != NULL; b++)
	{
		val = my_strlen(environ[b]);
		write(1, environ[b], val);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
