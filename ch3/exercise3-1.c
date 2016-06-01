/* Clinton Andrews
 * 2016-05-31
 *
 * The C Programming Language
 * Exercise 3-1:
 * Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a
 * version with only one test inside the loop and measure the 
 * difference in run time.
 *
 */

#include <stdio.h>
#include <time.h>

const int ARR_SIZE = 1000000;
const int SEARCH_TERM = 123417;

int binsearch(int x, int v[], int n);
int mybinsearch(int x, int v[], int n);

main()
{
	int i, v, l[ARR_SIZE];
	for (i=0;i<ARR_SIZE;++i)
		l[i]=i;

	clock_t tStart, tEnd;
	tStart = clock();
	v = binsearch(SEARCH_TERM, l, ARR_SIZE);
	tEnd = clock();
	printf("Found %d at position %d in %f clock cycles.\n", SEARCH_TERM, v, (double)(tEnd - tStart));

	tStart = clock();
	v = mybinsearch(SEARCH_TERM, l, ARR_SIZE);
	tEnd = clock();
	printf("Found %d at position %d in %f clock cycles.\n", SEARCH_TERM, v, (double)(tEnd - tStart));
}

/* binsearch: find x in v[0] <= ... <= v[n-1] */
int binsearch(int x, int vp[], int n)
{
	int low, high, mid;

	low = 0;
	high = n-1;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < vp[mid])
			high = mid - 1;
		else if (x > vp[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1; // no match
}

int mybinsearch(int x, int vp[], int n)
{
	int low, high, mid;
	low = 0;
	high = n-1;
	mid = (high+low) / 2;
	while (low <= high && x != vp[mid]) {
		if (x < vp[mid])
			high = mid - 1;
		else
			low = mid + 1;
		mid = (high+low)/2;
	}
	if (x == vp[mid])
		return mid;
	return -1;
}
