#include <stdio.h>
#include "src/header.h"
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[]) {
    printf("Welcome To Push Swape Project: \n");
    
    print_passing_arg(&argc, argv);

    // The Input Will Be From User [Stack a]
    int n = 6;
    int T[] = {5, 2, 3, 1, -5, 6};
    Stack *a = malloc(sizeof(Stack) * n);
    Stack *b = malloc(sizeof(Stack) * n);

    // Initialize The Stack a
    for (int i = 0; i < n; i++) {
        a[i].data = T[i];
    }

    display_a_b(a, b, n);
    sorting_algo(a, b, n);
    display_a_b(a, b, n);




    return 0;
}


