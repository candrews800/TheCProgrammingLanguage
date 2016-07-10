/* Clinton Andrews
 * 2016-07-09
 *
 * The C Programming Language
 * Exercise 5-2:
 * Write getfloat, the floating-point analog of getint. What
 * type does getfloat return as its function value?
 * A: int, the return value is used as a status code, not as 
 * what was translated.
 *
 */

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE	100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getfloat(float *);
int getch(void);
void ungetch(int);

main()
{
	float c;
	int i = getfloat(&c);
	printf("%c\n", i);
	printf("%f\n", c);
	printf("%f\n", c + 2.0);
	printf("%c\n", getch());
}

/* getfloat: get next float from input into *pn */
int getfloat(float *pn)
{
	int c, sign, dec, t;

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
	if(c == '.') {
		c = getch();
		t = 1;
		for (dec = 0; isdigit(c); c = getch()) {
			dec = 10 * dec + (c - '0');
			t*= 10;
		}
		*pn += (float)dec / t;
	}
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

