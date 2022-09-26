#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b; 
}

int main()
{
    int n;
    scanf("%d",&n);
    long long int all[10010];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&all[i]);
    }
    long long int sum=0;
    long long int tmp;
    qsort(all,n,sizeof(all[0]),compare);
    for(int i=0;i<n-1;i++)
    {
        all[i + 1] += all[i];
        sum += all[i + 1];
        for (int j = i + 1; j < n - 1 && all[j] > all[j + 1]; j++)
        {
            tmp = all[j];
            all[j] = all[j + 1];
            all[j + 1] = tmp;
        }
    }
    printf("%lld\n",sum);
}