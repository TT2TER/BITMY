#include<stdio.h>
int f=1;
long long gcd(long long a , long long b)
{
	return a%b?gcd(b,a%b):b;
}
long long lcm(long long a, long long b)
{
	return a/gcd(a,b)*b;
}
long long flag(long long a)
{   
    if(a<0)f=-1,a=-a;
    return a;
}
long long reflag(long long a)
{
    int ret= f*a;
    f=1;
    return ret;
}
int main()
{
    int n;
    scanf("%d",&n);
    const int N=n;
    int arr[2][N+2];
    long long i=1;
    while(scanf("%d/%d",&arr[0][i],&arr[1][i])!=EOF)i++;
    long long tm;
    long long tz;
    long long tarry[2]={arr[0][1],arr[1][1]};
    for(i=2;i<=N;i++)
    {
        tm=lcm(tarry[1],arr[1][i]);
        tz=flag(tarry[0]*tm/tarry[1]+arr[0][i]*tm/arr[1][i]);
        long long g=gcd(tz,tm);
        tarry[0]=reflag(tz)/g;
        tarry[1]=tm/g;
    }
    tarry[1]=tarry[1]*N;
    int c=1;
    if(tarry<0)c=-1;
    long long g=gcd(flag(tarry[0]),tarry[1]);
    tarry[0]=c*tarry[0]/g;
    tarry[1]=tarry[1]/g;
    if(tarry[1]==1)printf("%d",tarry[0]);
    else printf("%d/%d",tarry[0],tarry[1]);
    return 0;
}