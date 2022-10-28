#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

// Creating structure for Node
struct Node
{
    int info;
    struct Node * next,*prev;
};

struct Node *head = NULL;

//Creating Node
struct Node * CreateNode()
{
   struct Node *NewNode;
   int Val;
   printf("\nEnter value to be inserted : ");
   scanf("%d",&Val);
   NewNode = (struct Node * )malloc(sizeof(struct Node));
   NewNode->info = Val;
   NewNode->next = NULL;
   NewNode->prev = NULL;
   return(NewNode);   
}

//Creating Doubly Linked list 
struct Node * CreateDLL(struct Node *head)
{
    struct Node *ptr,*qtr;
    int ch = 0;
   
    printf("\nLets Create DOUBLY LINKED LIST\n ");
    do
    {
        ptr = CreateNode();
        if(head == NULL)
        {
            head = ptr;
        }
        else
        {
            qtr = head;
            while(qtr->next!=NULL)
            {
                qtr = qtr->next ;
            }

            qtr->next = ptr;
            ptr->prev = qtr;
        }
        printf("\nDo you want to add more values (0/1) : ");
        scanf("%d",&ch);
    }while(ch!=0);

    return(head);
}

//Displaying Doubly Linked List
struct Node * DisplayDLL(struct Node * head)
{
    struct Node * ptr;
    ptr = head;
    if(head == NULL)
    {
        printf("\nEMPTY DOUBLY LIST !!");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf(" %d ",ptr->info);
            ptr = ptr->next;
        }
    }
    return(head);
}
// Updating Doubly Linked List
struct Node * UpdateDLL(struct Node * head)
{
    int old,new;
    struct Node * ptr;
    ptr = head;
    printf("\nEnter the old value : ");
    scanf("%d",&old);
    printf("\nEnter the new value : ");
    scanf("%d",&new);
    while(ptr!=NULL)
    {
        if(ptr->info == old)
        {
            ptr->info = new;
        }      
        ptr = ptr->next;
        
    }   
    printf("\nValue Updated !!"); 
    return(head);
}

//Inserting at Beginning
struct Node * InsertAtBeg(struct Node * head)
{
    struct Node *newNode;
    newNode = CreateNode();
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    printf("\nNode inserted at BEGINNING !!!");
    return(head);
}

// Inserting In between 
struct Node * InsertInBetween(struct Node *head)
{
    int pos=0,count=1;
    struct Node *NewNode ,*ptr;
    ptr = head;
    printf("\nEnter the position : ");
    scanf("%d",&pos);
    NewNode = CreateNode();
    while(count<pos-1)
    {
        ptr = ptr->next;
        count++;
    }

    NewNode->next = ptr->next;
    NewNode->prev = ptr;
    ptr->next->prev = NewNode;
    ptr->next = NewNode;
    printf("\nNode inserted in BETWEEN !!!");
    return(head);
}

//Inserting at End
struct Node * InsertAtEnd(struct Node *head)
{
    struct Node *newNode, *ptr;
    newNode = CreateNode();
    ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev=ptr;
    printf("\nNode inserted at END !!!");
    return(head);
    
}

//Deleting at beginning
struct Node * DeleteAtBeg(struct Node *head)
{
    struct Node * ptr;
    ptr = head;
    head = ptr->next;
    head->prev = NULL;
    printf("\nNode Deleted from BEGINNING !!!");
    return(head);
}

//Deleting in Between
struct Node * DeleteInBetween(struct Node *head)
{
    struct Node *ptr,*qtr;
    int count=1,pos;
    ptr = head;
    printf("\nEnter the position : ");
    scanf("%d",&pos);
    while(count<pos-1)
    {
        ptr = ptr->next;
        count++;
    }
    ptr->next = ptr->next->next;
    ptr->next->next->prev = ptr;
    printf("\nNode Deleted from Between !!!");
    return(head);
}

//Deleting At end 
struct Node * DeleteAtEnd(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    while(ptr->next->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = NULL;
    printf("\nNode Deleted from END !!!");
    return (head);
}


int main()
{
    int ch1;
    do{
        printf("\n\t\t DOUBLY LINKED LIST \n");
        printf("\n\t1. Create List");
        printf("\n\t2. Display List");
        printf("\n\t3. Update ");
        printf("\n\t4. Insert at Beginning");
        printf("\n\t5. Insert in Between");
        printf("\n\t6. Insert at End  ");
        printf("\n\t7. Delete in Beginning ");
        printf("\n\t8. Delete in Between ");
        printf("\n\t9. Delete in End  ");
        printf("\n\t0. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &ch1);
    
    switch (ch1)
    {
        case 1:
            head = CreateDLL(head);
            break;
        case 2:
            head = DisplayDLL(head);
            break;
        case 3:
            head = UpdateDLL(head);
            break;
        case 4:
            head = InsertAtBeg(head);
            break;
        case 5:
            head = InsertInBetween(head);
            break;
        case 6:
            head = InsertAtEnd(head);
            break; 
        case 7:
            head = DeleteAtBeg(head);
            break;
        case 8:
            head = DeleteInBetween(head);
            break;
        case 9:
            head = DeleteAtEnd(head);
            break;
        case 0:
            printf("\nThank you!!!");
            exit(0);
    }
    }while(1);

}
