#include<stdio.h>
#include<string.h>
int sys[100];
char ch[100][11];
int nch[100][11];
int main()
{
    int i,j;
    for(i='a',j=1;i<='z';i++,j++)
    {
        sys[i]=j;
        //printf("%d %c ",sys[i],i);
    }//将每一位（进制）初始化
    int n;
    scanf("%d\n",&n);
    int k;
    for(k=0;k<n;k++)
    {
        gets(ch[k]);
        int ret=1;
        //puts(ch[k]);
        int len=strlen(ch[k]);
        int sum;
        for(i=len-1;i>0;i--)
        {
            if(ch[k][i]<=ch[k][i-1])
            {
                ret=0;
                goto exit;
            }
            else
            {
                int a,b;
                a=ch[k][i];
                b=ch[k][i-1];
                sum+=sys[a]-sys[b];
            }
            
        }
        int a=ch[k][i];
        sum+=sys[a];
        exit:
        if(ret==0)
        {
            printf("0\n");
            ret=1;
        }
        else 
        {
            printf(":%d\n",sum);
        }
    }
    return 0;
}