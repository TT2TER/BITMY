#include<stdio.h>
typedef struct Time
{
    int s;
    int w;
    int sum;
}time;
int main()
{
    time arr[8];
    int day=0;
    int max=-1;
    for(int i=1;i<=7;i++)
    {
        scanf("%d %d",&arr[i].s,&arr[i].w);
        arr[i].sum=arr[i].s+arr[i].w>=10?arr[i].s+arr[i].w-10:-1;
        if(arr[i].sum>max)
        {
            max=arr[i].sum;
            day=i;
        }
    }
    printf("%d\n",day);
    return 0;
}
