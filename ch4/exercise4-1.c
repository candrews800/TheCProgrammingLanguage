/* Clinton Andrews
 * 2016-06-07
 *
 * The C Programming Language
 * Exercise 4-1:
 * Write the function strrindex(s,t), which returns the position
 * of the rightmost occurrence of t in s or -1 if there is none.
 *
 */

#include <stdio.h>

int strrindex(char s[], char t[]);

main()
{
	char s[] = "Sample test string";
	printf("\"%s\": amp position: %d\n", s, strrindex(s, "amp"));
	printf("\"%s\": qwe position: %d\n", s, strrindex(s, "qwe"));
	printf("\"%s\": string position: %d\n", s, strrindex(s, "string"));
	printf("\"%s\": g position: %d\n", s, strrindex(s, "g"));
}

int strrindex(char s[], char t[])
{
	int i, j, k;
	char c;

	// Get to end of s
	for (i = 0; s[i] != '\0'; ++i)
		;

	for (--i; i >= 0; --i) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}

	return -1;
}
