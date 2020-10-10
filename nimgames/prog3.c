/*
Assignment 2, Program 3: Longest Increasing Sequence
Name: Subrat Prasad Panda
Roll: CS1913
*/

#include <stdio.h>

int max(int i, int j){
    if(i > j)
        return i;
    else
        return j;
}

int main()
{
    int n;
    printf("Enter number of integers: ");
    scanf("%d", &n);
    int seq[n]; // integer sequence
    int LIS[n], len = 0, min_change;

    printf("Enter Sequence: ");
    for(int i=0; i<n; i++)
        scanf("%d", &seq[i]);

    // Mark all elements of Longest Increasing Sequence
    for (int i = 0; i < n; i++)
        LIS[i] = 1;

    // Find longest increasing sequence of array
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (seq[i] > seq[j] && (i - j) <= (seq[i] - seq[j])) // (i-j) part validates there are possibility of changing a number
            {
                LIS[i] = max(LIS[i], LIS[j] + 1); //update only maximum value
            }
        }
        len = max(len, LIS[i]); //maximum term in array
    }

    min_change = n - len;
    printf("\nMin number of changes: %d\n", min_change);
    return 0;
}
