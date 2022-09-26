#include <iostream>
#include <cstdio>
const long long t = 2147483647;
const int maxN = 2000;
#define ll long long
using namespace std;
ll b[maxN + 50];
ll dp[maxN][maxN] = {0};
ll max(ll a, ll b)
{
    if (a > b)
        return a;
    else
        return b;
}
ll min(ll a, ll b)
{
    if (a > b)
        return b;
    else
        return a;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i <= T; i++)
    {
        scanf("%lld", &b[i]);
    }
    dp[1][b[0]]=1;
    for (int i = 1; i <= T; i++)
    {
        for (int j = 0; j <= T + 1; j++)
        {
            ll left = min(b[i - 1], j);
            ll right = max(b[i - 1], j);
            if (b[i] <= left)
            {
                dp[i][right] = (dp[i - 1][j] + dp[i][right]) % t;
            }
            if (b[i] >= right)
            {
                dp[i][left] = (dp[i - 1][j] + dp[i][left]) % t;
            }
            if (b[i] < right && b[i] > left)
            {
                dp[i][left] = (dp[i - 1][j] + dp[i][left]) % t;
                dp[i][right] = (dp[i - 1][j] + dp[i][right]) % t;
            }
        }
    }
    ll ans = 0;
    for (int j = 0; j <= T +1; j++)
    {
        ans = (ans + dp[T][j]) % t;
    }
    printf("%lld\n",ans);
}
