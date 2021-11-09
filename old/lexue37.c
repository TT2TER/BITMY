#include<stdio.h>
int map[100][100];
int main()
{
    int n;
    scanf("%d",&n);
    //
    int i,j;
    for (i=0;i<=n+1;i++)
    {
        for (j=0;j<=n+1;j++)
        {
            if(j==0||j==n+1||i==0||i==n+1)
            map[i][j]=2;
        }
        
    }
    int dire=1;//1向右2向下3向左4向上
    int block=0;//四个方向有几个不能走，只有0可以走
    i=1;j=1;
    int num=1;
    while(n)
    {
        if(block==4)break;
        if(map[i][j]!=0)
        {
            switch (dire)
            {
                case 1:
                    j--;
                    break;
                case 2:
                    i--;
                    break;
                case 3:
                    j++;
                    break;
                case 4:
                    i++;
                    break;
            }
            dire=(dire==4?1:dire+1);
            block++;
        }
        else//如果没有四面楚歌而且没撞墙，打印这个点
        {
            map[i][j]=num;
            num++;
            block=0;
        }
        //移动
        switch (dire)
            {
                case 1:
                    j++;
                    break;
                case 2:
                    i++;
                    break;
                case 3:
                    j--;
                    break;
                case 4:
                    i--;
                    break;
            }
    }
    for (i=1;i<n+1;i++)
    {
        for (j=1;j<n+1;j++)
        {
            printf("%3d",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}