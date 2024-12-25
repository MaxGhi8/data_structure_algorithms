#include<stdio.h>
#include<stdlib.h>

struct DLLNode {
    int data;
    struct DLLNode *next;
    struct DLLNode *prev;
};

// Function to print the elements of the DLL
void printDLList(struct DLLNode* head){
	while(head!=NULL){
		printf("%d ",(*head).data); // (*head).data is same as head->data
		head=(*head).next; // (*head).next is same as head->next
	}
	printf("\n");
}

// Function to insert at the beginning of the DLL
void insertAtBeginnig(struct DLLNode **head, int data) {
    // Create the new node
    struct DLLNode* tmp = (struct DLLNode*)malloc( sizeof(struct DLLNode) );
    tmp->data = data;
    tmp->next = NULL;
    tmp->prev = NULL;

    // Concatenate with the previous model
    if (*head == NULL) {
        *head = tmp;
        return;
    }
    else {
        tmp->next = *head;
        (*head)->prev = tmp;
        *head = tmp;
        return;
    }
}

// Function to insert at the end of the DLL
void insertAtEnd(struct DLLNode** head, int data){
    // Create a new DLLNode
    struct DLLNode* tmp = (struct DLLNode*)malloc( sizeof(struct DLLNode) );
    tmp->data = data;
    tmp->next = NULL;
    tmp->prev = NULL;

    // Traverse the list
    struct DLLNode* cur = *head;
    if ( *head == NULL ) {
        return;
    }
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = tmp;
    tmp->prev = cur;
    return;
}

// Function for insert an element in a DLL in a given position
void insert(struct DLLNode** head, int data, int pos){
    // Create a new node
    struct DLLNode* tmp = (struct DLLNode*)malloc( (sizeof(struct DLLNode)) );
    tmp->data = data;
    tmp->next = NULL;
    tmp->prev = NULL;

    // head is NULL
    if (*head == NULL) {
        *head = tmp;
        return;
    }
    // Insertion at the beginning
    if (pos == 1) {
        tmp->next = *head;
        (*head)->prev = tmp;
        *head = tmp;
        return;
    }
    // Traverse the DLL
    struct DLLNode* cur = *head;
    int index = 1;
    while (cur->next != NULL) {
        if (pos-1 == index){
            // Insertion in the middle
            struct DLLNode* cur_cur = cur->next;
            cur->next = tmp;
            tmp->prev = cur;
            tmp->next = cur_cur;
            cur_cur->prev = tmp;
            return;
        }
        cur = cur->next;
        index++;
    }
    // Insertion at the end
    cur->next = tmp;
    tmp->prev = cur;
    return;
}

// Deletion the first element of a DLL
void deleteFrontNode(struct DLLNode** head) {
    // DLL is empty
    if (*head == NULL) {
        return;
    }
    // DLL is not empty
    struct DLLNode* tmp = *head;

    if ((*head)->next == NULL) {
        *head = NULL;
    }
    else {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }

    free(tmp);
    return;
}

void deleteLastNode(struct DLLNode** head){
    if (*head == NULL) {
        return;
    }
    struct DLLNode* cur = *head;
    struct DLLNode* tmp;
    while (cur->next != NULL) {
        tmp = cur;
        cur = cur -> next;
    }
    tmp->next = NULL;
    free(cur);
    return;
}

// Delete an element INSIDE a DLLNode at  a given position
void delete(struct DLLNode** head, int pos){
    if (*head == NULL) {
        return;
    }
    struct DLLNode* cur = *head;
    struct DLLNode* tmp;
    for (int i = 2; i < pos; i++){ // traverse
        cur = cur->next; 
    }
    tmp = cur->next;
    struct DLLNode* curr = tmp->next;
    cur->next = curr;
    curr->prev = cur;
    free(tmp);
    return;
}

// Delete the entire DLL
void deleteDLL(struct DLLNode** head){
    while (*head != NULL) {
        deleteFrontNode(head);
    }
    return;
}

int main(){
    struct DLLNode *head = NULL;
    printDLList(head); // []

    insertAtBeginnig(&head, 1);
    insertAtBeginnig(&head, 2);
    insertAtBeginnig(&head, 3);
    printDLList(head); // [3, 2, 1]

    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    printDLList(head); // [3, 2, 1, 4, 5, 6]

    insert(&head, 10, 1);
    insert(&head, 10, 100);
    insert(&head, 10, 5);
    printDLList(head); // [10, 3, 2, 1, 10, 4, 5, 6, 10]

    deleteFrontNode(&head);
    printDLList(head); // [3, 2, 1, 10, 4, 5, 6, 10]

    deleteLastNode(&head);
    printDLList(head); // [3, 2, 1, 10, 4, 5, 6]

    delete(&head, 4);
    printDLList(head); // [3, 2, 1, 4, 5, 6]

    deleteDLL(&head);
    printDLList(head); // []


    return 0;
}