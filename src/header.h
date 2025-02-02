#ifndef PUSH_SWAP
#define PUSH_SWAP


// Define The Structure of Stack
typedef struct Stack {
    int data;
    struct Stack *next;
    struct Stack *prev;
} Stack;



// Start Defining The Functions Prototype
Stack *create_and_init_node(int data);
void push_to_stack(Stack **head, Stack **sommet, int data);
void display_stack(Stack *head);
void pop_from_stack(Stack **head, Stack **sommet);
void sorting_algo(int n, Stack *a, Stack *b);




#endif

