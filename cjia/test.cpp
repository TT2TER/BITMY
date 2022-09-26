#include <iostream>
#include <cstring>
using namespace std;
const int size = 500 + 5;
int w[size], v[size], g[size]; //权重 成熟度 金粒子
int W[size], V[size];
int dp[size][size];
void Check(int &WW, int &VV)
{
    int ans = -1;
    for (int i = 1; i <= WW; ++i)
    { // w之和
        for (int j = VV; j <= 500; ++j)
        { // v之和
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i] >> v[i] >> g[i];
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> W[i] >> V[i];
    }
    for (int i = 0; i <= 500; ++i)
    { // w之和
        for (int j = 0; j <= 500; ++j)
        { // v之和
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 500 - w[k]; i >= 0; --i)
        { // w之和
            for (int j = 500; j >= 0; --j)
            { // v之和
                if (dp[i][j] != -1)
                    dp[i + w[k]][min(j + v[k], 500)] = max(dp[i + w[k]][min(j + v[k], 500)], dp[i][j] + g[k]);
            }
        }
    }
    // for(int i=0;i<=50;++i){//w之和
    //  for(int j=0;j<=50;++j){//v之和
    //   cout<<dp[i][j]<<" ";
    //  }
    //  cout<<endl;
    // }
    for (int index = 1; index <= q; ++index)
    {
        Check(W[index], V[index]);
    }
    return 0;
}