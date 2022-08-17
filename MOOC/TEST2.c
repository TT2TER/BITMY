#include<stdio.h>
void sort(float arr[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            float temp;
            if(arr[j]>arr[j+1])
            {temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;}
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    const int N=n;
    float a[N+2];
    for(int i=0;i<N;i++)
    {
        scanf("%f",&a[i]);
    }
    sort(a,N);
    a[N]=-1;
    // for(int i=0;i<N;i++)
    // {
    //     if(a[i]==a[i+1]||a[i]<0)a[i]=-1;
    // }
    int i,j,k;
    int flag=0;
    for(i=0;i<N-2;i++)
    {
        if(a[i]==-1)continue;
        for(j=i+1;j<N-1;j++)
        {
            if(a[i]==-1)continue;
            if(a[j]==-1)continue;
            for(k=j+1;k<N;k++)
            {
                if(a[i]==-1)continue;
                if(a[j]==-1)continue;
                if(a[k]==-1)continue;
                else
                {
                    if(a[i]+a[j]>a[k])
                    {flag++;
                        a[i]=-1;
                        a[j]=-1;
                        a[k]=-1;
                    }
                    
                }
            }
        }
    }
    printf("%d",flag);
    return 0;
}