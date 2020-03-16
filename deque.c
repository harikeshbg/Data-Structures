#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int info;
    struct Node *next;
};

typedef struct Node *NODE;

NODE rear=NULL;
NODE front=NULL;

void insert(int flag)
{
    NODE newn;
    int ele;
    newn=(struct Node*)malloc(sizeof(struct Node));
    if(newn==NULL)
    {
        printf("Memory allocation error...\nQueue is Overflow...\n");
        return;
    }
    printf("\nEnter the data to be inserted\n");
    scanf("%d",&ele);
    newn->info=ele;
    newn->prev=NULL;
    newn->next=NULL;
    if(flag==1)
    {
        if(front==NULL)
        {
            rear=front=newn;
            return;
        }
        newn->next=front;
        front->prev=newn;
        front=newn;
        return;
    }
    else
    {
        if(rear==NULL)
        {
            rear=front=newn;
            return;
        }
        rear->next=newn;
        newn->prev=rear;
        rear=newn;
        return;
    }

}

void deletion(int flag)
{
    NODE temp;
    if(front==NULL)
    {
        printf("DEQUE is Empty...\n");
        return;
    }

    if(flag==1)
    {
        temp=front;
        printf("Deleted element is %d\n",temp->info);
        if(front->next!=NULL)
        {
            front=front->next;
            front->prev=NULL;
            return;
        }
        else
        {
            front=NULL;
            return;
        }
    }
    else
    {
        temp=rear;
        printf("Deleted element is %d\n",temp->info);
        if(rear->prev!=NULL)
        {
            rear=rear->prev;
            rear->next=NULL;
            return;
        }
        else
        {
            rear=NULL;
            return;
        }
    }
}

void DISPLAY(void)
{
	   NODE temp;
	   if(front==NULL)
	   {
		printf("\nDEQUEUE EMPTY\n");
		return;
	   }
	   temp=front;
	   printf("\nDEQUEUE CONTENTS:\nFRONT->");
	   while(temp!=NULL)
	   {
	       printf("%d->",temp->info);
	       temp=temp->next;
	   }
	   printf("REAR\n");
}


int main()
 {
     int choice;
     printf("C Program to implement DEQUE using Linked List concept\n");
     while(1)
     {
         printf("\n1:INSERT LEFT\n2:INSERT RIGHT\n3:REMOVE LEFT\n4:REMOVE RIGHT\n5:DISPLAY\n6:EXIT\n");
         printf("Enter your choice\n");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1: insert(1);
                     break;
             case 2: insert(0);
                     break;
             case 3: deletion(1);
                     break;
             case 4: deletion(0);
                     break;
             case 5: DISPLAY();
                     break;
             case 6: exit(0);
             default:printf("\nInvalid Choice\n");
          }
     }
     return(1);
}

