#include <stdio.h>
#include <stdlib.h>
#define size 7
struct stack
{
    int data[size];
    int top;
};
struct stack s;
int isempty();
int isoverflow();
int isunderflow();
void push(int element);
int pop();
void display();
int isempty()
{
    if(s.top==-1)
        return 1;
    else
        return 0;
}
int isoverflow()
{
    if(s.top>=size-1)
        return 1;
    else
        return 0;
}
int isunderflow()
{
    if(s.top==-1)
        return 1;
    else
        return 0;
}
void push(int element)
{
    if(isoverflow())
    {
        printf("stack overflown...\n");
        return;
    }
    s.data[++s.top]=element;
}
int pop()
{
    if(isunderflow())
    {
        printf("stack is underflown....\n");
        return -1;
    }
    return(s.data[s.top--]);
}
void display()
{
    int index;
    if(isempty())
    {
        printf("stack is empty...\n");
        return;
    }
    printf("stack elements are:\n");
    for(index=s.top;index>=0;index--)
        printf("%d\n",s.data[index]);
}
int main()
{
    int element,choice;
    s.top=-1;
    do
    {
        printf("1.push\n2.pop\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("enter the value to be pushed:");
                     scanf("%d",&element);
                     push(element);
                     break;
            case 2 : element=pop();
                     if(element!=-1)
                        printf("Popped item is %d",element);
                     break;
            case 3 : display();
                     break;
            case 4 : exit(0);
                     break;
            default: printf("Invalid choice....\n");
        }
    }while(1);
}

