/* Clinton Andrews
 * 2016-04-28
 *
 * The C Programming Language
 * Exercise 1-10:
 * Write a program to copy its input to its output, replacing each
 * tab by \t, each backspace by \b, and each backslack by \\. This makes tabs
 * and backspace visible in an unambiguous way.
 *
 */

#include <stdio.h>

main()
{
	char c;

	while ((c = getchar()) != EOF) {
		if (c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}
}
