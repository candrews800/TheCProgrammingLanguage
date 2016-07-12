/* Clinton Andrews
 * 2016-07-11
 *
 * The C Programming Language
 * Exercise 5-4:
 * Write the function strend(s,t), which returns 1 if the
 * string t occurs at the end of the string s, and zero
 * otherwise.
 *
 */

#include <stdio.h>

int strend(char *, char *);
int strcmp(char *, char *);

main()
{
	char s[] = "Hello";
	char t[] = "llo";
	printf("%d\n", strend(s, t));
	char u[] = "123";
	printf("%d\n", strend(s, u));
	char v[] = "o";
	printf("%d\n", strend(s, v));
}

int strend(char *s, char *t)
{
	char *sInitial = s;
	char *tInitial = t;

	while (*s != '\0')
		s++;
	while (*t != '\0')
		t++;

	while (s != sInitial && *s == *t) {
		if (t == tInitial)
			return 1;
		s--;
		t--;
	}
	return 0;
}
