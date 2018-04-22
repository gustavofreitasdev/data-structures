#include "doubly_linked_list.h"

Node *DoublyLinkedList_create(char data){
    Node *new_list = (Node *) malloc(sizeof(Node));
    if(new_list){
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
        list->previous = new_element;
        new_element->next = list;
    }
    list = new_element;
    return list;
}
Node *DoublyLinkedList_insertEnd(Node *list, char new_data){
    Node *new_element = DoublyLinkedList_create(new_data);
    if(list != NULL && new_element != NULL){
        Node *aux = list;
        while(aux->next != NULL)
            aux = aux->next;
        new_element->previous = aux;
        aux->next = new_element;
    }
    else{
        list = new_element;
    }
    
    return list;
}
Node *DoublyLinkedList_insertOrderly(Node *list, char new_data){
    Node *new_element = DoublyLinkedList_create(new_data);
    if(list != NULL && new_element != NULL){
        Node *aux = list;
        while(aux != NULL){
            if(aux->data > new_data)
                break;
            aux = aux->next;
        }
        if(aux != NULL){
            if(aux->previous != NULL){
                Node *aux2 = aux->previous;
                aux2->next = new_element;
                new_element->previous = aux2;

                new_element->next = aux;
                aux->previous = new_element;
            }
            else{
                free(new_element);
                list = DoublyLinkedList_insertStart(list, new_data);
            }
        }
        else{
            free(new_element);
            list = DoublyLinkedList_insertEnd(list, new_data);
        }
    }
    else{
        list = new_element;
    }

    return list;
}

void DoublyLinkedList_print(Node *list){
    Node *aux = list;
    while(aux != NULL){
        printf("%c ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

int main(void){
    Node *list;
    // list = DoublyLinkedList_insertStart(list, 'g');
    // list = DoublyLinkedList_insertStart(list, 'f');
    // list = DoublyLinkedList_insertEnd(list, 'a');
    // list = DoublyLinkedList_insertEnd(list, 'b');

    list = DoublyLinkedList_insertOrderly(list, 'd');
    list = DoublyLinkedList_insertOrderly(list, 'a');
    list = DoublyLinkedList_insertOrderly(list, 'c');
    
    DoublyLinkedList_print(list);
    return 0;
}