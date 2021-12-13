#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
int scoreH[14] = {0, -50, -2, -3, -4, -5, -6, -7, -8, -9, -10, -20, -30, -40};
typedef struct _Poker
{
    char suit;
    int num;
} point;
int flag = 1;
int main()
{
    //freopen("1.out", "w", stdout);
    while (flag)
    {
        flag = 0;
        int player[5]={0};
        int allH = 0;
        for (int i = 0; i < 4; i++)
        {
            int isme = 0;
            int hadnum=0;
            scanf("%d", &hadnum);
            if(flag==16)
            {
                continue;
            }
            flag += hadnum;
            point arr[20] = {{0, 0}};
            int numH = 0;
            int hasC = 0;
            int hasS = 0;
            int hasD = 0;
            int sumH = 0;
            for (int j = 1; j <= hadnum; j++)
            {
                while((arr[j].suit=getchar())==' ')
                {
                    continue;
                }
                scanf("%d",&arr[j].num);
                if (arr[j].suit == 'H')
                {
                    numH++;
                    sumH += scoreH[arr[j].num];
                }
                if (arr[j].suit == 'C')
                {
                    hasC = 1;
                }
                if (arr[j].suit == 'D')
                {
                    hasD = 1;
                }
                if (arr[j].suit == 'S')
                {
                    hasS = 1;
                }
            }
            if (numH == 13)
            {
                allH = 1;
                isme = 1;
            }
            if (allH)
            {
                if (isme)
                {
                    arr[0].num += 200;
                    if (hasS && hasD)
                    {
                        arr[0].num += 300;
                    }
                    else if (hasS)
                    {
                        arr[0].num -= 100;
                    }
                    else if (hasD)
                    {
                        arr[0].num += 100;
                    }
                }
                else
                {
                    if (hasS && hasD)
                    {
                        arr[0].num += 0;
                    }
                    else if (hasS)
                    {
                        arr[0].num -= 100;
                    }
                    else if (hasD)
                    {
                        arr[0].num += 100;
                    }
                }
            }
            else if (!isme)
            {
                arr[0].num += sumH;
                if (hasS && hasD)
                {
                    arr[0].num += 0;
                }
                else if (hasS)
                {
                    arr[0].num -= 100;
                }
                else if (hasD)
                {
                    arr[0].num += 100;
                }
            }
            if (hasC && hadnum == 1)
            {
                arr[0].num += 50;
            }
            else if (hasC)
            {
                arr[0].num *= 2;
            }
            player[i] = arr[0].num;
        }
        if (flag)
        {
            for (int i = 0; i < 4; i++)
            {
                if (player[i])
                    printf("%+d", player[i]);
                else
                    printf("0");
                if (i == 3)
                    printf("\n");
                else
                    printf(" ");
            }
        }
    }
    return 0;
}