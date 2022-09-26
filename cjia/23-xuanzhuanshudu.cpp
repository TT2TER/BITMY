#include <cstdio>
#include <iostream>
#include <queue>
char mazec[18][18];
int maze[18][18];
int backup[18][18];
int s[18]; //记录dep操作
int block[4][4];
bool solved = false;
int a[18][18] = {0}; //第i行数字j出现的次数
int b[18][18] = {0}; //第i列数字j出现的次数
bool bad = false;
int c(char a)
{
    switch (a)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
    default:
        break;
    }
    return 0;
}
void spin(int x, int y)
{ //转，同时维护a,b
    int x0 = (x - 1) * 4, y0 = (y - 1) * 4;
    for (int j = 3; j >= 0; j--)
        for (int k = 0; k < 4; k++)
        {
            block[3 - j][k] = maze[k + x0][j + y0];
            a[k + x0][maze[k + x0][j + y0]]--;
            b[j + y0][maze[k + x0][j + y0]]--;
        }
    for (int l = 0; l < 4; l++)
        for (int m = 0; m < 4; m++)
        {
            maze[l + x0][m + y0] = block[l][m];
            ++a[l + x0][maze[l + x0][m + y0]];
            ++b[m + y0][maze[l + x0][m + y0]];
        }
}
void check(int x, int y)
{
    int x0 = (x - 1) * 4, y0 = (y - 1) * 4;
    for (int l = 0; l < 4; l++)
        for (int m = 0; m < 4; m++)
        {
            if (a[l + x0][maze[l + x0][m + y0]] > 1)
            {
                bad = true;
                return;
            }
            if (b[m + y0][maze[l + x0][m + y0]] > 1)
            {
                bad = true;
                return;
            };
        }
}
void back(int x, int y)
{
    int x0 = (x - 1) * 4, y0 = (y - 1) * 4;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            maze[x0 + i][y0 + j] = backup[x0 + i][y0 + j];
            a[i + x0][maze[i + x0][j + y0]]--;
            b[j + y0][maze[i + x0][j + y0]]--;
        }
    }
}
void dfs(int dep)
{
    if (solved)
        return;
    if (dep == 17)
    {
        solved = true;
        return;
    }
    int x = (dep - 1) / 4 + 1, y = dep - 4 * (x - 1);
    int x0 = (x - 1) * 4, y0 = (y - 1) * 4;

    for (int i = 0; i <= 3; i++)
    {
        if (i)
        {
            spin(x, y);
            check(x, y);
        }

        else
        {
            //把这个dep加入到a,b中；
            for (int l = 0; l < 4; l++)
                for (int m = 0; m < 4; m++)
                {
                    a[l + x0][maze[l + x0][m + y0]]++;
                    ++b[m + y0][maze[l + x0][m + y0]];
                }
            check(x, y);
        }
        s[dep] = i;
        if (bad)
        {
            bad = false;
            continue;
            ;
        }
        dfs(dep + 1);
        if (solved)
            return;
    }
    back(x, y);
    s[dep] = 0;
    return;
}
int main()
{
    int T;
    scanf("%d\n", &T);
    while (T--)
    {
        for (int i = 0; i < 16; i++)
        {
            scanf("%s", &mazec[i]);
            for (int j = 0; j < 16; j++)
            {
                maze[i][j] = c(mazec[i][j]);
                backup[i][j] = maze[i][j];
            }
        }
        solved = false;
        dfs(1);
        int cnt = 0;
        for (int dep = 1; dep <= 16; dep++)
        {
            cnt += s[dep];
        }
        printf("%d\n", cnt);
        for (int dep = 1; dep <= 16; dep++)
        {
            int x = (dep - 1) / 4 + 1, y = dep - 4 * (x - 1);
            while (s[dep]--)
            {
                printf("%d %d\n", x, y);
            }
        }
    }
    return 0;
}