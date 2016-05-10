/* Clinton Andrews
 * 2016-05-08
 *
 * The C Programming Language
 * Exercise 2-1:
 * Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing
 * appropriate values frm standard headers and by direct computation.
 * Harder if you compute them: determine the various floating-point types.
 *
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

main()
{
	printf("Limits found in <limits.h>\n");
	printf("(CHAR_BIT)\tBits in a char:\t\t%d\n", CHAR_BIT);
	printf("(CHAR_MAX)\tMaximum value of char:\t%d\n", CHAR_MAX);
	printf("(CHAR_MIN)\tMinimum value of char:\t%d\n", CHAR_MIN);
	printf("(INT_MAX)\tMaximum value of int:\t%d\n", INT_MAX);
        printf("(INT_MIN)\tMinimum value of int:\t%d\n", INT_MIN);
	printf("(LONG_MAX)\tMaximum value of long:\t%li\n", LONG_MAX);
        printf("(LONG_MIN)\tMinimum value of long:\t%li\n", LONG_MIN);
	printf("(SCHAR_MAX)\tMaximum value of signed char:\t%d\n", SCHAR_MAX);
        printf("(SCHAR_MIN)\tMinimum value of signed char:\t%d\n", SCHAR_MIN);
	printf("(SHRT_MAX)\tMaximum value of short:\t%d\n", SHRT_MAX);
        printf("(SHRT_MIN)\tMinimum value of short:\t%d\n", SHRT_MIN);
	printf("(UCHAR_MAX)\tMaximum value of unsigned char:\t%d\n", UCHAR_MAX);
	printf("(UINT_MAX)\tMaximum value of unsigned int:\t%d\n", UINT_MAX);
	printf("(ULONG_MAX)\tMaximum value of unsigned long:\t%li\n", ULONG_MAX);
	printf("(USHRT_MAX)\tMaximum value of unsigned short:\t%d\n\n", USHRT_MAX);

	printf("(FLT_RADIX)\tRadix of exponent representation:\t%d\n", FLT_RADIX);
	printf("(FLT_ROUNDS)\tFloating point rounding mode for addition:\t%d\n", FLT_ROUNDS);
	printf("(FLT_DIG)\tDecimal digits of precision:\t%d\n", FLT_DIG);
	printf("(FLT_EPSILON)\tSmallest number x such that 1.0+x doesnt equal 1.0:\t%f\n", FLT_EPSILON);
	printf("(FLT_MANT_DIG)\tNumber of base FLT_RADIX digits in mantissa:\t%d\n", FLT_MANT_DIG);
	printf("(FLT_MAX)\tMaximum floating-point number:\t%f\n", FLT_MAX);
	printf("(FLT_MAX_EXP)\tMaximum n such that FLT_RADIX^n-1 is representable:\t%d\n", FLT_MAX_EXP);
	printf("(FLT_MIN)\tMinimum normalized floating-point number:\t%f\n", FLT_MIN);
	printf("(FLT_MIN_EXP)\tMinimum n such that 10^n is a normalized number:\t%d\n", FLT_MIN_EXP);
	printf("(DBL_DIG)\tDecimal digits of precision:\t%d\n", DBL_DIG);
	printf("(DBL_EPSILON)\tSmallest number x such that 1.0+x does not equal 1.0:\t%f\n", DBL_EPSILON);
	printf("(DBL_MANT_DIG)\tNumber of base FLT_RADIX digits in mantissa:\t%d\n", DBL_MANT_DIG);
	printf("(DBL_MAX)\tMaximum double floating-point number:\t%f\n", DBL_MAX);
	printf("(DBL_MAX_EXP)\tMaximum n such that FLT_RADIX^n-1 is representable:\t%d\n", DBL_MAX_EXP);
	printf("(DBL_MIN)\tMinimum normalized double floating-point number:\t%f\n", DBL_MIN);
	printf("(DBL_MIN_EXP)\tMinimum n such that 10^n is a normalized number:\t%d\n", DBL_MIN_EXP);

}
