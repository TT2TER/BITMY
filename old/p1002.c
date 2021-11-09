# include<stdio.h>
long long int map[25][25];

int main ()
{
 //   freopen("i.out","w",stdout);
    int x,y;
    scanf("%d %d",&x,&y);
    int i,j;
    for(i=0;i<=x+2;i++)
    {
        for(j=0;j<=y+2;j++)
        {
            if(j==0||i==0||j==y+2||i==x+2)
            map[i][j]=-1;
        }
    }
    int m,n;
    scanf("%d %d",&m,&n);
    m++;
    n++;
    map[m][n]=-1;
    map[m+2][n+1]=-1;if(n-1>=0)map[m+2][n-1]=-1;
    map[m+1][n+2]=-1;if(n-2>=0)map[m+1][n-2]=-1;
    if(m-1>=0)map[m-1][n+2]=-1;if(m-1>=0&&n-2>=0)map[m-1][n-2]=-1;
    if(m-2>=0)map[m-2][n+1]=-1;if(m-2>=0&&n-1>=0)map[m-2][n-1]=-1;
                        // for(i=0;i<=x+2;i++)
                        // {
                        //     for(j=0;j<=y+2;j++)
                        //     {
                        //     printf("%2d ",map[i][j]);
                        //     }printf("\n");
                        // }
    map[1][1]=1;
    for(i=1;i<=x+1;i++)
    {
        for(j=1;j<=y+1;j++)
        {
            if(map[i][j]!=-1)
            {
            if(map[i-1][j]==-1);
            else map[i][j]+=map[i-1][j];
            if(map[i][j-1]==-1);
            else map[i][j]+=map[i][j-1];
            }
        }
    }
                        // for(i=0;i<=x+2;i++)
                        // {
                        //     for(j=0;j<=y+2;j++)
                        //     {
                        //     printf("%10d ",map[i][j]);
                        //     }printf("\n");
                        // }
    printf("%lld",map[x+1][y+1]);
    return 0;
}