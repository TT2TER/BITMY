#include<stdio.h>
#include<math.h>
int judge(int a,int n)
{   
    int ret;
    if (a%(n*n)!=0) return 0;
    else ret=1;
    a/=10;
    n--;
    return a==0?1:judge(a,n)*ret;
}
int main()
{
    int n;
    scanf("%d",&n);
    if(n==0||n==8|n==9)
    {printf("%d\n",0);
    return 0;}
    if(n==7)
    {printf("%d\n",1);
    return 0;}
    int i;
    int count=0;
    for(i=pow(10,n-1);i<pow(10,n);i++)
    {
        if(judge(i,n))count++;
    }
    printf("%d\n",count);
    return 0;
}