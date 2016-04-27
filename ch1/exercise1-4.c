/*
* Clinton Andrews
* The C Programming Language
* Exercise 1-4
* Write a program to print the corresponding Celsius to Fahrenheit
* table.
*/

#include <stdio.h>

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	// lower limit of temperature table
	upper = 300;	// upper limit
	step = 20;	// step size

	printf("celsius\t  fahr\n");

	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0/5.0) * celsius + 32.0;
		printf("%5.0f\t %4.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
