/* Clinton Andrews
 * 2016-06-08
 *
 * The C Programming Language
 * Exercise 4-2:
 * Extend atof to handle scientific notation of the form
 * 	123.45e-6
 * where a floating point number may be followed by e or E
 * and an optionally signed exponent.
 *
 */

#include <stdio.h>
#include <math.h>
#include "../utility.h"

#define MAXLINE 100

double atof(char[]);

/* rudimentary calculator */
main()
{
	double sum;
	char line[MAXLINE];

	while (mgetline(line, MAXLINE) > 0)
		printf("%g\n", atof(line));
	return 0;	
}

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)
		; // skip white space
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	
	val = sign * val / power;
	
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		sign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		if (isdigit(s[i])) {
			power = s[i] - '0';
			i++;
		}
		for (power; isdigit(s[i]); i++)
			power = 10.0 * power + (s[i] - '0');

		power *= sign;
		power = pow(10, power);
		val *= power;
	}

	return val;
}
