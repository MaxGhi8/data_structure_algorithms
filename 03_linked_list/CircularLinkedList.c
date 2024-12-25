#include<stdio.h>
#include<stdlib.h>

// Definition of Circular Linked List (CLL)
struct CircularLL
{
    int data;
    struct CircularLL *next;
};

// Function to print the elements of the CLL
void printCLL(struct CircularLL* head){
    if (head == NULL) {
        printf("[]\n");
        return;
    }
    struct CircularLL* cur = head;
    printf("[");
    while (cur->next != head){
        printf("%d, ", cur->data);
        cur = cur->next;
    }
    printf("%d]\n", cur->data);
}

// Function to print the elements of the CLL
int countCLL(struct CircularLL* head){
    if (head == NULL) {
        return 0;
    }
    int count = 1;
    struct CircularLL* cur = head;
    while (cur->next != head){
        count++;
        cur = cur->next;
    }
    return count;
}

// Insert an element at the beginning of a CLL
void insertAtBeginnig(struct CircularLL **head, int data)
{
    // Create a new object
    struct CircularLL* tmp = (struct CircularLL*)malloc( sizeof(struct CircularLL) );
    tmp->data = data;
    tmp->next = tmp;

    if (*head == NULL) {
        *head = tmp;
        return;
    }

    tmp->next = *head;
    struct CircularLL* cur = *head;
    while (cur->next != *head) {
        cur = cur->next;
    }
    cur->next = tmp;
    *head = tmp;
    return;
}

// Insert an element at the end of a CLL
void insertAtEnd(struct CircularLL** head, int data){
    // Create a new object
    struct CircularLL* tmp = (struct CircularLL*)malloc( sizeof(struct CircularLL) );
    tmp->data = data;
    tmp->next = tmp;

    if (*head == NULL) {
        *head = tmp;
        return;
    }

    struct CircularLL* cur = *head;
    while (cur->next != *head) {
        cur = cur->next;
    }
    cur->next = tmp;
    tmp->next = *head;
    return;
}

// Delete the first element of a CLL
void deleteFrontNode(struct CircularLL** head){
    if (*head == NULL) {
        return;
    } else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    struct CircularLL* cur = *head;
    struct CircularLL* tmp = *head;
    while (cur->next != *head) {
        cur = cur->next;
    }
    cur->next = (*head)->next;
    *head = (*head)->next;
    free(tmp);
    return;
}

// Delete the last element of a CLL
void deleteEndNode(struct CircularLL** head){
    if (*head == NULL) {
        return;
    } 
    else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    struct CircularLL* cur = *head;
    struct CircularLL* tmp;
    while (cur->next != *head) {
        tmp = cur;
        cur = cur->next;
    }
    tmp->next = *head;
    free(cur);
    return;
}

// Delete the entire CLL
void deleteCLL(struct CircularLL** head){
    if (*head == NULL) {
        return;
    }
    while (*head != NULL) {
        deleteFrontNode(head);
    }
    return;
}

int main(){
    struct CircularLL* head = NULL;
    printCLL(head); // []

    insertAtBeginnig(&head, 1) ;
    insertAtBeginnig(&head, 2) ;
    insertAtBeginnig(&head, 3) ;
    printCLL(head); // [3, 2, 1]

    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    printCLL(head); // [3, 2, 1, 4, 5, 6]
    printf("Number of elements in the CLL: %d\n", countCLL(head)); // 6

    deleteFrontNode(&head);
    deleteFrontNode(&head);
    printCLL(head); // [1, 4, 5, 6]

    deleteEndNode(&head);
    deleteEndNode(&head);
    printCLL(head); // [1, 4]

    deleteCLL(&head);
    printCLL(head); // []

}
