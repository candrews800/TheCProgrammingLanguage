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

#define IN 	1
#define OUT	0
#define LARGEST_WORD 20

main()
{
	int c, i, j, nc, largest_input, state;
	nc = 0;

	int wc[LARGEST_WORD+1];
	for (i = 0; i < LARGEST_WORD+1; ++i) {
		wc[i] = 0;
	}

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == '\t' || c == ' ') {
			state = OUT;
			if (nc > largest_input) {
				largest_input = nc;
			}

			if (nc > LARGEST_WORD) {
				largest_input = LARGEST_WORD;
				++wc[LARGEST_WORD-1];
				nc = 0;
			} else if (nc > 0) {
				++wc[nc];
				nc = 0;
			}
		} else {
			++nc;
		}
	}

	int mc = 0;
	for (i = 0; i < LARGEST_WORD+1; i++) {
		if (wc[i] > mc)
			mc = wc[i];
	}

	float step = mc / 5.0;
	int width = 0;
	printf("max 0");
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

	for (i = 0; i < LARGEST_WORD+1; i++) {
		if (wc[i] > 0){
			printf("%3d ", i);
			for (j = 1; j < width; j++) {
				if ( (float) j / width <= (float) wc[i] / mc) {
					printf("#");
				}
			}
			printf("\n");
		}
	}
}
