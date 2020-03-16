#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define size 3
void insert(int element);
void del();
void display();
int overflow();
int underflow();
struct queue
{
    int data[size];
    int front;
    int rear;
}s;
main()
{
    s.front=-1;
    s.rear=-1;
    int choice,element;
    do
        {
            printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
            printf("Enter your choice:");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1 : printf("Enter the element to be inserted:");
                         scanf("%d",&element);
                         insert(element);
                         break;
                case 2 : del();
                         break;
                case 3 : display();
                         break;
                case 4 : exit(0);
                         break;
                default: printf("Invalid choice\n");
                         break;
            }
        }while(1);
}

void insert(int element)
{
    if(overflow())
       {
         printf("Queue is overflown..\n");
         return;
       }
    else
        {
            s.data[++s.rear]=element;
            if(s.front==-1)
                s.front=0;
            printf("front=%d\n",s.front);
            printf("rear=%d\n",s.rear);
        }
}
void del()
{
    if(underflow())
    {
        printf("queue under flown...\n");
        return;
    }
    else
        {
            printf("deleted item is:%d\n",s.data[s.front]);
            s.front++;
            printf("front=%d\n",s.front);
            printf("rear=%d\n",s.rear);
        }
}
void display()
{
    int n=s.rear;
    if(s.rear==-1)
        printf("queue is empty\n");
    else
    {
        printf("Queue elements are:\n");
        while(n>=s.front)
            printf("%d\n",s.data[n--]);
    }
}
int overflow()
{
    if(s.rear>=size-1)
        return 1;
    else
        return 0;
}
int underflow()
{
    if(s.rear==-1&&s.front==-1)
        return 1;
    else
        return 0;
}
