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

int findLengthLoopFloyd(struct listNode* head) {
    if (head == NULL){
        return 0;
    }

    struct listNode* slow = head;
    struct listNode* fast = head;

    bool flag = false;
    while (fast->next != NULL) {
        if (fast == NULL) {
            return 0;
        }
        fast = (fast->next)->next;
        slow = slow->next;
        if (fast == slow) {
            flag = true;
            break;
        }
    }

    if (flag) {
        int count = 1;
        fast = fast->next;
        while (fast != slow) {
            count++;
            fast = fast->next;
        }
        return count;
    }
    else {
        return 0;
    }
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

    printf("%d\n", findLengthLoopFloyd(head)); // 0

    // modify the list to create a loop
    struct listNode* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = head->next; // skip the first node and then connect the loop
    printf("%d\n", findLengthLoopFloyd(head)); // 6


    deleteLinkedList(&head);
    
	printSLList(head); // []
	return 0;
}