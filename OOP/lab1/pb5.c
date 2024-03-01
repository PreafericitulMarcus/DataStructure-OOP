/*
This is Cezars cipher.
The user gives a natural number and a text.
The program will display the encrypted text by subtracting the number, given, from each character.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char s[256];
    printf("Enter a natural number: ");
    int result_n = scanf("%d", &n);
    if (result_n == 0 || n < 0)
    {
        printf("Invalid input, the number should be a natural number\n");
        return 1;
    }
    n++;
    printf("Enter a string: ");
    getchar();               // consume newline character left by scanf
    fgets(s, 256, stdin);    // use fgets to read a line of text
    s[strcspn(s, "\n")] = 0; // remove newline character at the end of the string

    for (int i = 0; i <= strlen(s); i++)
    {
        // Upper character
        if (s[i] >= 'A' && s[i] <= 'Z')
            if (s[i] - n + 1 < 'A')
                printf("%c", 26 - (n - s[i]) + 1);
            else
                printf("%c", s[i] - n + 1);
        // Lower character
        else if (s[i] >= 'a' && s[i] <= 'z')
            if (s[i] - n + 1 < 'a')
                printf("%c", 26 - (n - s[i]) + 1);
            else
                printf("%c", s[i] - n + 1);
        else
            printf("%c", s[i]);
    }
    return 0;
}