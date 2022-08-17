#include <stdio.h>
#define max 16
int ans = 17 * 17;
int map[max + 2][max + 2];
int curent[max + 2][max + 2];
int l = 0, w = 0;

int if_line_all_zero(int a[])
{
    int answ = 1;
    for (int i = 0; i < w; i++)
    {
        if (a[i] != 0)
        {
            answ = 0;
            break;
        }
    }
    return answ;
}

void change(int *a)
{
    if (*a == 1)
    {
        *a = 0;
    }
    else
    {
        *a = 1;
    }
    return;
}

void one_step(int a[max + 2][max + 2], int a0, int b0)
{
    change(&a[a0][b0]);
    if (a0 - 1 >= 0)
        change(&a[a0 - 1][b0]);
    if (b0 - 1 >= 0)
        change(&a[a0][b0 - 1]);
    if (a0 + 1 < l)
        change(&a[a0 + 1][b0]);
    if (b0 + 1 < w)
        change(&a[a0][b0 + 1]);
    return;
}
int is_yes()
{
    int count = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < w; j++)
        {
            curent[i][j] = map[i][j];
        }
    }
    for (int i = 0; i < l - 1; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (curent[i][j] == 1)
            {
                one_step(curent, i + 1, j);
                count++;
            }
        }
    }
    if (if_line_all_zero(curent[l-1]))
    {
        return count;
    }
    else
        return -1;
}

void dfs(int position, int count)
{
    if (position == w)
    {
        int answer = is_yes();
        if (answer == -1)
        {
            return;
        }
        else if (answer + count < ans)
        {
            ans = answer + count;
            return;
        }
        else
            return;
    }

    one_step(map, 0, position);
    dfs(position + 1, count + 1);

    one_step(map, 0, position);
    dfs(position + 1, count);
}

int main()
{
    scanf("%d %d\n", &l, &w);
    
    for (int i = 0; i < l; i++)
    {
        char c;
        for (int j = 0; j < w; j++)
        {

            c = getchar();
            map[i][j] = c - '0';
        }
        c = getchar();
    }
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}