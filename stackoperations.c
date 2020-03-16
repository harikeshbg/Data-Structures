#include<stdio.h>
#include<stdlib.h>
#define size 10
struct stack
{
    int data[size];
    int top;
};
struct stack s;
void push(int element);
int pop();
void display();
int underflow();
int overflow();
main()
{
    s.top=-1;
    do
    {
        int choice,element;
        printf("1.push\n2.pop\n3.display\n4.exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the value to be pushed:");
                     scanf("%d",&element);
                     push(element);
                     break;
            case 2 : element=pop(&s);
                     printf("Popped item is %d\n",element);
                     break;
            case 3 : display();
                     break;
            case 4 : exit(0);
                     break;

        }
     }while(1);
}

int underflow()
{
    if(s.top>-1)
        return 0;
    else
        return 1;
}
int overflow()
{
    if(s.top>=size-1)
        return 1;
    else
        return 0;
}
void push(int e)
{
    if(overflow())
        printf("Stack over flown\n");
    else
        {
            s.data[++s.top]=e;
        }
}
int pop()
{
    if(underflow())
        printf("Stack under flown..\n");
    else
        return(s.data[s.top--]);
}
void display()
{
    int i;
    for(i=s.top;i>=0;i--)
        printf("%d\n",s.data[i]);
}
