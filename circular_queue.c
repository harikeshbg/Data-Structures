#include<stdio.h>
#include<stdlib.h>
#define size 3
struct queue
{
    int data[size];
    int front,rear;
};
struct queue q;
void insert()
{
    if((q.front==0&&q.rear==size-1)||(q.rear==q.front-1))
    {
        printf("Queue overflown...\n");
        return;
    }
    if(q.front==-1)
        q.front=q.rear=0;
    else
    {
        q.rear=(q.rear+1)%size;
    }
    printf("Enter the element to be inserted:");
    scanf("%d",&q.data[q.rear]);
    printf("Inserted element is:%d\n",q.data[q.rear]);
}
void del()
{
    if(q.rear==-1)
    {
        printf("Queue underflown..\n");
        return;
    }
    else
    {
        if(q.front==q.rear)
        {
            printf("Deleted element is:%d\n",q.data[q.front]);
            q.front=q.rear=-1;
        }
        else
        {
            printf("Deleted element is:%d\n",q.data[q.front]);
            q.front=(q.front+1)%size;
        }
    }
}
void display()
{
    int temp;
    if(q.rear==-1)
        printf("Queue is empty..\n");
    else
    {
        temp=q.front;
        printf("Queue elements are:\n");
        while((temp%size)!=q.rear)
        {
            printf("temp=%d\n",temp);
            printf("%d\t",q.data[temp%size]);
            temp++;
        }
        temp=temp%size;
        printf("temp=%d\n",temp);
        printf("%d",q.data[temp]);
        printf("\n");
    }
}
int main()
{
    q.front=-1;
    q.rear=-1;
    int choice;
    do
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice..");
            break;
        }
    }
    while(1);
    return 0;
}
