/*
Assignment 2, Program 2: Bounded NIM game.
Name: Subrat Prasad Panda
Roll: CS1913
*/


#include <stdio.h>

//Global Varibles
int u[2], c[2];    //u-user; c-computer

// Sum of balls in all bins
int sum(int n[], int k){
    int sum =0;
    for(int i=0; i<k; i++)
        sum = sum + n[i];
    return sum;
}


//nim sum calculation
int nimsum(int n[], int m[], int k)
{
    int nimsum = n[0]%( m[0]+1 );
    for (int i = 1; i < k; i++)
        nimsum = nimsum ^ ( n[i] % (m[i] + 1) ); //bitwise XOR with n_j%m_j
    
    return nimsum;
}

//print
void bin_print(int n[],int k){
    for (int i = 0; i < k; i++)
        printf("bin %d: %d | ", i + 1, n[i]);
    printf("Total: %d\n", sum(n, k));
}

//Finding moves for computer
void find_move(int n[], int m[], int k){

    int n_sum = nimsum(n, m, k);
    int initial, final, decrement;

    for(int i=0; i<k; i++){
        initial = n[i]%(m[i]+1);
        final = initial ^ n_sum;
        decrement = (initial > final)?(initial - final):(m[i] + 1 + initial - final);
        
        //printf("i: %d, f: %d, d: %d\n", initial, final, decrement);
        if(decrement <= n[i] && decrement<=m[i] && decrement!=0){
            c[0] = i;
            c[1] = decrement;
            return;
        }
        else
        {
            if (n[i]>0)
                c[0] = i; c[1]=1;

        }
              
    }
}

int main(){
    int k; // total number of bins
    printf("#bins: ");
    scanf("%d", &k);

    int n[k], m[k]; //n-total balls; m-max limit
    

    for(int i=0; i<k; i++){
        printf("bin %d: ", i+1);
        scanf("%d %d", &n[i], &m[i]);
    }

    bin_print(n, k);

    //printf("Total: %d\n", sum(n,k));
    //printf("nimsum: %d\n", nimsum(n, m, k));

    while(1){
        
        //-------------------------------User Move
        printf("user: ");
        scanf("%d %d", &u[0], &u[1]); // u0: bin index u1:balls; it follows 1 indexing

        n[u[0] - 1] = n[u[0] - 1] - u[1]; // subtract from respective bin
        bin_print(n, k);
        if (sum(n, k) == 0)
        {
            printf("computer: FAIL\n");
            printf("\n>>>>>>>>NO<<<<<<<<<\n");
            break;
        }
       
        //-------------------------------Computer Move
        find_move(n, m, k);
        printf("computer: %d %d\n", c[0] + 1,c[1]);
        n[c[0]] = n[c[0]] - c[1]; // subtract from respective bin
        bin_print(n, k);
        if (sum(n, k) == 0)
        {
            printf("\n>>>>>>>>YES<<<<<<<<<\n");
            break;
        }    
    }
    return 0;

}