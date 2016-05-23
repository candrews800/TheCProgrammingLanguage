/* Clinton Andrews
 * 2016-05-22
 *
 * The C Programming Language
 * Exercise 2-3:
 * Write a function htoi(s), which converts a string of hexa-
 * decimal digits (including an option 0x or 0X) into its equivalent
 * integer value. The allowable digits are 0 through 9, a through f,
 * and A through F.
 *
 */

#include <stdio.h>
#include <string.h>

int htoi(char[]);
int hexValue(char);

main()
{
	printf("0xC8:\t\t%d\n", htoi("0xC8")); 		// 200
	printf("c8:\t\t%d\n", htoi("c8")); 		// 200
	printf("0X15B3:\t\t%d\n", htoi("0X15B3"));	// 5,555
	printf("0x19CBD2:\t%d\n", htoi("0x19CBD2"));	// 1,690,578
}

int htoi(char s[])
{
	int start = 0,
	    d = 0,
	    i = 0,
	    size = strlen(s);

	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		start = 2;

	for (i = start; i < size; ++i) {
		d = d * 16;
		d = d + hexValue(s[i]);
	}

	return d;
}

int hexValue(char s)
{
	if (s >= '0' && s <= '9')
		return s - '0';

	switch (s) {
		case 'a':
		case 'A':
			return 10;
		case 'b':
		case 'B':
			return 11;
		case 'c':
		case 'C':
			return 12;
		case 'd':
		case 'D':
			return 13;
		case 'e':
		case 'E':
			return 14;
		case 'f':
		case 'F':
			return 15;
	}
	return -1;
}
