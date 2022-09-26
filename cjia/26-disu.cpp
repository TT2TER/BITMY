#include<cstdio>
#include<iostream>
using namespace std;
#define ll long long int
const int  maxN=500050;
const int INF=0x3f3f3f3f;
ll dp[4][maxN];//表示第到第j个数已经有i队美女，这i队美女颜值总数。
ll beu[maxN];
ll cmp(ll a,ll b)
{
    if(a>b)return a;
    else return b;
}
int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&beu[i]);
    }

    //初始化

    for(ll i=0;i<maxN;i++)
    {
        dp[0][i]=0;
    }

    //开始DP
    for (int i = 1; i < 4; i++)
    {
        ll maxP=-INF;
        for(ll j=i;j<=n;j++)
        {
            if(j==i)//初始化，到第1个有一队就是beu[1],第二个有两队就是beu[2]……
            {
                dp[i][j]=dp[i-1][j-1]+beu[j];
                continue;
            }
            maxP=cmp(maxP,dp[i-1][j]);
            dp[i][j]=cmp(maxP,dp[i][j-1])+beu[j];
        }
    }
    //输出
    ll maxP=-INF;
    for(ll i=3;i<=n;i++)
    {
        maxP=cmp(maxP,dp[3][i]);
    }
    printf("%lld\n",maxP);
}