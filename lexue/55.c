# include<stdio.h>
int sum (int a,int b)
{
    return a==b?a:sum(a+1,b)+a;
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("The sum from %d to %d is %d.\n",a,b,sum(a,b));
    return 0;
}