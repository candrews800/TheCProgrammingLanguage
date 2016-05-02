/* Clinton Andrews
 * Date Created
 *
 * The C Programming Language
 * Exercise 1-13:
 * Write a program to print a histogram of the lengths of words in
 * its input. It is easy to draw the histogram with the bars horizontal;
 * a verical orientation is more challenging.
 *
 */

#include <stdio.h>

#define POSSIBLE_CHARS 256

main()
{
	int c, i, j, mc = 0;

	int cc[POSSIBLE_CHARS];
	for (i = 0; i < POSSIBLE_CHARS; ++i)
		cc[i] = 0;

	while ((c = getchar()) != EOF)
		++cc[c];

	mc = 0;
	for (i = 0; i < POSSIBLE_CHARS; i++)
		if (cc[i] > mc) 
			mc = cc[i];

	float step = mc / 5.0;
        int width = 0;
        printf("    0");
        for (i = 1; i < 25; i++) {
                if (i % 5 == 0) {
                        int step_i = step * i / 5;
                        if (step_i == (step-0.5) / (i/5)) {
                                printf("%d", 1 + step_i);
                        } else {
                                printf("%d", step_i);
                        }

                        ++width;
                        while (step_i > 0) {
                                step_i = step_i / 10;
                                ++width;
                        }
                } else {
                        printf(" ");
                        ++width;
                }
        }
        printf("%d\n", mc);

        for (i = 0; i < POSSIBLE_CHARS; i++) {
                if (cc[i] > 0 && i >= ' '){
			printf("%c   ", i);
                        for (j = 1; j < width; j++) {
                                if ( (float) j / width < (float) cc[i] / mc) {
                                        printf("#");
                                }
                        }
                        printf("\n");
                }
        }

}
