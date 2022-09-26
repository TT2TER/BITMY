# include<stdio.h>
# include<stdlib.h>
struct mission
{
    long int start;
    long int end;
};

struct mission all[300100];

int compare(const void *a, const void *b)
{
    return (*(struct mission*)a).end - (*(struct mission*)b).end;//终止时间从小到大
}

int main()
{
    long int n;
    scanf("%ld",&n);
    for(long int i=0;i<n;i++)  
    {  
        scanf("%ld  %ld",&all[i].start,&all[i].end);  
    }
    qsort(all,n,sizeof(all[0]),compare);
    long int sum=1;
    long int lastend=all[0].end;
    for(long int i=0;i<n-1;i++)
    {
        if(lastend<=all[i+1].start)
        {
            sum++;
            lastend=all[i+1].end;
        }
    }
    if(n==0)
    {
        sum=0;
    }
    printf("%ld\n",sum);
    return 0;
}