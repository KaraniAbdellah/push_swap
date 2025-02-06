#include <stdio.h>
#include "src/header.h"
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[]) {
    printf("Welcome To Push Swape Project: \n");
    
    print_passing_arg(&argc, argv);

    // The Input Will Be From User [Stack a]
    int n = 3;
    int size_a = n, size_b = 0;
    int T[] = {1, -1, 5};
    Stack *a = malloc(sizeof(Stack) * size_a);
    Stack *b = malloc(sizeof(Stack) * size_a);

    // Initialize The Stack a
    for (int i = 0; i < n; i++) {
        a[i].data = T[i];
    }
    for (int i = 0; i < n; i++) {
        b[i].data = 0;
    }

    display_a_b(a, b, size_a, size_b);
    sorting_algo(a, b, &size_a, &size_b);
    display_a_b(a, b, size_a, size_b);




    return 0;
}


