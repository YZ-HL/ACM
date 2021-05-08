#include <bits/stdc++.h>
#define maxn 1005
#define int long long
using namespace std;
int dp[maxn][maxn];
int t, n, k;
const int mod = 1e9 + 7;
int dfs(int now, int can){
    if(~dp[now][can])    
        return dp[now][can];
    if(now == 0)
        return dp[now][can] = 1;
    if(can == 1)
        return dp[now][can] = 1;
    int val = 0;
    val = (val + dfs(n - now, can - 1)) % mod;
    val = (val + dfs(now - 1, can)) % mod;
    return dp[now][can] = val;
}
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%lld %lld", &n, &k);
        printf("%lld\n", dfs(n, k));
    }
    return 0;
}