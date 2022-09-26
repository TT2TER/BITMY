#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

struct place
{
    int x;
    int y;
    int s;
    place(int x0 = 0, int y0 = 0, int s0 = 0)
    {
        x = x0;
        y = y0;
        s = s0;
    }
};

bool map[105][105][52];
char space[105][105];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, k;
        scanf("%d %d %d\n", &n, &m, &k);
        int sx, sy;

        // read map
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                space[i][j]=getchar();
                if (space[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
            }
            getchar();
        }

        queue<place> q;
        int flag = 0;
        memset(map, 0, sizeof(map));
        q.push(place(sx, sy, 0));
        map[sx][sy][0] = true;
        while (!q.empty())
        {
            place t = q.front();
            q.pop();

            if (space[t.x][t.y] == 'E')
            {
                printf("%d\n", t.s);
                flag = 1;
                break;
            }
            else
            {
                for (int i = 0; i < 4; i++)
                {
                    int x = t.x + dx[i], y = t.y + dy[i], stp = t.s + 1;
                    if (x < 1 || x > n || y < 1 || y > m || space[x][y] == '#' || map[x][y][stp % k] == true)
                    {
                        continue;
                    }
                    if (space[x][y] == '*' && (stp % k))
                    {
                        continue;
                    }
                    q.push(place(x, y, stp));
                    map[x][y][stp % k] = true;
                }
            }
        }
        if (!flag)
        {
            printf("-1\n");
        }
    }

    return 0;
}