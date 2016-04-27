/*
* Clinton Andrews
* The C Programming Language
* Exercise 1.2
* Experiment to find out what happens when printf's argument string contains \c, where
* c is some character not listed above. (\t, \b, \", \\)
*/

#include <stdio.h>

main()
{
	printf("hello \n world");
	/* Output:
	   hello 
	   world
	*/

	printf("hello \b world");
	/* Outputs:
	   hello world (note the single backspace instead of 2)
	*/
}
