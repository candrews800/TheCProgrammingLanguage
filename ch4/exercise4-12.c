/* Clinton Andrews
 * 2016-06-16
 *
 * The C Programming Language
 * Exercise 4-12:
 * Adapt the ideas of printd to write a recursive version of itoa;
 * that is, convert an integer into a string by calling a recursive
 * string.
 *
 */

#include <stdio.h>
#include <string.h>

void reverse(char[]);
void itoa(int, char[]);
void itoar(int, char[]);

main()
{
	int i = 120;
	char s[1000];
	itoa(i, s);
	printf("%s\n", s);

	i = 123;
	itoar(i, s);
	printf("%s\n", s);
}

/* reverse:  reverse string s in place */
void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)	/* record sign */
		n = -n;		/* make n positive */
	i = 0;
	do {
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* itoar: convert n to characters in s, recursively */
void itoar(int n, char s[])
{
	static int i;

	if (n / 10)
		itoar(n/10, s);
	else {
		i = 0;
		if (n < 0) {
			s[i++] = '-';
			n = -n;
		}
	}

	s[i++] = n % 10 + '0';
	s[i] = '\0';
}
