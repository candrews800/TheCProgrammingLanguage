/* Clinton Andrews
 * 2016-05-30
 *
 * The C Programming Language
 * Exercise 2-5:
 * Write the function any(s1,s2) which returns the first location in the
 * string s1 where any character from the string s2 occurs, or -1 if s1
 * contains no characters from s2. (The standard library function strpbrk
 * does the same job but returns a pointer to the location.)
 *
 */

#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);

main()
{
	char s1[] = "abcdefg";
	printf("%d: should be -1\n", any(s1, "h"));
	printf("%d: should be 0\n", any(s1, "a"));
	printf("%d: should be 2\n", any(s1, "c"));

	char* l = strpbrk(s1, "c");
	printf("%c: should be c\n", *l);
}

int any(char s1[], char s2[])
{
	int i, j;
	for (i = 0; s1[i] != '\0'; ++i) {
		for (j = 0; s2[j] != '\0'; ++j) {
			if (s1[i] == s2[j]) {
				return i;
			}
		}
	}
	return -1;
}
