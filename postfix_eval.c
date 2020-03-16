#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define size 50
struct stack
{
    int data[size];
    int top;
};
struct stack s;
void push(int e)
{
    s.data[++s.top]=e;
}
int pop()
{
    return(s.data[s.top--]);
}
int values[26][2]={0};
main()
{
    s.top=0;
    int i,op1,op2,res,check;
    char ch;
    char postfix[50];
    printf("Enter a valid postfix expression:");
    gets(postfix);
    puts(postfix);
    i=0;
    while(postfix[i]!='\0')
    {
        ch=postfix[i];
        if(isdigit(ch))
        {
            push(ch-'0');
            i++;
            printf("stacktop=%d\n",s.data[s.top]);
        }
        else
        if(isalpha(ch))
        {
                if(isupper(ch))
                    ch=tolower(ch);
                if(values[ch-97][1]==0)
                    {
                        printf("Enter the value of %c:",ch);
                        scanf("%d",&values[ch-97][0]);
                        printf("%d",values[ch-97][0]);
                        values[ch-97][1]=1;
                        push(values[ch-97][0]);
                        printf("stacktop=%d\n",s.data[s.top]);
                        i++;

                    }
                else
                    {
                        push(values[ch-97][0]);
                        i++;
                    }
        }
        else
        {
            printf("%c\n",ch);
            op2=pop();
            printf("op1=%d\n",op2);
            op1=pop();
            printf("op1=%d\n",op1);
            switch(ch)
            {
                case '+':res=op1+op2;
                         break;
                case '-':res=op1-op2;
                         break;
                case '*':res=op1*op2;
                         break;
                case '/':res=op1/op2;
                         break;
                case '%':res=op1%op2;
                         break;
            }
            push(res);
            i++;
        }

    }
    res=pop();
    printf("result=%d",res);

}
