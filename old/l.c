#include<stdio.h>
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int a,b;
    int i,j;
    scanf("%d %d",&a,&b);
    const int A=a;
    const int B=b;
    char map[A+2][B+2];
    //初始化map,用1围圈圈；
    for(i=0;i<A+2;i++)
    {
        for(j=0;j<B+2;j++)
        {
            if(i==0||j==0||i==A+1||j==B+1)
            map[i][j]='1';
        }
    }

    for(i=1;i<A+1;i++)
    {
        for(j=1;j<B+1;j++)
        {
            scanf("%c",&map[i][j]);
        }
    }

    // for(i=1;i<=A;i++)
    // {
    //     for(j=1;j<=B;j++)
    //     {
    //         if(map[i][j]!='C')
    //         {
    //             continue;
    //         }
    //         else if(map[i][j]=='C')
    //         {
    //             if(map[i-1][j]=='R'||map[i+1][j]=='R'||map[1][j+1]=='R'||map[i][j-1]=='R')
    //             {
    //                 printf("No");
    //                 return 0;
    //             }
    //         }
    //     }
    // }

    // for(i=1;i<A+1;i++)
    // {
    //     for(j=1;j<B+1;j++)
    //     {
    //         if(map[i][j]=='.')
    //         map[i][j]='#';
    //     }
    // }
    for(i=1;i<A+1;i++)
    {
        for(j=1;j<B+1;j++)
        {
            printf("%d %d %c\n",i,j,map[i][j]);
        }
        printf("\n");
    }
    return 0;
}