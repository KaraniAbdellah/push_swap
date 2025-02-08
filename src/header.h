#ifndef PUSH_SWAP
#define PUSH_SWAP


// Define The Structure of Stack
typedef struct Stack {
    long int data;
    struct Stack *next;
    struct Stack *prev;
} Stack;

// Start Define The Color



// Start Defining The Functions Prototype
Stack *create_and_init_node(int data);
void push_to_stack(Stack **head, Stack **sommet, int data);
void display_stack(Stack *head);
void pop_from_stack(Stack **head, Stack **sommet);
void sorting_algo(Stack *a, Stack *b, int *size_a, int *size_b);
long int *check_passing_args(int *argc, char **argv);
int isThisDigit(char *arg);
void display_a_b(Stack *a, Stack *b, int size_a, int size_b);
int getNumberOfSpace(char *s);
int isThisStackSorted(Stack *a, int size_a);



#endif

