#include<stdio.h>

int main()
{
    long long int n=0,h=0;
    scanf("%lld %lld",&n,&h);
    long long int delta=0;
    long long int pre =h,cur =0;
    while (scanf("%lld",&cur)!=EOF)
    {
        if(pre>cur)
        {
            delta += (pre-cur);
        }
        pre=cur;
    }
    printf("%lld\n",delta);
    return 0;
}