#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * _strlen - dlkflds
 * @s: the string
 *
 * Return : no of charachters
 */
int _strlen(char *s)
{
	int x = 0;

	if (!s)
	{
		return (0);
	}
	while (s[x] != '\0')
	{
		x++;
	}
	return (x);

}
