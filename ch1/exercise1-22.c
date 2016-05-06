/* Clinton Andrews
 * 2016-05-05
 *
 * The C Programming Language
 * Exercise 1-22:
 * Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before
 * the n-th column of input. Make sure your program does something intelligent
 * with very long lines, and if there are no blanks or tabs before the
 * specified column.
 *
 */

#include <stdio.h>

#define MAXLINE	1000

int _getline(char line[], int lim);
char* fold(char line[], int columns);

main()
{
	int length;
	int COLUMNS = 80, TABSIZE = 8;
	char line[MAXLINE];

	while ((length = _getline(line, MAXLINE)) > 0)
		printf("%s", fold(line, COLUMNS));
}

int _getline(char line[], int lim)
{
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

char* fold(char line[], int columns)
{
	int i, added_chars = 0, line_size = 0;
	char s[MAXLINE];

	for (i=0; i<MAXLINE && line[i] != '\0'; ++i) {
		++line_size;

		if (line[i] == '\n') {
			line_size = 0;
		}

		s[i+added_chars] = line[i];

		if (line_size > columns) {
			++added_chars;
			s[i+added_chars] = '\n';
			line_size = 0;
		}
	}

	s[i+added_chars] = '\0';

	for (i=0; i<MAXLINE; i++) {
		line[i] = s[i];
	}

	return line;
}
