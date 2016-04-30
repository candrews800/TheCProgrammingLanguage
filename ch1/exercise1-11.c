/* Clinton Andrews
 * 2016-04-29
 *
 * The C Programming Language
 * Exercise 1-11:
 * How would you test the word count program? What kinds of input are
 * most likely to uncover bugs if there are any?
 *
 * A: Pass in a file with a known amount of words, characters, lines by piping 
 * them in such as with cat known.txt | ./a.out
 * Potential bugs here: This program will count non word characters like dashes
 * as words.
 */

#include <stdio.h>

#define	IN	1
#define OUT	0

main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}

	printf("%d %d %d\n", nl, nw, nc);
}
