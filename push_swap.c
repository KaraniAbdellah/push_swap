#include <stdio.h>
#include "src/header.h"
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[]) {
    printf("Welcome To Push Swap Project: \n");

    long int *T = check_passing_args(&argc, argv);
    int length = argc - 1;
    printf("leenght = %d\n", length);
    for (int i = 0; i < length; i++) {
        printf("T = %ld\n", T[i]);
    }
    printf("size of array T = %ld\n", sizeof(T) / sizeof(long int) + 1);

    // // The Input Will Be From User To Stack a
    // long int n = sizeof(T);
    // int size_a = n, size_b = 0;
    // Stack *a = malloc(sizeof(Stack) * size_a);
    // Stack *b = malloc(sizeof(Stack) * size_a);

    // // Initialize The Stack a
    // for (int i = 0; i < n; i++) {
    //     a[i].data = T[i];
    // }
    // for (int i = 0; i < n; i++) {
    //     b[i].data = 0;
    // }

    // display_a_b(a, b, size_a, size_b);
    // sorting_algo(a, b, &size_a, &size_b);
    // display_a_b(a, b, size_a, size_b);




    return 0;
}


