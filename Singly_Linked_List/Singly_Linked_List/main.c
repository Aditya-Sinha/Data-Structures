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
    do
    {
        printf("\n1.\tInsert at the beginning\n2.\tDelete from the beginning\n3.\tDisplay\n4.\tExit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("\n\nEnter ITEM to be inserted: ");
                scanf("%d", &item);
                insertAtTheBeginning(item);
                break;
            case 2:
                
                break;
            case 3:
                display();
                break;
            case 4:
//                return 0;
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