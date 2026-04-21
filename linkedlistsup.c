#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

int NoOfNodes(struct Node* head){

    int count = 0;

    while(NULL != head){
        count++;
        head = (*head).link;
    }

    return count;
}

void insertAtB(struct Node** head, int a){
    struct Node* temp = (struct Node*) malloc (sizeof(struct Node));
    (*temp).data = a;
    (*temp).link = *head;
    *head = temp;
}

void insertAtlast(struct Node** head, int a){
    struct Node* temp1 = (struct Node*) malloc (sizeof(struct Node));
    (*temp1).data = a;
    (*temp1).link = NULL;

    if(NULL == *head){
        *head = temp1;
        return;
    }

    struct Node* temp2 = *head;

    while(NULL != (*temp2).link){
        temp2 = (*temp2).link;
    }

    (*temp2).link = temp1;
}

void insertAtN(struct Node** head, int a, int n){
    int num = NoOfNodes(*head);

    if(n > num || n < 1){
        printf("ERROR : Invalid Position\n");
        return;
    }

    struct Node* temp1 = (struct Node*) malloc (sizeof(struct Node));
    (*temp1).data = a;
    (*temp1).link = NULL;

    if(1 == n){
        (*temp1).link = *head;
        *head = temp1;
        return;
    }

    struct Node* temp2 = *head;

    for(int i = 0; i < n-1; i++){
        temp2 = (*temp2).link;
    }

    (*temp1).link = (*temp2).link;
    (*temp2).link = temp1;

}

void deleteAtB (struct Node** head){
    struct Node* temp = *head;

    if (NULL == *head){
        printf("ERROR : No Nodes to Delete\n");
        return;
    }

    *head = (*temp).link;
    free(temp);
}

void deleteAtLast(struct Node** head){
    struct Node* temp = *head;

    if (NULL == *head){
        printf("ERROR : No Nodes to Delete\n");
        return;
    }

    if(NULL == (*temp).link){
        *head = NULL;
        free(temp);
        return;
    }

    while(NULL != (*(*temp).link).link){
        temp = (*temp).link;
    }

    struct Node* martyr = (*temp).link;
    (*temp).link = NULL;
    free(martyr);

}

void deleteAtN(struct Node** head, int n){

    int num = NoOfNodes(*head);

    if(n > num || n < 1){
        printf("ERROR : Invalid Position\n");
        return;
    }

    struct Node* temp = *head;

    if (1 == n){
        *head = (*temp).link;
        free(temp);
        return;
    }

    for (int i = 0; i < n-1; i++){
        temp = (*temp).link;
    }

    struct Node* martyr = (*temp).link;
    (*temp).link = (*martyr).link;
    free(martyr);

}

void reverse (struct Node** head){

    struct Node* prev, *current, *next;
    prev = NULL;
    current = *head;

    if(NULL == *head || NULL == (*current).link){
        printf("ERROR : Not Enough Nodes to Reverse\n");
        return;
    }

    while (NULL != current){
        next = (*current).link;
        (*current).link = prev;
        prev = current;
        current = next;
    }

    *head = prev;

}

struct Node* reverseWithRecursion(struct Node* head){

    if(NULL == head || NULL == (*head).link){
        return head;
    }

    struct Node* pshead = reverseWithRecursion((*head).link);
    (*(*head).link).link = head;
    (*head).link = NULL;

    return pshead;

}

