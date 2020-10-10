/*
Assignment 2, Program 1: Subtraction Nim Game.
Name: Subrat Prasad Panda
Roll: CS1913
*/


#include <stdio.h>


int main(){
    int n, m; //n-total balls; m-max limit
    int u, c; //u-user; c-computer
    printf("#balls and max-limit: ");
    scanf("%d %d", &n, &m);

    printf("n: %d, m: %d\n", n, m);

    while( n > 0){
        printf("user: ");
        scanf("%d", &u);

        n = n - u;
        if (n == 0){
            printf("computer: FAIL >>>>>>>>BALLS LEFT: %d\n", n);
            printf("\n>>>>>>>>NO<<<<<<<<<\n");
            break;
        }
        
        c = n%(m+1);
        if (c == 0) c = 1;
        n = n - c;
        printf("computer: %d >>>>>>>BALLS LEFT: %d\n", c, n);
        if (n == 0)
        {
            printf("\n>>>>>>>>YES<<<<<<<<<\n");
            break;
        }
        
    }
    return 0;

}