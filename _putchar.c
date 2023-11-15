#include "shell.h"
/**
 * clays_putchar - printing putchar
 * @clays_char: char to be printed also
 * Return: returns int anytime used always
 */
int clays_putchar(char clays_char)
{
	return (write(STDOUT_FILENO, &clays_char, 1));
}

