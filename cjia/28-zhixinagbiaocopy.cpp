#include <iostream>
#include <cstdio>
const long long t = 2147483647;
const int maxN = 2000;
#define ll long long
using namespace std;
ll b[maxN + 50];
ll dp[maxN+50][maxN+50] = {0};
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
            if(j==b[i-1])
            {
                if(b[i]>j)
                {
                    for(int k=j+1;k<=T+1;k++)
                    {
                        dp[i][j]=(dp[i][j]+dp[i-1][k])%t;
                    }
                }
                if(b[i]<j)
                {
                    for(int k=0;k<=j-1;k++)
                    {
                        dp[i][j]=(dp[i][j]+dp[i-1][k])%t;
                    }
                }
            }
            else if((j<b[i-1]&&j<b[i])||(j>b[i-1]&&j>b[i]))
            {
                dp[i][j]=dp[i-1][j];
            }
            else dp[i][j]=0;
        }
    }
    ll ans = 0;
    for (int j = 0; j <= T +1; j++)
    {
        ans = (ans + dp[T][j]) % t;
    }
    printf("%lld\n",ans);
}
