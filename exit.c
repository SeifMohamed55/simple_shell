#include "header.h"
#include <stdlib.h>
void myexit(char **s, int stat)
{
	int i = 0, len;
	int sum = 0, c = 1;

	if(!s[1])
	{
		free2D(s);
		free(s);
		exit(stat);
	}
	while(s[1][i])
	{
		if (!(s[1][i] - '0' >= 0  && s[1][i] <= '9'))
			return; /* see what we do */
		i++;
	}
	len = _strlen(s[1]);
	for (i = len - 1 ; i >= 0 ; i--)
	{
		sum += (s[1][i] - '0') * c;
		c *= 10;
	}
	free2D(s);
	free(s);
	exit(sum);
}
