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

int main(){
	struct listNode *head=NULL;
	head = insertAtBeginning(head, 5);
	printSLList(head);
	head = insertAtBeginning(head, 2);
	head = insertAtBeginning(head, 2);
	printSLList(head);
    head = insertAtEnd(head, 3);
	printSLList(head);
    head = insertAtGivenPosition(head, 32, 1);
	printSLList(head);
    head = insertAtGivenPosition(head, 42, 100);
	printSLList(head);
    head = insertAtGivenPosition(head, 42, 5);
	printSLList(head);
	return 0;
}