#include <bits/stdc++.h>
#define maxn 200005
#define int long long
const int mod = 1e9 + 7;
using namespace std;
int t, n, m;
int dp[15][maxn];
int dfs(int num, int m){
    if(m == 0)
        return 1;
    if(~dp[num][m])
        return dp[num][m];
    int val = 0;
    if(10 - num <= m)
        val = (val + (dfs(1, m - (10 - num)) + dfs(0, m - (10 - num))) % mod) % mod;
    else
        return 1;
    return dp[num][m] = val;
}
signed main(void)
{
    memset(dp, -1, sizeof(dp));
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &m);
        int ans = 0;
        while(n)
        {
            ans = (ans + dfs(n % 10, m)) % mod;
            n /= 10;
        }
        printf("%lld\n", ans);
    }    
    return 0;
}
