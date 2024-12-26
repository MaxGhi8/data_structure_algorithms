#include <stdio.h>
#include <stdlib.h>

// Define the stack struct
struct Stack{
    int top; // index of the top element
    int capacity;
    int* array;
};

// Create a stack
struct Stack* createStack(int capacity) {
    // allocate memory for the struct Stack
    struct Stack* S = (struct Stack*)malloc( sizeof(struct Stack) );
    if (!S){
        return NULL;
    }

    S->capacity = capacity; 
    S->top = -1;
    S->array = (int*)malloc( S->capacity * sizeof(int));
    if (! S->array) {
        return NULL;
    }
    return S;
}

// Check if the stack is empty
int isEmpty(struct Stack* S){
    return (S->top == -1);
};

// Get the size of the stack
int size(struct Stack* S){
    return (S->top + 1);
}

// Check if the stack is full
int isFull(struct Stack* S){
    return (size(S) == S->capacity);
}

// Add an element to the stack (push operation)
struct Stack* push(struct Stack* S, int data){
    if (isFull(S)){
        printf("Stack overflow.\n");
    }
    else {
        S->top++; 
        S->array[S->top] = data;
        return S;
    }
}

int pop(struct Stack* S){
    if (isEmpty(S)){
        printf("Stack underflow.\n");
    }
    else {
        int tmp = S->array[S->top];
        S->top--;
        return tmp;
    }
}

int top(struct Stack* S){
    if (isEmpty(S)){
        printf("Stack underflow.\n");
    }
    else {
        int tmp = S->array[S->top];
        return tmp;
    }
}

void deleteStack(struct Stack* S){
    if (S){
        if (S->array){
            free(S->array);
        }
        free(S);
    }
    return;
}

int main(){
    // Create a stack
    int capacity = 15;
    struct Stack* S = createStack(capacity);
    for(int i = 0; i < 10; i++){
        push(S, i);
    }
    printf("Top element is %d\n", S->array[S->top]);
    printf("Stack size is %d, stack capacity is %d\n", size(S), S->capacity);


    int n = pop(S);
    printf("Popped the element %d, now the top element is %d and the size is %d\n", n, S->array[S->top], size(S));

    int m = top(S);
    printf("Topped the element %d, now the top element is %d and the size is %d\n", m, S->array[S->top], size(S));

    deleteStack(S);

    return 0;
}