/* Clinton Andrews
 * 2016-05-30
 *
 * The C Programming Language
 * Exercise 2-10:
 * Rewrite the function lower, which converts upper case
 * to lower case, with a conditional expression instead of 
 * if-else.
 *
 */

#include <stdio.h>

char* lower(char s[]);

main()
{
	char s[] = "ABCD";
	printf("%s\n", lower(s));
}

char* lower(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; ++i) {
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + 32 : s[i];
	}
	return s;
}
