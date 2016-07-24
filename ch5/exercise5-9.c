/* Clinton Andrews
 * 2016-07-24
 *
 * The C Programming Language
 * Exercise 5-9:
 * Rewrite the routines day_of_year and month_day with pointers
 * instead of indexing.
 *
 */

#include <stdio.h>

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    char *days;

    if (month < 1 || month > 12) {
        return -1;
    }

    leap = year%4 == 0 && year%100 && year%400 == 0;
    days = *(daytab+leap);

    if (day < 1 || day > daytab[leap][month]) {
        return -1;
    }

    for (i = 1; i < month; i++)
        day += *(days+i);
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year%4 == 0 && year%100 && year%400 == 0;

    if (yearday < 1 || yearday > 365 + leap) {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= *(*(daytab+leap)+i);
    *pmonth = i;
    *pday = yearday;
}

int main()
{
    int day, month, dayOfYear;

    dayOfYear = day_of_year(2016, 7, 24);
    printf("Days in year to 2016-07-24: %d\n", dayOfYear);
    month_day(2016, dayOfYear, &month, &day);
    printf("Day of year %d in the year %d is the month of %d and day %d\n", dayOfYear, 2016, month, day);

    // Try to set invalid day
    dayOfYear = day_of_year(2016, 13, 24);
    printf("Days in year to 2015-13-24: %d\n", dayOfYear);

    // Try to set invalid dayOfYear
    month_day(2016, -1, &month, &day);
    printf("Day of year %d in the year %d is the month of %d and day %d\n", -1, 2016, month, day);

    return 0;
}
