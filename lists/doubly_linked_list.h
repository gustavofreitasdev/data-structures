#include <stdlib.h>
#include <stdio.h>

typedef struct node_type{
    struct node_type *previous;
    struct node_type *next;
    char data;
} Node;

Node *DoublyLinkedList_create(char data);

Node *DoublyLinkedList_insertStart(Node *list, char new_data);

Node *DoublyLinkedList_insertEnd(Node *list, char new_data);

Node *DoublyLinkedList_insertOrderly(Node *list, char new_data);

Node *DoublyLinkedList_removeStart(Node *list);

Node *DoublyLinkedList_removeEnd(Node *list);

Node *DoublyLinkedList_removeData(Node *list, char data);

Node *DoublyLinkedList_get(Node *list, char data);

unsigned int DoublyLinkedList_len(Node *list);

void DoublyLinkedList_print(Node *list);
