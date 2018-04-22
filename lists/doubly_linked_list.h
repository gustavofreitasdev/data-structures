#include <stdlib.h>
#include <stdio.h>

/*  Type node, with information about the previous and the next. 
    A Doubly Linked List is a set of this type of node
*/
typedef struct node_type{
    struct node_type *previous;
    struct node_type *next;
    char data;
} Node;

// Creates a node for a Doubly Linked List
Node *DoublyLinkedList_create(char data);

// Given a value, it inserts at the top of the list
Node *DoublyLinkedList_insertStart(Node *list, char new_data);
// Given a value, it inserts at the bottom of the list
Node *DoublyLinkedList_insertEnd(Node *list, char new_data);
// Given a value, it neatly inserts from the list
Node *DoublyLinkedList_insertOrderly(Node *list, char new_data);

// Removes the first node from the list
Node *DoublyLinkedList_removeStart(Node *list);
// Removes the last node from the list
Node *DoublyLinkedList_removeEnd(Node *list);
// Given the value of the node, if there is remove
Node *DoublyLinkedList_removeData(Node *list, char data);

// Given the value of the node, it returns the node if it exists
Node *DoublyLinkedList_get(Node *list, char data);

// Returns the size of the list
unsigned int DoublyLinkedList_len(Node *list);
// Print a list
void DoublyLinkedList_print(Node *list);
