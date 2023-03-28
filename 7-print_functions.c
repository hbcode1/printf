#include "main.h"

/**
 * handle_flags - handles the possible flags in format string
 * @format: format string to look inside of
 * @index: current index position inside format
 * @flags: flags to handle
 * Description: takes the @format and the current @index inside the format
 *				looks for flags in the next few chars,
 *				then loops through format, and when it finds flag, it returns
 *				the flag identifier for that flag
 * Return: flags
 */
int handle_flags(const char *format, int *index, _flag_t *flags)
{
	int i, j, k = *index, result = 0;

	for (i = *index; format[i] != '\0' && format[i] != '%'; i++)
	{
		for (j = 0; flags[j].id != 0; j++)
		{
			if (format[i] == flags[j].id)
			{
				result |= flags[j].value;
				k++;
				break;
			}
		}
		if (flags[j].id == 0)
			break;
	}
	*index = k;
	return (result);
}
