/*Simple program
ask the user for name and year.
validate the input
display the input */
#include <stdio.h>

int main()
{
    int birth_year;
    char name[20];
    printf("What is your name? ");
    while (scanf("%s", name) != 1)
    {
        printf("Invalid input. Please enter your name: ");
        fflush(stdin);
    }
    printf("What is your birth year? ");
    while (scanf("%d", &birth_year) != 1)
    {
        printf("Invalid input. Please enter your birth year: ");
        fflush(stdin);
    }
    printf("Hello, %s! You have been born in %d.\n", name, birth_year);
    return 0;
}