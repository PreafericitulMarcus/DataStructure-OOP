/* We need a 4-digit code such that the sum of each number is 24 */
#include <stdio.h>

int main()
{
    int sum = 24;
    for (int i = 9; i >= 0; i--)
        for (int j = 9; j >= 0; j--)
            for (int k = 9; k >= 0; k--)
                if (sum - i - j - k == 0)
                    printf("%d%d%d%d\n", i, j, k, sum - i - j - k);
    return 0;
}