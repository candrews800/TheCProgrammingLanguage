/* Clinton Andrews
 * 2016-06-16
 *
 * The C Programming Language
 * Exercise 4-14:
 * Define a macro swap(t,x,y) that interchanges two
 * arguments of type t. (Block structure will help.)
 *
 */

#include <stdio.h>

#define swap(t,x,y) 	\
	do {		\
	t _i = y;	\
	y = x; 		\
	x = _i;		\
	} while (0);	// Need do/while for scope

main()
{
	int i = 1;
	int j = 2;

	printf("%d - %d\n", i, j);
	swap(int, i, j);
	printf("%d - %d\n", i, j);

	double q = 1.0;
	double w = 2.0;
	printf("%f - %f\n", q, w);
	swap(double, q, w);
	printf("%f - %f\n", q, w);
}
