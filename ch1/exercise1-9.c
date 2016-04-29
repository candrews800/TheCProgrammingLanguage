/* Clinton Andrews
 * 2016-04-28
 *
 * The C Programming Language
 * Exercise 1-9:
 * Write a program to copy its input to its output, replacing each
 * string of one or more blanks by a single blank.
 *
 */

// Example    Text     Here

#include <stdio.h>

main()
{
	char c, prev_c;

	while ((c = getchar()) != EOF) {
		if (c != ' ' || prev_c != ' ') {
			putchar(c);
		}
		prev_c = c;
	}
}
