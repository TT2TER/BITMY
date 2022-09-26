#include <stdio.h>
#include <cstring>
#include <stack>
#include <iostream>
using namespace std;

struct Build
{
    int c;
    int h;
};
int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        int m;
        scanf("%d", &m);
        int color[1000100];           //每栋楼颜色编号
        int has_color[1000100] = {0}; //还剩下几个该颜色的
        int cnt = 0;                 //有几种颜色
        stack<Build> build;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &color[i]);
        }
        for (int i = 0; i < m; i++)
        {
            Build cur;
            cur.c = color[i];
            scanf("%d", &cur.h);
            if (build.empty() || cur.h < build.top().h) //空或者现在的更矮，压入
            {
                if (has_color[cur.c] == 0)
                {
                    cnt++;
                }
                has_color[cur.c]++;
                build.push(cur);
            }
            else //和前一个楼等高或者更高
            {
                while (cur.h >= build.top().h) //比较和之前的楼的高低，从最近的开始比，如果这个更高
                {
                    has_color[build.top().c]--;
                    if (has_color[build.top().c] == 0) //如果删了这栋楼该颜色减到0，颜色减1
                        cnt--;
                    build.pop(); //这栋楼再也看不到了

                    if (build.empty() || cur.h < build.top().h) //等到了空或者能看到高楼，入
                    {
                        if (has_color[cur.c] == 0)
                        {
                            cnt++;
                        }
                        has_color[cur.c]++;
                        build.push(cur);
                        break;
                    }
                }
            }
            if (i != m - 1)
                printf("%d ", cnt);
            else
                printf("%d\n", cnt);
        }
    }
    return 0;
}