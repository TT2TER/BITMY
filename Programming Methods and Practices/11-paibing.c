#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;//a<b 从小到大
}

int main()
{
    long long int n,p;
    long long int x[100100]={0};
    long long int y[100100]={0};
    scanf("%lld",&n);
    p=n/2;
    long long int sum=0;
    for(long long int i=0;i<n;i++)  
    {  
        scanf("%lld  %lld",&x[i],&y[i]);  
    }
    qsort(x,n,sizeof(x[0]),compare);
    qsort(y,n,sizeof(y[0]),compare);
    long long int delta[100100]={0};
    for(long long int i=0;i<n;i++)
    {
        sum+=fabs(y[i]-y[p]);
        delta[i]=x[i]-i;
    }
    qsort(delta,n,sizeof(delta[0]),compare);
    for(long long int i=0;i<n;i++)
    {
        sum+=fabs(x[i]-i-delta[p]);
    }
    printf("%lld\n",sum);
    return 0;
}