#include <bits/stdc++.h>
#define maxn 2005
#define int long long
using namespace std;
int n, m, s[maxn], dp[maxn][maxn];
int dfs(int lf, int rt){
    if(lf == rt)     return 0;
    if(~dp[lf][rt])  return dp[lf][rt];
    return dp[lf][rt] = s[rt] - s[lf] + min(dfs(lf + 1, rt), dfs(lf, rt - 1));
}
signed main(void)
{
    memset(dp, -1, sizeof(dp));
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &s[i]);
    sort(s + 1, s + n + 1);
    printf("%lld\n", dfs(1, n));
    return 0;
}
