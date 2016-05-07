/* Clinton Andrews
 * 2016-06-05
 *
 * The C Programming Language
 * Exercise 1-23:
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants 
 * properly. C comments do not nest.
 *
 */

#include <stdio.h>

main()
{
	int c, last_c = getchar();

	int MULTI = 0, SINGLE = 0, QUOTE = 0, IGNORE = 0;

	while ((c = getchar()) != EOF) {
		if (last_c == '/' && c == '*' && !SINGLE && !QUOTE)
			MULTI = 1;
		else if (last_c == '/' && c == '/' && !MULTI && !QUOTE)
			SINGLE = 1;
		else if (last_c == '"' && !SINGLE && !MULTI && c != '\'')
			QUOTE = !QUOTE;


		if (last_c == '\n' && !MULTI) {
			SINGLE = 0;
			QUOTE = 0;
			putchar(last_c);
		}
		else if (MULTI && last_c == '*' && c == '/') {
			MULTI = 0;
			IGNORE = 1;
		}
		else if (!SINGLE && !MULTI && !IGNORE)
			putchar(last_c);
		else if (IGNORE)
			IGNORE = 0;

		last_c = c;
	}
}
