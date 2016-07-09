/* Clinton Andrews
 * 2016-07-08
 *
 * The C Programming Language
 * Exercise 5-1:
 * As written, getint treats + or - not followed by a digit as a 
 * valid representation of zero. Fix it to push such a character
 * back onto the input.
 *
 */

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE	100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getint(int *);
int getch(void);
void ungetch(int);

main()
{
	int c;
	int i = getint(&c);
	printf("%c\n", i);
	printf("%d\n", c);
	printf("%c\n", getch());
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
		if (!isdigit(c)) {
			ungetch(c);
			return 0;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

int getch(void) /* get a (possibily pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

