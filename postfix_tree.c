#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

struct node
{
    char info;
    struct node *lchild,*rchild;
};

typedef struct node *TREE;

TREE createTree(char postfix[])
{
    TREE newn,stack[20];
    int i=0;
    int top=-1;
    char ch;
    while((ch=postfix[i++])!='\0')
    {
        newn=(struct node*)malloc(sizeof(struct node));
        if(newn==NULL)
        {
            printf("Memory allocation error...\n");
            exit(1);
        }
        newn->info=ch;
        newn->lchild=newn->rchild=NULL;
        if(isalnum(ch))
            stack[++top]=newn;
        else
        {
            newn->rchild=stack[top--];
            newn->lchild=stack[top--];
            stack[++top]=newn;
        }
    }
    return(stack[top--]);
}

float eval(TREE root)
{
    float num;
    switch(root->info)
    {
        case '+' :return(eval(root->lchild)+eval(root->rchild));
                  break;
        case '-' :return(eval(root->lchild)-eval(root->rchild));
                  break;
        case '*' :return(eval(root->lchild)*eval(root->rchild));
                  break;
        case '/' :return(eval(root->lchild)/eval(root->rchild));
                  break;
        case '^' :return(pow(eval(root->lchild),eval(root->rchild)));
                  break;
        default  :if(isalpha(root->info))
                  {
                      printf("%c=",root->info);
                      scanf("%f",&num);
                      return(num);
                  }
                  else
                    return(root->info-'0');
                  break;
    }
}

int main()
{
    char postfix[30];
    float res;
    TREE root=NULL;
    printf("Enter valid postfix expression:");
    scanf("%s",postfix);
    root=createTree(postfix);
    res=eval(root);
    //strrev(postfix);
    printf("Result is %g\n",res);
    return(0);
}

