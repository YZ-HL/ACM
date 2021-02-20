#include <bits/stdc++.h>
#define maxn 1000005
#define int long long
#define mod 1000000007
using namespace std;
int n, dp[maxn][3];
signed main(void)
{
    scanf("%lld", &n);
    //前i位,有[u][us][*]的情况
    dp[1][0] = 1;  dp[1][1] = 0; dp[1][2] = 25;
    for(int i = 2; i <= n; i++)
    {
        dp[i][0] =  (dp[i - 1][0] * 25 + dp[i - 1][2]) % mod;
        dp[i][1] =  (dp[i - 1][0] + dp[i - 1][1] * 26) % mod;
        dp[i][2] =  (dp[i - 1][2] * 25) % mod;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)    ans = (ans + dp[i][1]) % mod;
    printf("%lld\n", ans);
    return 0;
}
