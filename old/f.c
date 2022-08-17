#include<stdio.h>
int main ()
{
    int n;
    long long m,l,r;
    scanf("%d %lld %lld %lld",&n,&m,&l,&r);
    const int N=n;
    long long dis[N+1];
    long long flag=0;
    int f=0,i;
    for(i=0;i<N;i++)
    {
        scanf("%lld",&dis[i]);
        if(l<=dis[i]&&r>=dis[i])
        {
            flag+=1;
            if(flag=m)
            {
                f=1;
                break;
            }
        else 
        {
            flag+=1;
            if(flag=m)
            {
                f=0;
                break;
            }
            flag+=1;
            if(flag=m)
            {
                f=1;
                break;
            }
        }
        }
    }
    if(f==1)printf("lzdak!");
    if(f==0)printf("%d",i-1);
    return 0;
}