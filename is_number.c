
   
#include "monty.h"

/**
* is_number - check is the value passed is a number
* @s: value passed
* Return: 1 if is a number, 0 otherwise
*/
int is_number(char *s)
{
	if (s == NULL)
		return (0);

	if (*s == '-')
		s++;

	for (; *s != '\0'; s++)
		if (isdigit(*s) == '\0')
			return (0);
	return (1);
}
