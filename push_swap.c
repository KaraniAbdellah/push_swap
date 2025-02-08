#include <stdio.h>
#include "src/header.h"
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[]) {
    printf("Welcome To Push Swap Project: \n");
    if (argc <= 1) {
        printf("You Need Some Number Arguments!\n");
        exit(1);
    }
    // The Input Will Be From User To Stack a
    int length = getNumberOfSpace(argv[1]);
    long int *T = check_passing_args(&argc, argv);

    long int n = length - 4;
    int size_a = n, size_b = 0;
    Stack *a = malloc(sizeof(Stack) * size_a);
    Stack *b = malloc(sizeof(Stack) * size_a);

    // Initialize The Stack a
    for (int i = 0; i < n; i++) {
        a[i].data = T[i]; b[i].data = 0;
    }

    // Check If The Stack Already Sorted
    if (isThisStackSorted(a, size_a) == 1) {
        printf("OK, It is Already Sorted\n");
        exit(0);
    }


    display_a_b(a, b, size_a, size_b);
    sorting_algo(a, b, &size_a, &size_b);
    display_a_b(a, b, size_a, size_b);

    free(T); free(a); free(b);


    return 0;
}


