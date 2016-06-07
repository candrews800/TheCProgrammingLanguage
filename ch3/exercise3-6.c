/* Clinton Andrews
 * 2016-06-06
 *
 * The C Programming Language
 * Exercise 3-6:
 * Write a version of itoa tha accepts three arguments instead of two.
 * The third argument is a minimum field width; the converted number
 * must be padded with blankes on the left if necessary to make it
 * wide enough.
 *
 */

#include <stdio.h>

void itoa(int n, char s[], int lp);
void string_reverse(char s[]);
void lpad(char s[], int n);

main()
{
	char s[] = "12345678";
	string_reverse(s);
	printf("%s\n", s);
	char t[1000];
	itoa(123456789, t, 8);
	printf("%s\n", t);
}

void itoa(int n, char s[], int lp)
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	string_reverse(s);
	lpad(s, lp);
}

void string_reverse(char s[]) {
	int i = 0, n;
	while (s[i] != '\0')
		i++;
	n = i;
	char tmp;
	for (i=0; i<n/2; ++i) {
		tmp = s[i];
		s[i] = s[n-i-1];
		s[n-i-1] = tmp;
	}
	s[n] = '\0';
}

void lpad(char s[], int n) {
	int i = 0, size;
	while (s[i] != '\0')
		++i;
	size = i;

	if (size >= n)
		return;

	for (i=size-1; i >=0; --i)
		s[i+(n-size)] = s[i];

	for (i=0; i < (n-size); ++i)
		s[i] = '0';

	s[n] = '\0';
}
