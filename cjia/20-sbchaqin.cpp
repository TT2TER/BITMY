#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Box
{
    int top = 0;
    int bot = 0;
    int left = 0;
};

Box box[100200];
int lr[100200][2]; // left and right

bool outputed[100200] = {0};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    memset(lr, 0, sizeof(lr));
    for (int i = 1; i <= n; i++)
    {
        box[i].top = i;
        box[i].bot = i;
        box[i].left = 1;
    }

    int from, to;

    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &from, &to);
        if (box[from].left == 0)
            continue;
        else if (box[to].left == 0)
        {
            box[to].top = box[from].bot;
            box[to].bot = box[from].top;
            box[to].left = box[from].left;

            box[from].left = 0;
            box[from].top = 0;
            box[from].bot = 0;
        }
        else
        {
            //在两头的元素一定有一边没数字，so解决掉这一边
            //要连接的正是两个的TOP
            for (int j = 0; j < 2; j++)
            {
                if (lr[box[from].top][j] == 0)
                {
                    lr[box[from].top][j] = box[to].top;
                    break;
                }
            }
            for (int j = 0; j < 2; j++)
            {
                if (lr[box[to].top][j] == 0)
                {
                    lr[box[to].top][j] = box[from].top;
                    break;
                }
            }
            box[to].top = box[from].bot;
            box[to].left += box[from].left;

            box[from].left = 0;
            box[from].top = 0;
            box[from].bot = 0;
        }
    }

    int direct1, direct2;
    bool isEnd1, isEnd2;

    for (int i = 1; i <= n; i++)
    {
        if (box[i].left == 0)
        {
            printf("0\n");
        }
        else
        {
            printf("%d", box[i].left);
            int cur = box[i].top;
            while (true)
            {
                if (!outputed[cur])
                {
                    printf(" %d", cur);
                    outputed[cur] = true;
                }

                direct1 = lr[cur][0];
                direct2 = lr[cur][1];
                isEnd1 = false;
                isEnd2 = false;
                if (direct1 == 0 || outputed[direct1])//顶头或者已经输出过
                    isEnd1 = true;
                if (direct2 == 0 || outputed[direct2])
                    isEnd2 = true;
                if (isEnd1 && isEnd2)
                    break;
                else
                {
                    if (isEnd1)
                        cur = direct2;
                    else
                        cur = direct1;
                }
            }
            printf("\n");
        }
    }

    return 0;
}
