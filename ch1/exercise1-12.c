/* Clinton Andrews
 * 2016-04-30
 *
 * The C Programming Language
 * Exercise 1-12:
 * Write a program that prints its input one line at a time. 
 *
 */

#include <stdio.h>

#define	IN	1
#define OUT	0

main()
{
	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			putchar('\n');
			putchar(c);
		} else if (state == IN)
			putchar(c);
	}
}
