#include<stdio.h>
void fibonacci(int fib1,int fib2,int n);
main()
{
    int fib1,fib2,n;
    fib1=0;
    fib2=1;
    printf("Enter the value of n:");
    scanf("%d",&n);
    fibonacci(fib1,fib2,n);
    printf("%d",3);
}
void fibonacci(int fib1,int fib2,int n)
{
    int temp;
    printf("%d\t",fib1);
    printf("%d\t",fib2);
    if(fib2>=n)
        return;
    else
    {
        temp=fib1;
        fib1=fib2;
        fib2=temp+fib2;
        fibonacci(fib1,fib2,n);
    }
}
