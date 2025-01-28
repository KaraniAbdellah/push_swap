#include <stdio.h>
#include "src/header.h"


int main() {
    printf("Welcome To Push Swape Project: \n");
    
    Stack *head = NULL, *sommet = NULL;

    push_to_stack(&head, &sommet, 5);
    push_to_stack(&head, &sommet, 2);
    push_to_stack(&head, &sommet, 3);
    push_to_stack(&head, &sommet, 1);
    push_to_stack(&head, &sommet, -5);
    push_to_stack(&head, &sommet, 6);

    display_stack(head);

    return 0;
}





