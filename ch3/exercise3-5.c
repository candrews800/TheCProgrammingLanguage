/* Clinton Andrews
 * 2016-06-06
 *
 * The C Programming Language
 * Exercise 3-5:
 * Write the function itob(n,s,b) that converts the integer
 * n into a base b character representation in the string s.
 * In particular, itob(n,s,16) formats n as a hexadecimal
 * integer in s.
 *
 */

#include <stdio.h>

void itob(int n, char s[], int b);
void string_reverse(char s[]);

main()
{
	char s[] = "123456789";
	string_reverse(s);
	printf("%s\n", s);
	char t[1000];
	itob(1234, t, 16);
	printf("%s\n", t);
}

void itob(int n, char s[], int b)
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		if (n % b > 9) {
			s[i++] = (n % b) - 10 + 'A';
		} else {
			s[i++] = n % b + '0';
		}
	} while ((n /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	string_reverse(s);
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
