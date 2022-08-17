#include<stdio.h>
double sum(int n)
{
    if(n==1)
    return 1;
    if(n%2==0)
    return sum(n-1)+1.0/n;
    if(n%2!=0)
    return sum(n-1)-1.0/n;
}
int main()
{
    int n;
    scanf("%d",&n);
    double ans=sum(n);
    if(ans==(int)ans)
    printf("%d\n",(int)ans);
    else
    printf("%.6f\n",ans);
    return 0;
}