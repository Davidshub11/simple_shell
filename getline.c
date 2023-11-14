#include "shell.h"
/**
 * clays_getline - main program to read
 * @clays_buf: buffer storage
 * @clays_size: size read buffer
 * Return: a signed int anytime being called
 */
ssize_t clays_getline(char **clays_buf, size_t *clays_size)
{
	static char clays_staticbuff[1024];

	ssize_t clays_numread;

	*clays_buf = NULL;

	if (*clays_buf == NULL)
	{
		*clays_buf = clays_staticbuff;
	}
	*clays_size = sizeof(clays_staticbuff);

	clays_numread = read(0, *clays_buf, *clays_size);

	if (clays_numread == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (clays_numread == 0)
	{
		if (isatty(0))
			clays_printf("\n");
		exit(EXIT_SUCCESS);
	}

	return (clays_numread);
}

