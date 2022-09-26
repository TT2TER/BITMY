#include <iostream>
#include<cstdio>
const long long t=10000000;
#define ll long long
using namespace std;
ll dp[2005][2005];
ll p[2010];

int main()
{
    ll n, V;
    scanf("%lld %lld", &n, &V);
    dp[0][0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &p[i]);
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < V; j++)
        { 
            dp[i][j] = dp[i - 1][j] % t;
        }

        for (ll v = 0; v < V; v++)
        {
            ll k = (v + p[i]) % V; 
            dp[i][k] = (dp[i - 1][v] + dp[i][k]) % t;
        }
    }

    printf("%lld\n",dp[n][0]-1);
    return 0;
}
