/* Clinton Andrews
 * Date Created
 *
 * The C Programming Language
 * Exercise 2-4:
 * Write an alternate version of squeeze(s1,s2) that deletes
 * each character in s1 that matches any character in string s2.
 *
 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

main()
{
	char s[] = "A Test String";
	squeeze(s, " ASster");
	printf("%s\n", s);
}

void squeeze(char s1[], char s2[])
{
	int i, j, k, contains;
	for (i = j = 0; s1[i] != '\0'; ++i) {
		contains = 0;
		for (k = 0; s2[k] != '\0'; ++k) {
			if (s1[i] == s2[k]) {
				contains = 1;
			}
		}
		if (!contains) {
			s1[j] = s1[i];
			++j;
		}
	}
	s1[j] = '\0';
}
