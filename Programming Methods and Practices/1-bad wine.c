#include <stdio.h>
#include <math.h>
int main()
{
    int T;
    scanf("%d", &T);
    long long int a[T + 1];
    int ans[T + 1];
    for (int i = 1; i <= T; i++)
    {
        scanf("%lld", &a[i]);
        float log2 = log(a[i]) / log(2);
        if (log2 != (int)log2)
        {
            log2++;
        }
        ans[i] = (int)log2;
    }
    for (int i = 1; i <= T; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}

/*笔记：
int长度32767
思路：不同小鼠尽可能覆盖不同的酒，用类似于二分法的想法，这样每个小鼠覆盖的都会组合出不一样的情况。，根据小鼠死亡可以判断
*/
