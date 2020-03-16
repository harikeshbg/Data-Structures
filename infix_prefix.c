#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define size 50
int precedence(char ch);
void infix_postfix();
void push(int e);
char pop();
char reverse(char expression);
struct stack
{
    char data[size];
    int top;
};
struct stack s;
char infix[100];
char postfix[100];
void push(int e)
{
    s.data[++s.top]=e;
}
char  pop()
{
    return(s.data[s.top--]);
}
main()
{
    char prefix[100];
    s.top=0;
    s.data[s.top]='@';
    printf("Enter the valid infix expression:\n");
    gets(infix);
    printf("Entered infix expression is:");
    puts(infix);
    printf("Reversed infix:");
    strrev(infix);
    puts(infix);
    infix_postfix();
    printf("Generated postfix with reverse associativity:");
    puts(postfix);
    strrev(postfix);
    printf("Prefix expression:");
    puts(postfix);

}
int precedence(char ch)
{
    switch(ch)
    {
        case '@' : return 0;break;
        case ')' : return 1;break;
        case '+' :
        case '-' : return 2;break;
        case '*' :
        case '%' :
        case '/' : return 3;break;
        case '^' : return 4;break;

    }
}
void infix_postfix()//This will generate a postfix expression with the reverse associativity of operators.
{
    int i=0,j=0;
    char dat,ch;
    while(infix[i]!='\0')
    {
        dat=infix[i];
        if(dat==')')
            push(dat);
        else
        if(dat=='(')
        {
            ch=pop();
            while(ch!=')')
                {
                    postfix[j++]=ch;
                    ch=pop();
                }
        }
        else
        if(isalpha(dat)||isdigit(dat))
            {
                postfix[j++]=dat;
            }

        else
        {
            if(precedence(dat)>precedence(s.data[s.top]))
                    push(dat);
            else
                if(precedence(dat)<=precedence(s.data[s.top]))
                    {
                        while(precedence(dat)<precedence(s.data[s.top]))
                                postfix[j++]=pop();
                        push(dat);
                    }
        }
        i++;
    }
    while(s.data[s.top]!='@')
        postfix[j++]=pop();
    postfix[j]='\0';
    //printf("Postfix expression:");
    //puts(postfix);
}

