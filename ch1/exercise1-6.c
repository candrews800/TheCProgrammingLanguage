/* Clinton Andrews
 * 2016-04-28
 *
 * The C Programming Language
 * Exercise 1-6:
 * Verify that the expression getchar() != EOF is 0 or 1.
 *
 */

#include <stdio.h>

main()
{
	int c;
	while ((c = getchar()) != EOF)
		putchar(c);

	putchar(c);
}
