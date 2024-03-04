#include <stdio.h>

long long max_triplet(int arr[], unsigned int st, int *t1, int *t2, int *t3)
{
    *t1 = *t2 = *t3 = 0;
    int max = arr[0], min = arr[0];
    int *mt1, *mt2;
    *mt1 = *mt2 = 0;
    for (int i = 0; i < st; i++)
    {
        // max 3 values
        if (arr[i] > max)
        {
            *t3 = *t2;
            *t2 = *t1;
            *t1 = arr[i];
            max = arr[i];
        }
        else if (arr[i] > *t2)
        {
            *t3 = *t2;
            *t2 = arr[i];
        }
        else if (arr[i] > *t3)
        {
            *t3 = arr[i];
        }

        // min 2 values
        if (arr[i] < 0)
        {
            if (arr[i] <= min)
            {
                *mt2 = *mt1;
                *mt1 = arr[i];
                min = arr[i];
            }
            else if (arr[i] < *mt2)
            {
                *mt2 = arr[i];
            }
        }
    }
    long long a = (*t1 * *t2 * *t3), b = (*t1 * *mt1 * *mt2);
    return a > b ? a : b;
}

int main()
{
    int arr[5] = {-3, 10, 200, 4, -900};
    unsigned int st = 5;
    int *t1, *t2, *t3;
    printf("\nThe produce of the triplets is: %lld", max_triplet(arr, st, &t1, &t2, &t3));
    return 0;
}