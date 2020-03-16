#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define size 50

struct stack
{
    int data[size];
    int top;
};
struct stack s;
int values[26][2];
void push(int e)
{
    s.data[++s.top]=e;
}
int pop()
{
    return(s.data[s.top--]);
}
char prefix[50];
main()
{
    s.top=0;
    int i=0,op1,op2,res;
    char ch;
    printf("Enter a valid prefix expression:");
    gets(prefix);
    puts(prefix);
    strrev(prefix);
    while(prefix[i]!='\0')
    {
        ch=prefix[i];
        if((isdigit(ch)))
        {
           push(ch-'0');
           i++;
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
           op1=pop();
           op2=pop();
           switch(ch)
           {
              case '+': res=op1+op2;
                        break;
              case '-': res=op1-op2;
                        break;
              case '*': res=op1*op2;
                        break;
              case '/': res=op1/op2;
                        break;
              case '%': res=op1%op2;
                        break;
           }
           push(res);
           i++;

        }

    }
    printf("result=%d",res);
    i++;
}
