#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int info;
    struct Node *next;
};

typedef struct Node *NODE;

NODE endp=NULL;

NODE insert(NODE list,int ele,int sval,NODE head)
{
    NODE newn,temp;
    newn=(struct Node *)malloc(sizeof(struct Node));
    if(newn==NULL)
    {
        printf("Memory allocation error...\n");
        return(list);
    }
    newn->info=ele;
    newn->next=newn->prev=NULL;

    if(list==NULL)
    {
        list=newn;
        endp=newn;
        head->info++;
        return(list);
    }
    temp=list;
    while(temp!=NULL&&temp->info!=sval)
        temp=temp->next;
    if(temp!=NULL)
    {
        newn->next=temp->next;
        if(temp->next==NULL)
        {
            temp->next=newn;
            newn->prev=temp;
            head->info++;
            endp=newn;
        }
        else
        {
            temp->next->prev=newn;
            temp->next=newn;
            newn->prev=temp;
            head->info++;
        }
        return(list);
    }
    else
    {
        printf("Node information is not found\n");
        free(newn);
        return(list);
    }
}

NODE deletion(NODE list,NODE head)
{
    NODE temp=list;
    NODE p;
    if(temp==NULL)
    {
        printf("List is Empty...\n");
        return(list);
    }
    while(temp->prev!=NULL)
        temp=temp->prev;
    if(temp->next==NULL)
    {
        printf("Deleted element is %d\n",temp->info);
        free(temp);
        if(head->info==-1)
            head->info=0;
        else
            head->info--;
        endp=NULL;
        return(NULL);
    }
    else
    {
        p=temp->next;
        p->prev=NULL;
        printf("Deleted element is %d\n",temp->info);
        free(temp);
        if(head->info==-1)
            head->info=0;
        else
            head->info--;
        return(p);
    }
}

NODE deletePos(NODE list,int pos)
{
    NODE temp,before=NULL;
    int count=1;
    temp=list;
    while(count!=pos)
    {
        before=temp;
        temp=temp->next;
        count++;
    }
    if(before==NULL&&temp->next==NULL)
        list=NULL;
    else
    {
        if(before==NULL)
        {
            list=temp->next;
            list->prev=NULL;
        }
        else if(temp->next==NULL)
             {
                  before->next=NULL;
                  endp=before;
             }
             else
             {
                 before->next=temp->next;
                 temp->next->prev=before;
             }
    }
    printf("Deleted element is %d\n",temp->info);
    free(temp);
    return(list);
}

void display(NODE list)
{
    NODE temp=list;
    if(temp==NULL)
        printf("List is Empty...\n");
    else
    {
        printf("List elements are...\n");
        while(temp!=NULL)
        {
            printf("%d\t",temp->info);
            temp=temp->next;
        }
        printf("\n");
    }
}

void swap(NODE list,int m,int n)
{
    NODE temp,prev,before;
    int i,k,x;
    temp=list;
    if(m>n)
        k=m;
    else
        k=n;
    for(i=1;i<=k;i++)
    {
        if(i==m)
            before=temp;
        if(i==n)
            prev=temp;
        temp=temp->next;
    }
    x=before->info;
    before->info=prev->info;
    prev->info=x;
}

int main()
{
    NODE head;
    int ch,ele,pos,sval,m,n;
    printf("C Program on header node concept and to perform insertion, deletion and display operations.\n");
    head=(NODE)malloc(sizeof(NODE));
    if(head==NULL)
    {
        printf("Memory allocation error...\n");
        exit(1);
    }
    head->info=0;
    head->prev=NULL;
    head->next=NULL;
    do
    {
        printf("1.Insert a node next to info-field\n2.Delete first node\n3.Delete the specified node\n4.Display\n5.Swapping the nodes\n6.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :printf("Enter element to insert:");
                    scanf("%d",&ele);
                    printf("Enter info-field in the list:");
                    scanf("%d",&sval);
                    head->next=insert(head->next,ele,sval,head);
                    break;
            case 2 :head->next=deletion(endp,head);
                    break;
            case 3 :printf("Enter the position to be delete:");
                    scanf("%d",&pos);
                    if(head->info<=0||pos>head->info)
                        printf("Invalid position...\n");
                    else
                    {
                        head->next=deletePos(head->next,pos);
                        head->info--;
                    }
                    break;
            case 4 :display(head->next);
                    break;
            case 5 :printf("Enter two position to swap:");
                    scanf("%d%d",&m,&n);
                    if(m>head->info||n>head->info)
                        printf("Invalid positions...\n");
                    else
                        swap(head->next,m,n);
                    break;
            case 6 :exit(2);
                    break;
            default:printf("Invalid choice...\n");
                    break;
        }
    }while(1);
    return(0);
}

