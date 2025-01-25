#ifndef PUSH_SWAP
#define PUSH_SWAP


// Define The Structure of Stack
typedef struct Stack {
    int data;
    struct Stack *next;
    struct Stack *prev;
} Stack;



// Start Defining The Functions Prototype
Stack *create_and_init_node();




#endif

