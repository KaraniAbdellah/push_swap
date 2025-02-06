// The Rule
/*
    You have 2 stacks named a and b.
        - At the beginning:
            --> The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
            --> The stack b is empty.

    - The goal is to sort in ascending order numbers into stack a. To do so you have the
    following operations at your disposal:

    sa (swap a): Swap the first 2 elements at the top of stack a.
        Do nothing if there is only one or no elements.

    sb (swap b): Swap the first 2 elements at the top of stack b.
        nothing if there is only one or no elements.

    ss : sa and sb at the same time.

    pa (push a): Take the first element at the top of b and put it at the top of a.
        nothing if b is empty.

    pb (push b): Take the first element at the top of a and put it at the top of b.
        nothing if a is empty.

    ra (rotate a): Shift up all elements of stack a by 1.
        The first element becomes the last one.

    rb (rotate b): Shift up all elements of stack b by 1.
        The first element becomes the last one.

    rr : ra and rb at the same time.

    rra (reverse rotate a): Shift down all elements of stack a by 1.
        The last element becomes the first one.

    rrb (reverse rotate b): Shift down all elements of stack b by 1.
        The last element becomes the first one.
        
    rrr : rra and rrb at the same time
*/

// Include The Necessary Libs
#include "header.h"
#include <stdio.h>
#include <stdlib.h>


Stack *create_and_init_node(int data) {
    Stack *new_node = malloc(sizeof(Stack));
    if (new_node != NULL) {
        new_node->next = new_node->prev = NULL;
        new_node->data = data;
        return new_node;
    } else return NULL;
}


void push_to_stack(Stack **head, Stack **sommet, int data) {
    Stack *new_node = create_and_init_node(data);
    if (new_node == NULL) return;

    if (*head == NULL) {
        *head = new_node;
        *sommet = new_node;
        return;
    }

    (*sommet)->next = new_node;
    new_node->prev = *sommet;
    *sommet = new_node;
}

void pop_from_stack(Stack **head, Stack **sommet) {
    if (*sommet == NULL) return;
    Stack *temp = *sommet;
    *sommet = (*sommet)->prev;
    if (*sommet == NULL) *head = NULL;
    else (*sommet)->next = NULL;
    free(temp);
}

void display_stack(Stack *head) {
    printf("Stack X:\n");
    Stack *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void sa(Stack *a, int *size_a) {
    if (*size_a > 1) {
        int temp = a[0].data;
        a[0].data = a[1].data;
        a[1].data = temp;
    }
}

void sb(Stack *b, int *size_b) {
    if (*size_b > 1) {
        int temp = b[0].data;
        b[0].data = b[1].data;
        b[1].data = temp;
    }
}

void ss(Stack *a, Stack *b, int *size_a, int *size_b) {
    sa(a, size_a);
    sb(b, size_b);
}

void pa(Stack *a, Stack *b, int *size_a, int *size_b) {
    if (*size_b > 0) {
        for (int i = *size_a; i > 0; i--) { 
            a[i].data = a[i - 1].data;
        }
        a[0].data = b[0].data;  
        for (int i = 0; i < *size_b - 1; i++) {  
            b[i].data = b[i + 1].data;  
        }
        (*size_a)++;  
        (*size_b)--;
    }
}

void pb(Stack *a, Stack *b, int *size_a, int *size_b) {
    if (*size_a > 0) { 
        for (int i = *size_b; i > 0; i--) { 
            b[i].data = b[i - 1].data;  
        }
        b[0].data = a[0].data;  
        for (int i = 0; i < *size_a - 1; i++) {  
            a[i].data = a[i + 1].data;  
        }
        (*size_b)++;  
        (*size_a)--;  
    }
}

void ra(Stack *a, int *size_a) {
    if (*size_a > 1) {
        int temp = a[0].data;
        for (int i = 0; i < *size_a - 1; i++) {
            a[i].data = a[i + 1].data;
        }
        a[*size_a - 1].data = temp;
    }
}

void rb(Stack *b, int *size_b) {
    if (*size_b > 1) {
        int temp = b[0].data;
        for (int i = 0; i < *size_b - 1; i++) {
            b[i].data = b[i + 1].data;
        }
        b[*size_b - 1].data = temp;
    }
}

void rr(Stack *a, Stack *b, int *size_a, int *size_b) {
    ra(a, size_a);
    rb(b, size_b);
}

void rra(Stack *a, int *size_a) {
    if (*size_a > 1) {
        int temp = a[*size_a - 1].data;
        for (int i = *size_a - 1; i > 0; i--) {
            a[i].data = a[i- 1].data;
        }
        a[0].data = temp;
    }
}

void rrb(Stack *b, int *size_b) {
    if (*size_b > 1) {
        int temp = b[*size_b - 1].data;
        for (int i = *size_b - 1; i > 0; i--) {
            b[i].data = b[i- 1].data;
        }
        b[0].data = temp;
    }
}

void rrr(Stack *a, Stack *b, int *size_a, int *size_b) {
    rra(a, size_a);
    rrb(b, size_b);
}




void sorting_algo(Stack *a, Stack *b, int *size_a, int *size_b) {

    // Start Sorting Here The ELemenets With Some Conditions

}


void display_a_b(Stack *a, Stack *b, int size_a, int size_b) {
    printf("The Stack a and b:\n");
    printf("a = [ "); for (int i = 0; i < size_a; i++) printf("%d ", a[i].data); printf("]\n");
    printf("b = [ "); for (int i = 0; i < size_b; i++) printf("%d ", b[i].data); printf("]\n");
}

int isThisDigit(char *arg) {
    int i = 0;
    for (; arg[i] != '\0'; i++) {
        if (arg[i] < '0' || (int) arg[i] > '9') {
            if (arg[i] == ' ' || arg[i] == '+' || arg[i] == '-') continue;
            else return -1;
        }
    }
    return 1;
}



void print_passing_arg(int *argc, char **argv) {
    for (int i = 0; i < *argc; i++) {
        printf("%s --> %d\n", argv[i], isThisDigit(argv[i]));
    }
}