void print (struct Node* head){
    while(NULL != head){
        printf("%d -> ", (*head).data);
        head = (*head).link;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head = NULL;
    int data = 0;
    int p = 0;
    int total = 0;
    
    int choice = 0;
    while(5 != choice){
        printf("========OPERATIONS ON LINKED LIST========\n\t 1. Insert a NODE\n\t 2. Delete a NODE\n\t 3. Reverse all the NODES\n\t 4. Show all the NODES\n\t 5. EXIT\n=========================================\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: {
            int schoice = 0;
            while(4 != schoice){
                printf("==========INSERTION OF NODE==========\n\t 1. Insert a NODE at Beginning\n\t 2. Insert a NODE at Last\n\t 3. Insert a Node at any Position\n\t 4. EXIT\n=====================================\n");
                scanf("%d", &schoice);

                switch (schoice)
                {
                case 1:

                    printf("Enter the Data you want to Insert in a Node\n");
                    scanf("%d", &data);

                    insertAtB(&head, data);
                    printf("NODE INSERTED AT THE BEGINNING OF THE LINKED LIST\nNumber of NODES are : ");
                    total = NoOfNodes(head);
                    printf("%d\n", total);
                    break;
                
                case 2:

                    printf("Enter the Data you want to Insert in a Node\n");
                    scanf("%d", &data);

                    insertAtlast(&head, data);
                    printf("NODE INSERTED AT THE LAST OF THE LINKED LIST\nNumber of NODES are : ");
                    total = NoOfNodes(head);
                    printf("%d\n", total);
                    break;

                case 3:
                
                    printf("Enter the Data you want to Insert in a Node\n");
                    scanf("%d", &data);

                    printf("In which Position You want insert the NODE\nThe Number of NODES are : ");
                    total = NoOfNodes(head);
                    printf("%d\n", total);
                    scanf("\n%d", &p);

                    insertAtN(&head, data, p);
                    printf("NODE INSERTED AT %d POSITION OF THE LINKED LIST\nNumber of NODES are : ", p);
                    total = NoOfNodes(head);
                    printf("%d\n", total);
                    break;
                case 4:
                    break;

                default:
                    printf("ERROR : Enter a valid Option\n");
                    break;
                }
            }
            break;
        }
        case 2: {
            int tchoice = 0;
            while(4 != tchoice){
                printf("==========DELETION OF NODE==========\n\t 1. Delete a NODE at Beginning\n\t 2. Delete a NODE at Last\n\t 3. Delete a Node at any Position\n\t 4. EXIT\n====================================\n");
                scanf("%d", &tchoice);

                switch (tchoice)
                {
                case 1:
                    
                    deleteAtB(&head);
                    printf("THE BEGINNING NODE OF THE LINKED LIST DELETED\nNumber of NODES are : ");
                    total = NoOfNodes(head);
                    printf("%d\n", total);
                    break;
                
                case 2:

                    deleteAtLast(&head);
                    printf("THE LAST NODE OF THE LINKED LIST DELETED\nNumber of NODES are : ");
                    total = NoOfNodes(head);
                    printf("%d\n", total);
                    break;

                case 3:

                    printf("In which Position You want Delete the NODE\nThe Number of NODES are : ");
                    total = NoOfNodes(head);
                    printf("%d\n", total);
                    scanf("\n%d", &p);

                    deleteAtN(&head, p);
                    printf("THE %d POSITION NODE OF THE LINKED LIST DELETED\nNumber of NODES are : ", p);
                    total = NoOfNodes(head);
                    printf("%d\n", total);
                    break;

                case 4:
                    break;

                default:
                    printf("ERROR : Enter a valid Option\n");
                    break;
                }
            }
            break;
        }

        case 3: {
            int fchoice = 0;
            while(3 != fchoice){
                printf("==========REVERSE OF LINKED LIST==========\n\t 1. Reverse\n\t 2. Reverse with Recursion\n\t 3. EXIT\n==========================================\n");
                scanf("%d", &fchoice);

                switch (fchoice)
                {
                case 1:
                    printf("PREVIOUS LIST\n");
                    print(head);
                    reverse(&head);
                    printf("LIST REVERSED, NEW LIST\n");
                    print(head);
                    break;

                case 2: 
                    printf("PREVIOUS LIST\n");
                    print(head);
                    head = reverseWithRecursion(head);
                    printf("LIST REVERSED, NEW LIST\n");
                    print(head);
                    break;

                case 3:
                    break;
                
                default:
                    printf("ERROR : Enter a valid Option\n");
                    break;
                }
            }
            break;
        }

        case 4:
            printf("LIST\n");
            print(head);
            break;

        case 5:
            break;
        
        default:
            printf("ERROR : Enter a valid Option\n");
            break;
        }
    }
    return 0;
}