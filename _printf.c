#include "shell.h"
/**
 * clays_printf - stdout strings to be printed
 * @claysstring: output stdout string to be used
 * Return: an integer anytime its being used
 */
int clays_printf(const char *claysstring)
{
	return (write(STDOUT_FILENO, claysstring, strlen(claysstring)));
}

