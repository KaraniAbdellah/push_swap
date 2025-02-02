#include <stdio.h>
#include "src/header.h"
#include <stdlib.h>


int main() {
    printf("Welcome To Push Swape Project: \n");
    
    int n = 6;
    int T[] = {5, 2, 3, 1, -5, 6};
    Stack *a = malloc(sizeof(Stack) * n);
    Stack *b = malloc(sizeof(Stack) * n);

    // initialize the stack a
    for (int i = 0; i < n; i++) {
        a[i].data = T[i];
    }

    // sorting the stack a
    sorting_algo(n, a, b);



    
    


    
    

    return 0;
}





