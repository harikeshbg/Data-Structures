#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int info;
    struct tree *lchild,*rchild;
};
typedef struct tree *TREE;
TREE root;
void insert()
{
    int e;
    TREE newn,cur=NULL,parent=NULL;
    printf("Enter the element to bw inserted:");
    scanf("%d",&e);
    newn=(TREE)malloc(sizeof(struct tree));
    newn->info=e;
    newn->lchild=newn->rchild=NULL;
    if(root==NULL)
        root=newn;
    else
    {
        cur=root;
        while(cur!=NULL)
        {
            parent=cur;
            if(e>cur->info)
                cur=cur->rchild;
            else
                if(e<cur->info)
                    cur=cur->lchild;
                else
                {
                    printf("Element is already present in the tree ");
                    return;
                }
        }
        if(e>parent->info)
            parent->rchild=newn;
        else
            parent->lchild=newn;
    }
    return;
}
void inorder(TREE root)
{
    TREE temp=root;
    if(temp!=NULL)
    {
        inorder(temp->lchild);
        printf("%d\n",temp->info);
        inorder(temp->rchild);
    }

}
void preorder(TREE root)
{
    TREE temp=root;
    if(temp!=NULL)
    {
        printf("%d\n",temp->info);
        preorder(temp->lchild);
        preorder(temp->rchild);
    }

}
void postorder(TREE root)
{
    TREE temp=root;
    if(temp!=NULL)
    {
        postorder(temp->lchild);
        postorder(temp->rchild);
        printf("%d\n",temp->info);
    }

}
void del()
{
    int key;
    TREE cur,parent,q,successor;
    printf("Enter the key element:");
    scanf("%d",&key);
    if(root==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    cur=root;parent=NULL;
    while(cur!=NULL)
    {
        if(cur->info==key)
           break;
        parent=cur;
        cur=(key>cur->info)?cur->rchild:cur->lchild;

    }
    if(cur==NULL)
    {
        printf("Key element not found\n");
        return;
    }
    if(cur->lchild==NULL)
        q=cur->rchild;
    else
        if(cur->rchild==NULL)
            q=cur->lchild;
        else
        {
            q=successor=cur->rchild;
            while(successor->lchild!=NULL)
                successor=successor->lchild;
            successor->lchild=cur->lchild;
        }
        if(parent==NULL)
            root=q;
        if(parent->rchild==cur)
           parent->rchild=q;
        else
           parent->lchild=q;
    printf("%d deleted",cur->info);
    free(cur);
    return;
}
main()
{
    int choice;
    do
    {
        printf("\n1.insert\n2.preorder\n3.postorder\n4.inorder\n5.delete\n6.exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert();break;
            case 2:preorder(root);break;
            case 3:postorder(root);break;
            case 4:inorder(root);break;
            case 5:del();break;
            case 6:exit(0);break;
            default:printf("Invalid choice\n");break;
        }
    }while(1);
}


