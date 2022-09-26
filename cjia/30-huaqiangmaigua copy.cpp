#include <cstdio>
#include <iostream>
int w[105], v[105], g[105];
int dp[505][505];
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i <= 504; ++i)
    {
        for (int j = 0; j <= 504; ++j)
        {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    for (int k = 1; k <= n; k++)
    {
        scanf("%d %d %d", &w[k], &v[k], &g[k]);
        for (int i = 500; i >= w[k]; i--)
        {
            for (int j = 500; j >= 0; j--)
            {
                if (dp[i - w[k]][j] != -1)
                {
                    if (j + v[k] > 500)
                    {
                        dp[i][501] = max(dp[i][501], dp[i - w[k]][j] + g[k]);
                    }
                    else
                    {

                        dp[i][j + v[k]] = max(dp[i][j + v[k]], dp[i - w[k]][j] + g[k]);
                    }
                }
            }
        }
    }
    for (int k = 1; k <= q; k++)
    {
        int W, V;
        int ans = -1;
        scanf("%d %d", &W, &V);
        for (int i = 1; i <= W; i++)
        {
            for (int j = V; j <= 501; j++)
            {
                ans = max(ans, dp[i][j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}