/*Program to find the union and intersection of two lists*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node *NODE;
NODE ulist=NULL,ilist=NULL;
NODE insert_sort(NODE list,int e)
{
    NODE newN,temp=NULL,prev=NULL;
    newN=(NODE)malloc(sizeof(struct node));
    newN->info=e;
    newN->next=NULL;
    temp=list;
    if(newN==NULL)
    {
        printf("Memory allocation error..");
        return list;
    }
    if(list==NULL)
    {
        list=newN;
        return list;

    }
    else
    {
        temp=list;
        prev=list;
        if(newN->info<list->info)
        {
            newN->next=list;
            list=newN;
            return list;
        }
        else
        {
            while(temp!=NULL&&newN->info>temp->info)
            {
                prev=temp;
                temp=temp->next;
            }
            newN->next=prev->next;
            prev->next=newN;
            return list;

        }
    }
}
void display(NODE list)
{
    NODE temp;
    if(list==NULL)
    {
        printf("List is empty..");
        return;
    }
    temp=list;
    while(temp!=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->next;
    }
}
void uni(NODE l1,NODE l2)
{
    int status;
    if(l1==NULL)
    {
        ulist=l2;
        return;
    }
    if(l2==NULL)
    {
        ulist=l1;
        return;
    }
    while(l1!=NULL)
    {
        status=search(ulist,l1->info);
        if(status==0)
        {
            ulist=insert_sort(ulist,l1->info);
            l1=l1->next;
        }
        else
            l1=l1->next;
    }
     while(l2!=NULL)
    {
        status=search(ulist,l2->info);
        if(status==0)
        {
            ulist=insert_sort(ulist,l2->info);
            l2=l2->next;
        }
        else
            l2=l2->next;
    }
}
void inter(NODE l1,NODE l2)
{
    int status;
    if(l1==NULL||l2==NULL)
    {
        ilist=NULL;
        return;
    }
    while(l1!=NULL)
    {
        status=search(l2,l1->info);
        if(status==1&&!(search(ilist,l1->info)))
            ilist=insert_sort(ilist,l1->info);
            l1=l1->next;
    }
     while(l2!=NULL)
    {
        status=search(l1,l2->info);
        if(status==1&&!(search(ilist,l2->info)))
            ilist=insert_sort(ilist,l2->info);
            l2=l2->next;
    }

}
int search(NODE list,int e)
{
    NODE temp;
    temp=list;
    while(temp!=NULL)
    {
        if(temp->info==e)
            return 1;
        else
            temp=temp->next;
    }
    return 0;
}
main()
{

    int choice,e;
    NODE l1=NULL,l2=NULL;
    do
    {
        printf("\n1.Insert-l1\n2.Insert-l2\n3.Display-l1\n4.Display-l2\n5.Union\n6.Intersection\n7.Display-ulist\n8.Display-ilist\n9.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:printf("Enter the element:");
               scanf("%d",&e);
               l1=insert_sort(l1,e);break;
        case 2:printf("Enter the element:");
               scanf("%d",&e);
               l2=insert_sort(l2,e);break;
        case 3:printf("\nElements of list-1:\n");
               display(l1);break;
        case 4:printf("\nElements of list-2:\n");
               display(l2);break;
        case 5:uni(l1,l2);break;
        case 6:inter(l1,l2);break;
        case 7:printf("\nUnion of two lists:\n");
               display(ulist);break;
        case 8:printf("\nIntersection of two lists:\n");
               display(ilist);break;
        case 9:exit(0);break;
        default:printf("invalid choice..");break;

        }
    }while(1);

}
