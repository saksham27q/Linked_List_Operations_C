#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    printf("%d inserted at beginning\n", val);
}

void insertAtLast(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        printf("%d inserted at last\n", val);
        return;
    }

    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    printf("%d inserted at last\n", val);
}

void display(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){

    int choice, val;

    while(1){
        printf("\n1. Insert at Beginning\n2. Insert at Last\n3. Display\n4. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value : ");
                scanf("%d", &val);
                insertAtBeginning(val);
                break;
            case 2:
                printf("Enter value : ");
                scanf("%d", &val);
                insertAtLast(val);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

return 0;
}