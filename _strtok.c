#include <stdio.h>

char *_strchr(const char *str, int ch) {
    while (*str != '\0') {
        if (*str == ch)
            return (char *)str;
        str++;
    }

    if (ch == '\0')
        return (char *)str;

    return NULL;
}

char *_strtok(char *str, const char *delim) {
	static char *lastToken = NULL;
	char *token;
	int foundDelim = 0;

	if (str != NULL)
		lastToken = str;

	if (lastToken == NULL)
		return NULL;

	while (*lastToken != '\0' && _strchr(delim, *lastToken) != NULL)
		lastToken++;

	if (*lastToken == '\0') {
		lastToken = NULL;
		return NULL;
	}

	token = lastToken;
	while (*lastToken != '\0' && _strchr(delim, *lastToken) == NULL)
		lastToken++;

	if (*lastToken == '\0')
		lastToken = NULL;
	else {
		*lastToken = '\0';
		lastToken++;
		foundDelim = 1;
	}

	if (foundDelim)
		return token;
	else
		return _strtok(token, delim);
}
