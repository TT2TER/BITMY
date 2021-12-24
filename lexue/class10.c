#include <stdio.h>
#include <stdlib.h>
int map[100][100];
void print(int start,int end,int all,char c)
{
    if(start>end)return ;
    else
    {
        for(int i=start;i<=all;i++)
        {
            for(int j=start;j<=end;j++)
            {
                map[i][j]=c;
            }
        }
        if('a'<=c&&c<='z')
        {
            c=c+1>'z'?'a':c+1;
        }
        if('A'<=c&&c<='Z')
        {
            c=c+1>'Z'?'A':c+1;
        }
        print(start+1,end-1,all,c);
    }
    return ;
}
int main()
{
    int n;
    char c;
    scanf("%d %c",&n,&c);
    print(1,n,n,c);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}