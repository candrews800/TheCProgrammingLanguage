/* Clinton Andrews
 * 2016-05-11
 *
 * The C Programming Language
 * Exercise 2-2:
 * Write a loop equivalent to the foot loop above without using && or ||.
 *
 * loop:
 * for (i=0; i<lim-1 && (c=getchar()) !=  '\n' && c != EOF; ++i)
 * 	s[i] = c;
 *
 */

#include <stdio.h>

main()
{
	int i, lim = 1000;
	char c, s[lim];

	for (i=0; i<lim-1; ++i) {
		c = getchar();
		if (c == '\n')
			break;
		if (c == EOF)
			break;
		s[i] = c;
	}
}
