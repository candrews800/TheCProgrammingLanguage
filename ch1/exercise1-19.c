/* Clinton Andrews
 * 2016-05-03
 *
 * The C Programming Language
 * Exercise 1-19:
 * Write a function reverse(s) that reverses the character string
 * s. Use it to write a program that receives its input a line at a time.
 *
 */

#include <stdio.h>
#define MAXLINE	1000
#define MAX 80

int _getline(char line[], int lim);
char* reverse(char s[], int length);

main()
{
	int length;
	char line[MAXLINE];

	while ((length = _getline(line, MAXLINE)) > 0)
		printf("%s", reverse(line, length-1));
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

char* reverse(char s[], int length) {
	char cp[length];
	int i;

	for (i = 0; i < length; ++i)
		cp[i] = s[i];

	for (i = 0; i < length; ++i)
		s[i] = cp[length-i-1];

	return s;
}
