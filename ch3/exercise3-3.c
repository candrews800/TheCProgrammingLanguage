/* Clinton Andrews
 * 2016-06-02
 *
 * The C Programming Language
 * Exercise 3-3:
 * Write a function expand(s1,s2) that expands shorthand notations
 * like a-z in the string s1 into the equivalent complete list 
 * abc..xyz in s2. Allow for letters of either case and digits, and
 * be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
 * that a leading or trailing - is taken literally.
 *
 */

#include <stdio.h>

void expand(char s1[], char s2[]);

main()
{
	char s[1000];
	expand("a-z", s);
	printf("a-z: %s\n", s);
	expand("A-Z", s);
	printf("A-Z: %s\n", s);
	expand("-a-z", s);
	printf("-a-z: %s\n", s);
	expand("0-9", s);
	printf("0-9: %s\n", s);
	expand("a-z0-9", s);
	printf("a-z0-9: %s\n", s);
}

void expand(char s1[], char s2[])
{
	char sign = '\0';
	if (s1[0] == '-')
		sign = '-';

	/* Check if string can be expanded */
	if ((sign == '-' && s1[2] != '-')
            || (sign == '\0' && s1[1] != '-')) {
		s2 = s1;
		return;
	}

	int i, j, a = sign == '\0' ? 0 : 1;
	
	if (s1[0+a] >= s1[2+a]) {
		s2 = s1;
		return;
	}

	if (sign != '\0')
		s2[0] = sign;
	for (i = 0; s1[a] + i <= s1[2+a]; ++i) {
		s2[i+a] = (s1[a] + i);
	}

	if (s1[3+a] == '\0' || s1[4+a] != '-' || s1[5+a] == '\0' || s1[3+a] >= s1[5+a]) {
		s2[i+a] = '\0';
		return;
	} 

	for (j = 0;s1[3+a] + j <= s1[5+a]; ++j, ++i) {
		s2[i+a] = (s1[3+a] + j);
	}
	s2[i+a] = '\0';
}
