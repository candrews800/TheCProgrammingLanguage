/* Clinton Andrews
 * 2016-05-03
 *
 * The C Programming Language
 * Exercise 1-18:
 * Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines.
 *
 */

#include <stdio.h>
#define MAXLINE	1000
#define MAX 80

int _getline(char line[], int lim);
char* trim(char line[], int length);

main()
{
	int length;
	char line[MAXLINE];

	while ((length = _getline(line, MAXLINE)) > 0)
		if (length > 1)
			printf("%s\n", trim(line, length));
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

char* trim(char line[], int length) {
	int i, j = 0;
	int start = 0, startFound = 0, end = 0;

	for (i=0; i < length; i++) {
		if (!startFound && line[i] != ' ' && line[i] != '\t') {
			start = i;
			startFound = 1;
		}

		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\0')
			end = i;
	}

	for (i=0; i < end+1; i++) {
		line[i] = line[i+start];
	}

	line[i] = '\n';
	line[++i] = '\0';

	return line;
}
