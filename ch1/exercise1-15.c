/*
* Clinton Andrews
* The C Programming Language
* Exercise 1-3
* Modify the temperature conversion program to print a heading
* shown above the table.
*/

#include <stdio.h>

float ftoc(float fahr);

main()
{
	float fahr;
	int lower, upper, step;

	lower = 0;	// lower limit of temperature table
	upper = 300;	// upper limit
	step = 20;	// step size

	printf("fahr celsius\n");

	fahr = lower;
	while (fahr <= upper) {
		printf("%3.0f %6.1f\n", fahr, ftoc(fahr));
		fahr = fahr + step;
	}
}

float ftoc(float fahr) {
	return (5.0/9.0) * (fahr - 32.0);
}
