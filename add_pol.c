#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
struct node
{
    int dx,dy,dz,ce,pc;
    struct node *next;
};
typedef struct node*NODE;
NODE p1=NULL,p2=NULL,temps=NULL,s=NULL;
NODE read(NODE list)
{
    NODE temp=list,newn;int ch=0;
    do
    {
        newn=(NODE)malloc(sizeof(struct node));
        newn->next=NULL,newn->pc=0;
        printf("Enter the coefficient:");
        scanf("%d",&newn->ce);
        printf("Enter the degrees of x,y,z:\n");
        scanf("%d%d%d",&newn->dx,&newn->dy,&newn->dz);
        if(temp==NULL)
        {
            temp=newn;
            list=newn;
        }
        else
            {
                temp->next=newn;
                temp=temp->next;
            }
        printf("Do you want to continue(True-1):");
        scanf("%d",&ch);
    }while(ch==1);
    return list;
}
void display(NODE list)
{
    NODE temp;
    if(list==NULL)
    {
        printf("No polynomial\n");
        return;
    }
    temp=list;
    while(temp!=NULL)
    { if(temp->ce!=0)
        {if(temp->ce>0)
            printf("+");
        printf("%dx^%dy^%dz^%d",temp->ce,temp->dx,temp->dy,temp->dz);}
        temp=temp->next;
    }
    printf("\n");
}
void add(NODE l1,NODE l2)
{
    NODE newn,t1,t2;
    if(l1==NULL)
    {
        s=l2;
        return;
    }
    if(l2==NULL)
    {
        s=l1;
        return;
    }
    t1=l1;t2=l2;
    while(t1!=NULL)
    {
        newn=(NODE)malloc(sizeof(struct node));
        newn->next=NULL;
        newn->pc=0;
        newn->dx=t1->dx;
        newn->dy=t1->dy;
        newn->dz=t1->dz;
        while(t2!=NULL)
        {
            if(t1->dx==t2->dx&&t1->dy==t2->dy&&t1->dz==t2->dz&&t1->pc==0&&t2->pc==0&&t2->pc==0)
            {
                newn->ce=t1->ce+t2->ce;
                t1->pc=1;t2->pc=1;
                if(s==NULL)
                {
                    s=newn;
                    temps=newn;
                }
                else
                {
                    s->next=newn;
                    s=s->next;
                }
                break;
            }
            t2=t2->next;
         }
         if(t1->pc==0&&t1->ce!=0)
         {
            newn->ce=t1->ce;
            t1->pc=1;
            if(s==NULL)
            {
                s=newn;
                temps=newn;
            }
            else
            {
                s->next=newn;
                s=s->next;
            }
         }
        t2=l2;
        t1=t1->next;
    }
    t1=l1;t2=l2;
    while(t2!=NULL)
    {
       if(t2->pc==0&&t2->ce!=0)
        {newn=(NODE)malloc(sizeof(struct node));
        newn->next=NULL;
        newn->pc=0;
        newn->ce=t2->ce;
        newn->dx=t2->dx;
        newn->dy=t2->dy;
        newn->dz=t2->dz;
        s->next=newn;
        s=s->next;}
        t2=t2->next;
    }
}
int main()
{
    int ch;
    do
    {
        printf("\n1.Read-p1\n2.Read-p2\n3.Display-p1\n4.Display-p2\n5.Addition\n6.Display-sum\n7.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:p1=read(p1);break;
            case 2:p2=read(p2);break;
            case 3:display(p1);break;
            case 4:display(p2);break;
            case 5:add(p1,p2);break;
            case 6:display(temps);break;
            case 7:exit(0);break;
           default:printf("Invalid choice");break;
        }
    }while(1);
}

