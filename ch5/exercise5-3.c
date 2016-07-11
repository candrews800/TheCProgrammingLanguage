/* Clinton Andrews
 * 2016-07-10
 *
 * The C Programming Language
 * Exercise 5-3:
 * Write a pointer version of the function strcat that
 * we showed in Chapter 2: strcat(s,t) copes the string
 * t to the end of s.
 *
 */

#include <stdio.h>

void mystrcat(char *, char *);

main()
{
	char s[] = "Hello";
	char t[] = " There";
	mystrcat(s, t);
	printf("%s\n", s);
}

void mystrcat(char *s, char *t)
{
	while (*s != '\0')
		s++;
	while (*s++ = *t++)
		;
}
