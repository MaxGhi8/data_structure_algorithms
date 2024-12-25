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

int kthNodeFromEnd(struct listNode* head, int k){
    struct listNode* cur = head;
    for (int i = 2; i <= k; i++) {
        if (cur== NULL) {
            printf("k=%d is greater than the length of the list\n", k);
            return -1; // error, k is greater than the length of the list
        }
        cur = cur->next;
    } 
    while (cur->next != NULL) {
        head = head->next;
        cur = cur->next;
    }
    return head->data;
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

    printf("%d\n", kthNodeFromEnd(head, 1)); // 42
    printf("%d\n", kthNodeFromEnd(head, 2)); // 3
    printf("%d\n", kthNodeFromEnd(head, 300)); // error
    printf("%d\n", kthNodeFromEnd(head, 7)); // 32

    deleteLinkedList(&head);
	printSLList(head); // []
	return 0;
}