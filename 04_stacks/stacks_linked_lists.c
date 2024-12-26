#include<stdio.h>
#include<stdlib.h>

// Define a structure for the Singly Linked List (SLL)
struct listNode{
	int data;
	struct listNode *next;
};

// Import all the functionalities implemented for Singly Linked Lists
void printSLList(struct listNode* head);
int singlyListLength(struct listNode* head);
struct listNode* insertAtBeginning(struct listNode* head, int data);
struct listNode* insertAtEnd(struct listNode* head, int data);
struct listNode* insertAtGivenPosition(struct listNode* head, int data, int pos);
void* deleteFirst(struct listNode** head);
void* deleteLast(struct listNode** head);
void* delete(struct listNode** head, int idx);
void* deleteLinkedList(struct listNode** head);


// Define the stack struct
struct Stack{
    struct listNode* top;
};

// Create a stack
struct Stack* createStack() {
    // allocate memory for the struct Stack
    struct Stack* S = (struct Stack*)malloc( sizeof(struct Stack) );
    if (!S){
        return NULL;
    }
    S->top = NULL;
    return S;
}

// Check if the stack is empty
int isEmpty(struct Stack* S){
    return (S->top == NULL);
};

// Get the size of the stack
int size(struct Stack* S){
    return singlyListLength(S->top);
}

// Add an element to the stack (push operation)
struct Stack* push(struct Stack* S, int data){
    S->top = insertAtBeginning(S->top, data);
    return S;
}

int pop(struct Stack* S){
    if (isEmpty(S)){
        printf("Stack underflow.\n");
    }
    int n = (S->top)->data;
    deleteFirst(&(S->top));
    return n;
}

int top(struct Stack* S){
    if (isEmpty(S)){
        printf("Stack underflow.\n");
    }
    int n = (S->top)->data;
    return n;
}

void deleteStack(struct Stack* S){
    if (S){
        if (S->top){
            deleteLinkedList(&(S->top));
        }
        free(S);
    }
    return;
}

int main(){
    // Create a stack
    int capacity = 15;

    // Add 10 elements to the stack
    struct Stack* S = createStack(capacity);
    for(int i = 0; i < 10; i++){
        push(S, i);
    }
    printf("Top element is %d\n", S->top->data);
    printf("Stack size is %d\n", size(S));

    // pop example
    int n = pop(S);
    printf("Popped the element %d, now the top element is %d and the size is %d\n", n, S->top->data, size(S));

    // top example
    int m = top(S);
    printf("Topped the element %d, now the top element is %d and the size is %d\n", m, S->top->data, size(S));

    deleteStack(S);

    return 0;
}