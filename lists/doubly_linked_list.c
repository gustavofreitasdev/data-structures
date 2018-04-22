#include "doubly_linked_list.h"

Node *DoublyLinkedList_create(char data){
    Node *new_list = (Node *) malloc(sizeof(Node));
    if(new_list != NULL){ 
        // if can allocate
        new_list->previous = NULL;
        new_list->next = NULL;
        new_list->data = data;
    }
    else
        printf("Error: malloc Node\n");

    return new_list;
}

Node *DoublyLinkedList_insertStart(Node *list, char new_data){
    Node *new_element = DoublyLinkedList_create(new_data);
    if(list != NULL && new_element != NULL){
        // if it is not an empty list, and if can allocate
        list->previous = new_element; // change the 'previous' cursor from the first list element to the new element
        new_element->next = list; // changes the 'next' cursor of the new element, to point to the initial element of the list
    }
    list = new_element; // change the start of the list to the new element
    return list;
}
Node *DoublyLinkedList_insertEnd(Node *list, char new_data){
    Node *new_element = DoublyLinkedList_create(new_data);
    if(list != NULL && new_element != NULL){
        // if it is not an empty list, and if can allocate
        Node *aux = list;
        while(aux->next != NULL) // walks to the last element
            aux = aux->next;
        new_element->previous = aux; // changes the 'previous' cursor of the new element to the last element in the list
        aux->next = new_element; // changes the 'next' cursor from the last old element to the new last element in the list
    }
    else{
        // if it is an empty list
        list = new_element;
    }
    
    return list;
}
Node *DoublyLinkedList_insertOrderly(Node *list, char new_data){
    Node *new_element = DoublyLinkedList_create(new_data);
    if(list != NULL && new_element != NULL){
        // if the list is not empty, and the new element has been created
        Node *aux = list;
        while(aux->next != NULL){
            // scrolls through the list to the last element
            if(aux->data > new_data) // if you find an element larger than the data you are inserting
                break;
            // if it does not find it, it changes to the next one   
            aux = aux->next;
        }
        if(aux->previous == NULL && aux->data > new_data){
            // if the new element is the new first in the list
            list->previous = new_element; // change the 'previous' cursor from the first list element to the new element
            new_element->next = list; // changes the 'next' cursor of the new element, to point to the initial element of the list
            list = new_element; // change the start of the list to the new element
        }
        else if(aux->next == NULL && aux->data < new_data){
            // if the new element is the new last in the list
            aux->next = new_element; // points the 'next' pointer of the last element to the new element
            new_element->previous = aux; // points the 'previous' pointer of the new element to the old last node
        }
        else{
            // if the new element is in the middle of two elements
            Node *aux2 = aux->previous; // capture position of the previous node where the new element will be inserted
            aux2->next = new_element; // points to the 'next' cursor of the previous node where the new element will be inserted, to the new element
            new_element->previous = aux2; // points the 'previous' cursor of the new node by inserting it to the previous node.

            new_element->next = aux; // points the cursor 'next' to the new node by inserting, to the next node
            aux->previous = new_element; // points to the 'previous' cursor of the next node, to the new element
        }
    }
    else{
        // if it is an empty list
        list = new_element;
    }

    return list;
}

Node *DoublyLinkedList_removeStart(Node *list){
    if(list != NULL){
        // if it is not an empty list
        Node *aux = list->next; // captures the second list element
        if(aux != NULL) // if there is a second element
          aux->previous = NULL; // causes the 'previous' pointer of the second element to point to NULL
        free(list); // free space
        list = aux;  // makes the list point to the second element
    }
    
    return list;
}
Node *DoublyLinkedList_removeEnd(Node *list){
    if(list != NULL){
        // if it is not an empty list
        Node *aux = list;
        while(aux->next != NULL) // walks to the last element
            aux = aux->next;
        aux->previous->next = NULL; // makes the 'next' penultimate pointer element point to NULL
        free(aux); // free space
    }

    return list;
}
Node *DoublyLinkedList_removeData(Node *list, char data){
    if(list != NULL){
        // if it is not an empty list
        Node *aux = list;
        while(aux != NULL){ // scrolls through the list
            if(aux->data == data) // if it is the same data requested
                break;
            aux = aux->next;
        }
        if(aux != NULL){
            // if you have found the requested data
            if(aux->previous == NULL) // if it is the first element
                list = DoublyLinkedList_removeStart(list);
            else if(aux->next == NULL){
                // if it is the last element
                aux->previous->next = NULL; // makes the 'next' penultimate pointer element point to NULL
                free(aux); // free space
            }
            else{
                // if it is the element in the middle of the list
                Node *aux2 = aux->previous; // captures the previous element of the element to be deleted
                aux2->next = aux->next; // points to the 'next' pointer of the previous node element that will be removed to the next node of the element to be removed
                aux->next->previous = aux2; // points to the 'previous' pointer of the next node element that will be removed to the previous node of the element to be removed
                free(aux); // free space
            }
        }
    }

    return list;
}

Node *DoublyLinkedList_get(Node *list, char data){
    Node *result = NULL;
    if(list != NULL){
        // if it is not an empty list
        Node *aux = list;
        while(aux != NULL){ // scrolls through the list
            if(aux->data == data) // if it is the same data requested
                break;
            aux = aux->next;
        }
        result = aux;
    }

    return result;
}

unsigned int DoublyLinkedList_len(Node *list){
    unsigned int count = 0;
    if(list != NULL){
        // if it is not an empty list
        Node *aux = list;
        while(aux != NULL){
            // scrolls through the list
            count++;
            aux = aux->next;
        }
    }

    return count;
}

void DoublyLinkedList_print(Node *list){
    Node *aux = list;
    while(aux != NULL){
        // scrolls through the list
        printf("%c ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}