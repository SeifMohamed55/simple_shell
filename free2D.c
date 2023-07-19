#include "header.h"
#include <stdlib.h>
#include <stdio.h>
void free2D(char **s)
{
	int i = 0;

	while (s && s[i])
	{
		free(s[i]);
		i++;
	}

}
