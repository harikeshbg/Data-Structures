#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
struct node
{
    int dx,dy,dz,ce,pc;
    struct node*next;
};
typedef struct node *NODE;
NODE p1=NULL,p2=NULL,s=NULL,temps=NULL;
NODE read(NODE list)
{
    int ch;
    NODE newn;
    NODE temp=list;
    do
    {
        newn=(struct node*)malloc(sizeof(struct node));
        newn->pc=0;newn->next=NULL;
        printf("Enter the coefficient:");
        scanf("%d",&newn->ce);
        printf("Enter the degrees of x,y,z:\n");
        scanf("%d%d%d",&newn->dx,&newn->dy,&newn->dz);
        if(list==NULL)
        {
            list=newn;
            temp=newn;
        }
        temp->next=newn;
        temp=temp->next;
        printf("Do you want to continue?(T-1):");
        scanf("%d",&ch);
    }while(ch==1);
    return list;
}
void display(NODE list)
{
    NODE temp=list;
    while(temp!=NULL)
    {
        printf("Inside while");
        if(temp->ce!=0)
        {
            if(temp->ce>0)
                printf("+");
            printf("%dx^%dy^%dz^%d",temp->ce,temp->dx,temp->dy,temp->dz);
        }
        temp=temp->next;
    }
}
void add(NODE l1,NODE l2)
{
    NODE t1,t2,newn;
    t1=l1,t2=l2;
    if(l1==NULL)
    {
        s=l2;
        temps=l2;
    }
     if(l2==NULL)
    {
        s=l1;
        temps=l1;
    }
    while(t1!=NULL)
    {
        while(t2!=NULL)
        {
            newn=(struct node*)malloc(sizeof(struct node));
            newn->dx=t1->dx;
            newn->dy=t1->dy;
            newn->dz=t1->dz;
            newn->next=NULL;
            if(t1->dx==t2->dx&&t1->dy==t2->dy&&t1->dz==t2->dz&&t1->pc==0&&t2->pc==0)
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
            }
            else
                if(t1->pc==0&&t1->ce==0)
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
                t2=t2->next;
        }
        t2=l2;
        t1=t1->next;
    }
    while(t2!=NULL)
    {
            newn=(struct node*)malloc(sizeof(struct node));
            newn->dx=t2->dx;
            newn->dy=t2->dy;
            newn->dz=t2->dz;
            newn->ce=t2->ce;
            newn->next=NULL;
            if(t2->pc==0)
            {
                s->next=newn;
                s=s->next;
            }
            t2=t2->next;
            t2=t2->next;
    }
}
main()
{
   int ch;
   do
   {
       printf("\n1.Read-p1\n2.read-p2\n3.Add\n4.Display-p1\n5.Display-p2\n6.Display-s\n7.Exit\nEnter your choice:");
       scanf("%d",&ch);
       switch(ch)
       {
          case 1:p1=read(p1);break;
          case 2:p2=read(p2);break;
          case 3:add(p1,p2);break;
          case 4:display(p1);break;
          case 5:display(p2);break;
          case 6:display(temps);break;
          case 7:exit(0);break;
         default:printf("Invalid choice...");break;
       }
   }while(1);
}

