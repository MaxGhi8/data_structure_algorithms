#include<stdio.h>
#include<stdlib.h>

// Define a structure for the Singly Linked List (SLL)
struct listNode{
	int data;
	struct listNode *next;
};

// Function to print the elements of the SLL
void printSLList(struct listNode* head){
	while(head!=NULL){
		printf("%d ",(*head).data); // (*head).data is same as head->data
		head=(*head).next; // (*head).next is same as head->next
	}
	printf("\n");
}

// Function to traverse a SLL and find the length of the SLL
int singlyListLength(struct listNode* head){
	int count=0;
	struct listNode *current=head;
	while(current!=NULL){
		count++;
		current = current->next;	
	}
	return count;
}

// Function to insert a node at the beginning of the SLL
struct listNode* insertAtBeginning(struct listNode* head, int data){
    // Create a new node
    struct listNode* tmp;
    tmp = (struct listNode*)malloc( sizeof(struct listNode) );
    tmp -> data = data; // (*tmp).data
    tmp -> next = NULL;

    if ( head == NULL ) {
        return tmp;
    } else {
        tmp -> next = head;
        return tmp;
    }
}

// Function to insert a node at the ending of the SLL
struct listNode* insertAtEnd(struct listNode* head, int data){
    // Create a new node
    struct listNode* tmp;
    tmp = (struct listNode*)malloc( sizeof(struct listNode) );
    tmp->data = data;
    tmp->next = NULL;

    // traverse the list
    if (head == NULL) {
        return tmp;
    }
    struct listNode* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = tmp;
    return head;
}

// Insert a node in a given position (more general function)
struct listNode* insertAtGivenPosition(struct listNode* head, int data, int pos){
    // Create the new node
	struct listNode* newNode = (struct listNode*)malloc( sizeof(struct listNode) );
	newNode->data = data;
    newNode->next = NULL;

	int counter = 1;
    struct listNode *cur = head;

	if(cur == NULL){
        return newNode;
	} else if (pos == 1) {
        newNode -> next = head;
        return newNode;
    }
	else{ 
        while (cur->next != NULL) {
            if (counter == pos-1){
                struct listNode* tmp = cur->next;
                cur->next = newNode;
                newNode->next = tmp;
                return head;
            } 
            else {
                cur = cur->next;
                counter++;
            }
        }
        cur->next = newNode;
        return head;
	}
}

// Function to delete the first element
void* deleteFirst(struct listNode** head){ // double asterisk = pointer to the pointer of the structure
    struct listNode* tmp;
    if (*head == NULL){
        return NULL;
    }
    else {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return NULL;
    }
}

// Function to delete the last element
void* deleteLast(struct listNode** head){ // double asterisk = pointer to the pointer of the structure
    struct listNode* tmp;
    if (*head == NULL){
        return NULL;
    }
    else {
        struct listNode* cur = *head;
        struct listNode* tmp;
        while (cur->next != NULL) {
            tmp = cur;
            cur = cur->next;
        }
        tmp->next = NULL;
        free(cur);
        return NULL;
    }
}

// Function to delete a specific element inside the SLL
void* delete(struct listNode** head, int idx){
    struct listNode* tmp;
    struct listNode* cur = *head;
    for (int i = 2; i < idx; i++){
        cur = cur->next;
    }
    tmp = cur->next;
    cur->next = tmp->next;
    // tmp->next = NULL;
    return NULL;
}

// Delete an entire SLL
void* deleteLinkedList(struct listNode** head){
    while (*head != NULL) {
        deleteFirst(head);
    }
    return NULL;
}

static int main(){
	struct listNode *head=NULL;

	head = insertAtBeginning(head, 5);
	head = insertAtBeginning(head, 2);
	head = insertAtBeginning(head, 2);
	printSLList(head); // [2, 2, 5]

    head = insertAtEnd(head, 3);
	printSLList(head); // [2, 2, 5, 3]

    head = insertAtGivenPosition(head, 32, 1);
    head = insertAtGivenPosition(head, 42, 100);
    head = insertAtGivenPosition(head, 42, 5);
	printSLList(head); // [32, 2, 2, 5, 42, 3, 42]

    deleteFirst(&head);
    deleteLast(&head);
	printSLList(head); // [2, 2, 5, 42, 3]

    delete(&head, 3);
    delete(&head, 3);
	printSLList(head); // [2, 2, 3]

    deleteLinkedList(&head);
	printSLList(head); // []
	return 0;
}