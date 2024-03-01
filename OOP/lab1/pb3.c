/* Determines the number of 1s in binary representation of n
n is natural number
*/
#include <stdio.h>

int main()
{
    int n, counter = 0;
    printf("Enter a natural number: ");
    int result = scanf("%d", &n);
    if (result == 0 || n < 0)
    {
        printf("Invalid input. Please try again\n");
        return 1;
    }
    while (n != 0)
    {
        counter += n % 2;
        n /= 2;
    }
    printf("The number of 1s in the binary representation of n is: %d\n", counter);
    return 0;
}