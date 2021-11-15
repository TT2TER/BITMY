#include<stdio.h>
int d[110];
int h[110];
void sort(int arr[],int N)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N-1-i;j++)
        {
            int temp;
            if(arr[j]>arr[j+1])
            {temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;}
        }
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j;
    for(i=1;i<=n;i++)scanf("%d",&d[i]);
    for(i=1;i<=m;i++)scanf("%d",&h[i]);
    sort(&h[1],m);
    sort(&d[1],n);
    int head=n;
    int flag=0;
    int sum=0;
    for(i=1;i<=n;i++)
    {
        for(j=flag+1;j<=m;j++)
        {
            if(d[i]<=h[j]&&head>0)
            {
                --head;
                flag=j;
                sum+=h[j];
                break;
            }
        }
    }
    if(head>0)printf("bit is doomed!\n");
    else printf("%d\n",sum);
    return 0;
}