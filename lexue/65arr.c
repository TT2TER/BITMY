#include <stdio.h>
int main()
{
    int n,num,flag[55]={0};
    scanf("%d %d",&n,&num);
    for(int i=1;i<=n;i++)
    {
        flag[i]=i;
    }
    int left=n;
    while(left!=1)
    {
        for(int k=1,i=1;left>1;i=i+1>n?1:i+1)
        {
            if(flag[i]==0)continue;
            if(k==num)
            {
                flag[i]=0;
                left--;
            }
            k=k+1>num?1:k+1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(flag[i]!=0)printf("The left child is NO %d.\n",flag[i]);
    }
    return 0;
}