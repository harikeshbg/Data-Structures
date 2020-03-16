#include<stdio.h>
void toh(int n,char s,char d,char a);
main()
{
    int n;
    printf("Enter the number of disks\n");
    scanf("%d",&n);
    toh(n,'A','C','B');
}
void toh(int n,char s,char d,char a)
{
    if(n==1)
      {
        printf("Move disk 1 from peg %c to peg %c\n",s,d);
        return;
      }
        toh(n-1,s,a,d);
        printf("Move disk %d from peg %c to peg %c\n",n,s,d);
        toh(n-1,a,d,s);
}
