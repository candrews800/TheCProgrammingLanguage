/* Clinton Andrews
 * 2016-04-28
 *
 * The C Programming Language
 * Exercise 1-8:
 * Write a program to count blanks, tabs, and newlines.
 *
 */

#include <stdio.h>

main()
{
	int nb = 0, nt = 0, nl = 0;
	char c;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nl;
	}

	printf("Blanks: %d\n", nb);
	printf("Tabs: %d\n", nt);
	printf("Newlines: %d\n", nl);
}
