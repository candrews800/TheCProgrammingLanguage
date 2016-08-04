/* Clinton Andrews
 * 08-03-2016
 *
 * The C Programming Language
 * Exercise 5-10:
 * Write the program expr, which evaluates a reverse Polish
 * expression from the command line, where each operator
 * or operand is a separate argument. For example:
 *
 *  expr 2 3 4 + *
 *
 *  evaulates 2 x (3+4).
 *
 */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define NUMBER	'0'

double evaluate(int argc, char *argv[]);
int getTop(char *);
void push(double);
double pop();

double stack[1000];
int size = 0;

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        printf("No input given\n");
        return 0;
    }

    double i = evaluate(argc, argv);

    if (size > 0) {
        printf("Could not process all elements");
        return -1;
    }

    printf("%.8g\n", i);

    return 0;
}

double evaluate(int argc, char **argv)
{
    int type;
    double op;

    // Iterate over arguments
    while (--argc && ++argv) {
        switch(type = getTop(*argv)) {
            case '+':
                op = pop();
                push(op + pop());
                break;
            case '-':
                op = pop();
                push(pop() - op);
                break;
            case 'x':
                op = pop();
                push(op * pop());
                break;
            case '/':
                op = pop();
                push(pop() / op);
                break;
            case NUMBER:
                push(atof(*argv));
                break;
        }
    }

    return pop();
}

int getTop(char *str)
{
    if (!isdigit(*str) && str[0] != '.' && str[0] != '-')
        return str[0];	/* not a number */
    if (str[0] == '-') {
        if (!isdigit(str[1]) && str[1] != '.')
            return str[0]; /* not a number */
    }

    return NUMBER;
}

void push(double i) {
    stack[size++] = i;
}

double pop()
{
    if (size == 0) {
        printf("At end of stack. No more items to pop()");
    }

    return stack[--size];
}