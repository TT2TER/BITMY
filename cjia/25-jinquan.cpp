#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int N = 1050, M = 1050;
struct node
{
    int x;
    int y;
    int time;
};
char space[N][M];
bool did[N][M] = {false};
int main()
{
    int n, m, k;
    scanf("%d %d %d\n", &n, &m, &k);

    int sx, sy, ex, ey;
    bool flag = false;

    // read map
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            space[i][j] = getchar();
        }
        getchar();
    }
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    memset(did, false , sizeof(did));
    queue<node> q;
    while (!q.empty())
        q.pop();
    q.push({sx, sy, 0});
    if (sx == ex && sy == ey)
    {
        printf("0\n");
        flag = true;
    }
    while (!q.empty() && !flag)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                int x = j * dx[i] + q.front().x;
                int y = j * dy[i] + q.front().y;
                int time = q.front().time + 1;
                if (x < 1 || x > n || y < 1 || y > m || space[x][y] == '#')
                {
                    break;
                }
                else if (did[x][y] == true)
                {
                    continue;
                }
                if (x == ex && y == ey)
                {
                    printf("%d\n", time);
                    flag = true;
                    break;
                }
                q.push({x, y, time});
                did[x][y] = true;
            }
            if (flag)
            {
                break;
            }
        }
        q.pop();
    }
    if (!flag)
    {
        printf("-1\n");
    }
    return 0;
}