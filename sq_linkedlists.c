#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

int countS=0;
int countQ=0;

struct Node
{
    int info;
    struct Node *next;
};

typedef struct Node *NODE;

NODE rear=NULL;
NODE front=NULL;
NODE top=NULL;

void insert(int ele)
{
    NODE newn;
    newn=(NODE)malloc(sizeof(NODE));
    if(newn==NULL||countQ>=SIZE)
    {
        printf("Queue is Overflow...\n");
        return;
    }
    newn->info=ele;
    newn->next=NULL;
    if(rear==NULL)
    {
        rear=newn;
        front=newn;
        countQ++;
        return;
    }
    rear->next=newn;
    rear=newn;
    countQ++;
    return;
}

void deletion()
{
    NODE temp;
    if(front==NULL)
    {
        printf("Queue is Underflow...\n");
        rear=front;
        return;
    }
    temp=front;
    front=front->next;
    printf("Deleted element is %d\n",temp->info);
    free(temp);
    if(front==NULL)
        rear=NULL;
}

NODE push(NODE list,int ele)
{
    NODE newn;
    newn=(NODE)malloc(sizeof(NODE));
    if(newn==NULL||countS>=SIZE)
    {
        printf("Stack is Overflow...\n");
        return(list);
    }
    countS++;
    newn->info=ele;
    newn->next=NULL;
    newn->next=list;
    return(newn);
}

NODE pop(NODE list)
{
    NODE temp;
    if(list==NULL)
    {
        printf("Stack is Underflow...\n");
        return(list);
    }
    temp=list;
    list=list->next;
    printf("Deleted element is %d\n",temp->info);
    free(temp);
    return(list);
}

void display(NODE list)
{
    NODE temp;
    if(list==NULL)
    {
        printf("List is Empty...\n");
        return;
    }
    temp=list;
    printf("List elements are...\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->next;
    }
    printf("\n");
}

void stackOperations()
{
    int ele,in;
    do
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&in);
        switch(in)
        {
            case 1 :printf("Enter element to be pushed:");
                    scanf("%d",&ele);
                    top=push(top,ele);
                    break;
            case 2 :top=pop(top);
                    break;
            case 3 :display(top);
                    break;
            case 4 :return;
                    break;
            default:printf("Invalid choice...\n");
                    break;
        }
    }while(1);
}

void queueOperations()
{
    int ele,in;
    do
    {
        printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&in);
        switch(in)
        {
            case 1 :printf("Enter element to be inserted:");
                    scanf("%d",&ele);
                    insert(ele);
                    break;
            case 2 :deletion();
                    break;
            case 3 :display(front);
                    break;
            case 4 :return;
                    break;
            default:printf("Invalid choice...\n");
                    break;
        }
    }while(1);
}

int main()
{
    int ch;
    do
    {
        printf("1.Operations on Stack\n2.Operations on Queue\n3.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :stackOperations();
                    break;
            case 2 :queueOperations();
                    break;
            case 3 :exit(0);
                    break;
            default:printf("Invalid choice...\n");
                    break;
        }
    }while(1);
    return(0);
}
