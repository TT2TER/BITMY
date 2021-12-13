#include <stdio.h>
#include <string.h>
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
        int player[4];
        int allH = 0;
        for (int i = 0; i < 4; i++)
        {
            int isme = 0;
            int hadnum;
            scanf("%d", &hadnum);
            flag += hadnum;
            point arr[18] = {{0, 0}};
            int numH = 0;
            int hasC = 0;
            int hasS = 0;
            int hasD = 0;
            for (int j = 1; j <= hadnum; j++)
            {
                getchar();
                scanf("%c %d", &arr[j].suit, &arr[j].num);
                if (arr[j].suit == 'H')
                {
                    numH++;
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
            if (hasC && hadnum == 1)
            {
                arr[0].num += 50;
                continue;
            }
            if (allH)
            {
                if (isme)
                {
                    arr[0].num += 200;
                    if (hasS && hasD)
                    {
                        arr[0].num += 500;
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
                int sumH = 0;
                for (int k = 1, j = 0; j < numH && k <= hadnum; k++)
                {
                    if (arr[k].suit == 'H')
                    {
                        sumH += scoreH[arr[k].num];
                        j++;
                    }
                }
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
            if (hasC)
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
}