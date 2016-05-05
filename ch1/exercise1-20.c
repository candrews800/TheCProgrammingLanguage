/* Clinton Andrews
 * 2016-05-03\4
 *
 * The C Programming Language
 * Exercise 1-20:
 * Write a program detab tha replaces tabs in the input with the proper
 * number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter?
 * Answer: Variable, since you can change this with input args
 *
 */

#include <stdio.h>

main()
{
	int SPACES = 8;

	int c, i, nt = SPACES;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (i=0;i<nt;++i)
				putchar(' ');

			nt = SPACES;
		} else if (c == '\n') {
			nt = SPACES;
			putchar(c);
		} else {
			nt = --nt == 0 ? SPACES : nt;
			putchar(c);
		}
	}
}
