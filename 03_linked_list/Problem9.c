#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

bool findLoopFloyd(struct listNode* head) {
    if (head == NULL){
        return false;
    }
    struct listNode* slow = head;
    struct listNode* fast = head;

    while (fast->next != NULL) {
        if (fast == NULL) {
            return false;
        }
        fast = (fast->next)->next;
        slow = slow->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
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

    printf("%d\n", findLoopFloyd(head)); // 0

    // modify the list to create a loop
    struct listNode* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = head->next;
    printf("%d\n", findLoopFloyd(head)); // 1


    free(cur);

	printSLList(head); // []
	return 0;
}