#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
int maze[18][18];
int backup[18][18];
int s[18]; //记录dep操作
int block[4][4];
bool solved = false;
bool bad = false;
int c[18];
int z[18];
void check_line(int x)
{
    memset(c, 0, sizeof(c));
    for (int l = 0; l < 16; l++)
    {
        if (++c[maze[x][l]] > 1)
        {
            solved = false;
            return;
        }
    }
    solved = true;
    return;
}
void check_col(void)
{
    memset(c, 0, sizeof(c));
    for (int l = 0; l < 16; l++)
    {
        if (++c[z[l]] > 1)
        {
            solved = false;
            return;
        }
    }
    solved = true;
    return;
}
void spin(int x, int y)
{ //转
    int x0 = (x - 1) * 4, y0 = (y - 1) * 4;
    for (int j = 3; j >= 0; j--)
        for (int k = 0; k < 4; k++)
        {
            block[3 - j][k] = maze[k + x0][j + y0];
        }
    for (int l = 0; l < 4; l++)
        for (int m = 0; m < 4; m++)
        {
            maze[l + x0][m + y0] = block[l][m];
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
        }
    }
}
void dfs(int dep, int deep)
{
    if (solved)
        return;
    int x = (dep - 1) / 4 + 1, y = dep - 4 * (x - 1);
    int x0 = (x - 1) * 4, y0 = (y - 1) * 4;
    if (deep == 4)
    {
        for (int i = 0; i <= 3; i++)
        {
            if (i)
            {
                spin(x, y);
            }
            s[dep] = i;
            check_line(x0);
            if (solved)
                return;
        }
        back(x, y);
        s[dep] = 0;
        return;
    }

    for (int i = 0; i <= 3; i++)
    {
        if (i)
        {
            spin(x, y);
        }
        s[dep] = i;
        dfs(dep + 1, deep + 1);
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

            for (int j = 0; j < 16; j++)
            {
                scanf("%1x", &maze[i][j]);
                backup[i][j] = maze[i][j];
            }
        }

        int dep;
        for (dep = 1; dep < 16; dep += 4)
        {
            solved = false;
            dfs(dep, 1);
        }

        solved = false;
        //判断转or不转
        for (int i1 = 0; i1 < 2; i1++)
        {
            for (int i2 = 0; i2 < 2; i2++)
            {
                for (int i3 = 0; i3 < 2; i3++)
                {
                    for (int i4 = 0; i4 < 2; i4++)
                    {
                        z[0] = maze[0][i1 * 3];
                        z[1] = maze[1][i1 * 3];
                        z[2] = maze[2][i1 * 3];
                        z[3] = maze[3][i1 * 3];
                        z[4] = maze[4][i2 * 3];
                        z[5] = maze[5][i2 * 3];
                        z[6] = maze[6][i2 * 3];
                        z[7] = maze[7][i2 * 3];
                        z[8] = maze[8][i3 * 3];
                        z[9] = maze[9][i3 * 3];
                        z[10] = maze[10][i3 * 3];
                        z[11] = maze[11][i3 * 3];
                        z[12] = maze[12][i4 * 3];
                        z[13] = maze[13][i4 * 3];
                        z[14] = maze[14][i4 * 3];
                        z[15] = maze[15][i4 * 3];
                        check_col();
                        if (solved)
                        {
                            if (i4)
                            {
                                for (int t = 13; t <= 16; t++)
                                {
                                    s[t] = (s[t] + 2) % 4;
                                }
                            }
                            break;
                        }
                    }
                    if (solved)
                    {
                        if (i3)
                        {
                            for (int t = 9; t <= 12; t++)
                            {
                                s[t] = (s[t] + 2) % 4;
                            }
                        }

                        break;
                    }
                }
                if (solved)
                {
                    if (i2)
                    {
                        for (int t = 5; t <= 8; t++)
                        {
                            s[t] = (s[t] + 2) % 4;
                        }
                    }

                    break;
                }
            }
            if (solved)
            {
                if (i1)
                {
                    for (int t = 1; t <= 4; t++)
                    {
                        s[t] = (s[t] + 2) % 4;
                    }
                }

                break;
            }
        }

        int cnt = 0;
        int cur = 0, ver = 0;
        for (dep = 1; dep <= 16; dep++)
        {
            cur += s[dep];
            ver += (s[dep] + 2) % 4;
        }
        if (ver < cur)
        {
            for (dep = 1; dep <= 16; dep++)
            {
                s[dep] = (s[dep] + 2) % 4;
            }
        }
        for (dep = 1; dep <= 16; dep++)
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