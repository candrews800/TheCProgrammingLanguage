/* Clinton Andrews
 * 2016-04-02
 *
 * The C Programming Language
 * Exercise 1-17:
 * Write a program to print all input lines that are longer than 80
 * characters.
 *
 */

#include <stdio.h>
#define MAXLINE	1000
#define MAX 80

int _getline(char line[], int lim);

main()
{
	int length;
	char line[MAXLINE];

	while ((length = _getline(line, MAXLINE)) > 0)
		if (length > MAX)
			printf("%s", line);
}

int _getline(char line[], int lim) {
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		line[i] = c;

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}
