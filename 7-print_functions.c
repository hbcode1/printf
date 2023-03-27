#include "main.h"

/**
 * handle_flag - handles the possible flags in format string
 * @format: format string to look inside of
 * @index: current index position inside format
 *
 * Description: takes the @format and the current @index inside the format
 *				looks for flags in the next few chars,
 *				then loops through format, and when it finds flag, it returns
 *				the flag identifier for that flag
 * Return: flags
 */
int handle_flag(const char *format, int *index)
{
	int i, j, k, result = 0;
	_flag_t flags[] = handle_flags();

	for (i = *index; format[i] != '\0' && format[i] != '%'; i++)
	{
		for (j = 0; flags[j].id != 0; j++)
		{
			if (format[i] == flags[j].id)
			{
				result |= flags[j].value;
			}
		}
	}
	*index = i - 1;
	return (result);
}
