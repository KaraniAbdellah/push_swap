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


void sa(Stack *a) {
    int temp = a[0].data;
    a[1].data = a[0].data;
    a[0].data = temp;
}

void sb(Stack *b) {
    int temp = b[0].data;
    b[1].data = b[0].data;
    b[0].data = temp;
}

void ss(Stack *a, Stack *b) {
    sa(a);
    sb(b);
}

void pa(Stack *a, Stack *b, int *n) {
    a[0].data = b[0].data;
    for (int i = 0; i < *n - 1; i++) {
        b[i].data = b[i + 1].data;
    }
    *n -= 1;
}

void pb(Stack *a, Stack *b, int *n) {
    b[0].data = a[0].data;
    for (int i = 0; i < *n - 1; i++) {
        a[i].data = a[i + 1].data;
    }
    *n -= 1;
}

void ra(Stack *a, int n) {
    a[n - 1].data = a[0].data;
    for (int i = 0; i < n - 1; i++) {
        a[i].data = a[i + 1].data;
    }
}

void rb(Stack *b, int n) {
    b[n - 1].data = b[0].data;
    for (int i = 0; i < n - 1; i++) {
        b[i].data = b[i + 1].data;
    }
}

void rr(Stack *a, Stack *b, int n) {
    ra(a, n);
    rb(b, n);
}

void rra(Stack *a, int n) {
    int temp1 = a[n - 1].data;
    for (int i = n - 1; i > 0; i--) {
        a[i].data = a[i- 1].data;
    }
    a[0].data = temp1;
}

void rrb(Stack *b, int n) {
    int temp1 = b[n - 1].data;
    for (int i = n - 1; i > 0; i--) {
        b[i].data = b[i- 1].data;
    }
    b[0].data = temp1;
}

void rrr(Stack *a, Stack *b, int n) {
    rra(a, n);
    rra(b, n);
}




void sorting_algo(int n, Stack *a, Stack *b) {

    // PUSH Operattion
    b[0].data = a[0].data;
    for (int i = 0; i < n; i++) {
        a[i].data = a[i + 1].data;
    }
    n--;


    // SWAP Operation
    int temp = a[0].data;
    a[0].data = a[1].data;
    a[1].data = temp;


    // ROTATE Operation
    a[n].data = a[0].data;
    for (int i = 0; i < n; i++) {
        a[i].data = a[i + 1].data;
    }


    // REVERSE Rotate
    int temp1 = a[n].data;
    for (int i = n - 1; i >= 0; i--) {
        a[i].data = a[i- 1].data;
    }
    a[0].data = temp1;

}


int isThisDigit(char *arg) {
    int i = 0;
    if (arg[i] == '\0' || !arg[i]) return -1;
    if (arg[i] == '+' || arg[i] == '-') i++;

    for (; arg[i] != '\0'; i++) {
        if (arg[i] < '0' || (int) arg[i] > '9') {
            if (arg[i] == ' ' || arg[i] == '+' || arg[i] == '-') continue;
        }
    }
    return 0;
}


void print_passing_arg(int *argc, char **argv) {
    for (int i = 0; i < *argc; i++) {
        printf("argv = %s\n", argv[i]);
        printf("%d \n", isThisDigit(argv[i]));
    }
}







// int isThisDigit(char *arg) {
//     int i = 0;
//     // if (!arg || !arg[0]) return -1;
//     // if (arg[0] == '+' || arg[0] == '-') i++;
//     // for (; arg[i] != '\0'; i++) {
//     //     if (arg[i] < '0' || arg[i] > '9') return -1;
//     // }
//     // return (i == 1 && (arg[0] == '+' || arg[0] == '-')) ? -1 : 0;
// }




