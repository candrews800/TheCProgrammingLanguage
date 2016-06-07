/* Clinton Andrews
 * 2016-06-06
 *
 * The C Programming Language
 * Exercise 3-4:
 * In a two's complement number representation, our version of 
 * itoa does not handle the largest negative number, that is,
 * the value of n equal to -2^(wordsize-1). Explain why not.
 * Modify it to print that value correctly, regardless of the
 * machine on which it runs.
 *
 * Response: When reversing n in the statement:
 * n = -n
 * the n is reversed to 2^(wordsize-1) which is greater than the 
 * max interger of 2^(wordsize-1) - 1
 */

#include <stdio.h>

void itoa(int n, char s[]);

main()
{

}

void itoa(int n, char s[])
{
	int i, sign;
	long num = n;
	if ((sign = num) < 0) 
		num = -n;
	i = 0;
	do {
		s[i++] = num % 10 + '0';
	} while ((num /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
