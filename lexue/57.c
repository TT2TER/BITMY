#include<stdio.h>
int gcd(int a,int b)
{
    return a%b?gcd(b,a%b):b;
}
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    printf("%d\n",gcd(m,n));
    return 0;
}
