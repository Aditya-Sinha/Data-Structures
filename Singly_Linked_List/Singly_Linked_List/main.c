//
//  main.c
//  Singly_Linked_List
//
//  Created by Aditya Sinha on 19/10/13.
//  Copyright (c) 2013 Aditya Sinha. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#pragma pack(1)

void insertAtTheBeginning(int);
void insertAtTheEnd(int);
void deleteFromTheBeginning();
void deleteFromTheEnd();
void insertItemAtPostion(int, int);

void display();
struct ListNode{
    int data;
    struct ListNode *next;
};

typedef struct ListNode NODE;



NODE *head = NULL;

int main(int argc, const char * argv[])
{
    // insert code here...
    int ch;
    int item;
    int position;
    do
    {
        printf("\n1.\tInsert at the beginning\n2.\tDelete from the beginning\n3.\tDisplay\n4.\tInsert at the end\n5.\tDelete from the end\n6.\tInsert at position");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("\n\nEnter ITEM to be inserted at the beginning: ");
                scanf("%d", &item);
                insertAtTheBeginning(item);
                break;
            case 2:
                deleteFromTheBeginning();
                break;
            case 3:
                printf("\n\nHere is the list: ");
                display();
                break;
            case 4:
                printf("\n\nEnter ITEM to be inserted at the end: ");
                scanf("%d", &item);
                insertAtTheEnd(item);
                break;
                
            case 5:
                deleteFromTheEnd();
                break;
                
            case 6:
                
                printf("\n\nEnter Position: ");
                scanf("%d", &position);
                printf("\n\nEnter ITEM to be inserted: ");
                scanf("%d", &item);
                insertItemAtPostion(item, position);
                break;
            default:
                printf("\n\nInvalid choice. Pleasr try again...\n");
        }
    } while(1);
    
    return 0;
}

void insertAtTheBeginning(int item)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode==NULL) {
        printf("/nNODE CREATION FAILED");
        return;
    }
    newNode->data=item;
    
    if (head==NULL) { //First Node
        newNode->next=NULL;
        head=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;
}

void deleteFromTheBeginning()
{
    if (head==NULL) {
        printf("\nLL is empty, nothing to delete");
        return;
    }
    NODE *temp = head;
    head=head->next;
    free(temp);
}

void display()
{
    if (head==NULL) {
        printf("LL is empty");
        return;
    }
    NODE *current = head;
    while (current!=NULL) {
        printf("\n %d",current->data);
        current=current->next;
    }
}

void insertAtTheEnd(int item)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode==NULL) {
        printf("/nNODE CREATION FAILED");
        return;
    }
    newNode->data=item;
    newNode->next=NULL;
    NODE *current = head;
    while (current->next!=NULL) {
        current=current->next;
    }
    current->next=newNode;
}

void deleteFromTheEnd(){
    if (head==NULL) {
        printf("\nLL is empty, nothing to delete");
        return;
    }
    NODE *previous = NULL;
    NODE *current = head;
    while (current->next!=NULL) {
        previous=current;
        current=current->next;
    }
    previous->next=NULL;
    free(current);
    
}

void insertItemAtPostion(int item, int position)
{
    
    if (position<=1) {
        insertAtTheBeginning(item);
        return;
    }
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode==NULL) {
        printf("/nNODE CREATION FAILED");
        return;
    }
    newNode->data=item;
    int k=1;
    NODE *current = head;
    NODE *previous=NULL;
    while (k<position && current!=NULL) {
        k++;
        previous=current;
        current=current->next;
    }
    previous->next=newNode;
    newNode->next=current;
}
