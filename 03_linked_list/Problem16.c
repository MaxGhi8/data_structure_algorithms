#include<stdio.h>
#include<stdlib.h>

// Define a structure for the Singly Linked List (SLL)
struct listNode{
	int data;
	struct listNode *next;
};

void printSLList(struct listNode* head);
int singlyListLength(struct listNode* head);
struct listNode* insertAtBeginning(struct listNode* head, int data);
struct listNode* insertAtEnd(struct listNode* head, int data);
struct listNode* insertAtGivenPosition(struct listNode* head, int data, int pos);
void* deleteFirst(struct listNode** head);
void* deleteLast(struct listNode** head);
void* delete(struct listNode** head, int idx);
void* deleteLinkedList(struct listNode** head);

struct listNode* reverseListNode(struct listNode* head){
    struct listNode* cur = head;
    struct listNode* reversed = NULL;
    while (cur != NULL){
        reversed = insertAtBeginning(reversed, cur->data);
        cur = cur->next;
    }
    return reversed;
} 


int main(){
	struct listNode *head=NULL;

	head = insertAtBeginning(head, 5);
	head = insertAtBeginning(head, 2);
	head = insertAtBeginning(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtGivenPosition(head, 32, 1);
    head = insertAtGivenPosition(head, 42, 100);
    head = insertAtGivenPosition(head, 42, 5);
	printSLList(head); // [32, 2, 2, 5, 42, 3, 42]

    struct listNode* reversed = reverseListNode(head);
    printSLList(reversed); // [42, 3, 42, 5, 2, 2, 32]

    free(head);
    free(reversed);
	return 0;
}