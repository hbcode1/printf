#include "main.h"

/**
 * print_buffer - prints the buffer if it exists
 * @buffer: buffer array of chars of max BUFF_SIZE size (1024)
 * @index: index of last recieved char into buffer
 *
 * Return: Nothing
 */
void print_buffer(char buffer[], int *index)
{
	int i = 0;

	if (*index > 0)
	{
		while (i < *index)
		{
			_putchar(buffer[i++]);
		}
	}
	*index = 0;
}
