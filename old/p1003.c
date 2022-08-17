# include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    const int N=n+1;
    int map[N][5];
    int i,j;
    for(i=1;i<N;i++)
    {
        for(j=1;j<5;j++)
        scanf("%d",&map[i][j]);
    }
    int x,y;
    scanf("%d %d",&x,&y);
    for(i=N-1;i>=1;i--)
    {
        if(map[i][1]<=x&&map[i][2]<=y&&map[i][1]+map[i][3]>=x&&map[i][2]+map[i][4]>=y)
        {
            printf("%d",i);
            return 0;
        }
    }
    printf("%d",-1);
    return 0;
}