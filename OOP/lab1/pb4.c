/*
When does Easter fall?
Doing the calculation we can determine.
Be aware of the fact what it may occur in March or April, depending on the year.
Year should be larger than 1876.
*/
#include <stdio.h>

int main()
{
    int a, b, c, d, e;
    int year;
    printf("Enter a year: ");
    int result = scanf("%d", &year);
    if (year < 1876 || result == 0)
    {
        printf("Invalid input, the year should be greater or equal to 1876\n");
        return 1;
    }
    a = year % 19;
    b = year % 4;
    c = year % 7;
    d = (a * 19 + 24) % 30;
    e = (2 * b + 4 * c + 6 * d + 5) % 7;
    if (d + e < 10)
        printf("In year %d the Easter is in March %d\n", year, d + e + 22);
    else
        printf("In year %d the Easter is in April %d\n", year, d + e - 9);
    return 0;
}