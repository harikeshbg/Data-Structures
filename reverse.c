#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *next;
};

typedef struct Node *NODE;

void display(NODE list)
{
    NODE temp;
    if(list==NULL)
    {
        printf("List is Empty...\n");
        return;
    }
    temp=list;
    printf("The list elements are...\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->next;
    }
    printf("\n");
}

NODE deletion(NODE list)
{
    NODE temp;
    if(list==NULL)
    {
        printf("List doesn't contains any elements...\n");
        return(list);
    }
    temp=list;
    list=list->next;
    printf("Deleted element is %d\n",temp->info);
    free(temp);
    return(list);
}

NODE insert(NODE list,int ele)
{
    NODE newn,temp;
    newn=(NODE)malloc(sizeof(struct Node));
    if(newn==NULL)
    {
        printf("Memory allocation error...\n");
        return(list);
    }
    newn->info=ele;
    newn->next=NULL;
    if(list==NULL)
    {
        list=newn;
        return(list);
    }
    else
    {
        temp=list;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newn;
    }
    return(list);
}

NODE insertAtPos(NODE list,int ele,int pos)
{
    NODE newn,temp,prev;
    int c=2;
    newn=(NODE)malloc(sizeof(struct Node));
    if(newn==NULL)
    {
        printf("Memory allocation error...\n");
        return(list);
    }
    newn->info=ele;
    newn->next=NULL;
    if(list==NULL&&pos==1)
        return(newn);
    if(pos==1)
    {
        newn->next=list;
        return(newn);
    }
    temp=list->next;
    prev=list;
    while(temp!=NULL&&c!=pos)
    {
        prev=temp;
        temp=temp->next;
        c++;
    }
    if(temp==NULL&&pos==c)
        prev->next=newn;
    else if(pos>=c&&temp!=NULL)
         {
             prev->next=newn;
             newn->next=temp;
         }
         else
            printf("Invalid position...\n");
    return(list);
}

NODE reverse(NODE list)
{
    NODE temp,prev;
    if(list==NULL||list->next==NULL)
        return(list);
    temp=list->next;
    prev=list;
    list->next=NULL;
    while(temp!=NULL)
    {
        prev=temp;
        temp=temp->next;
        prev->next=list;
        list=prev;
    }
    return(list);
}

int main()
{
    int ele,in,pos,ch;
    NODE start=NULL;
    do
    {
        printf("1.Insertion\n2.Delete\n3.Display\n4.Reverse the list\n5.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :printf("1.Inserting a node at end\n2.Inserting a node at the specified position\nEnter your choice:");
                    scanf("%d",&in);
                    switch(in)
                    {
                        case 1 :printf("Enter element to be insert:");
                                scanf("%d",&ele);
                                start=insert(start,ele);
                                break;
                        case 2 :printf("Enter an element to be insert:");
                                scanf("%d",&ele);
                                printf("Enter the position where the element %d is to be insert:",ele);
                                scanf("%d",&pos);
                                start=insertAtPos(start,ele,pos);
                                break;
                        default:printf("Invalid choice...\n");
                                break;
                    }
                    break;
            case 2 :start=deletion(start);
                    break;
            case 3 :display(start);
                    break;
            case 4 :start=reverse(start);
                    break;
            case 5 :exit(1);
                    break;
            default:printf("Invalid choice...\n");
                    break;
        }
    }while(1);
    return(0);
}
