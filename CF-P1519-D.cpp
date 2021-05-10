#include <bits/stdc++.h>
#define maxn 5005
#define int long long
using namespace std;
int n, a[maxn], b[maxn], sum[maxn], dp[maxn][maxn];
int dfs(int lf, int rt){
    if(~dp[lf][rt])
        return dp[lf][rt];
    if(lf == rt)
        return dp[lf][rt] = a[lf] * b[lf];
    if(lf + 1 == rt)
        return dp[lf][rt] = a[lf] * b[rt] + a[rt] * b[lf];
    return dp[lf][rt] = a[rt] * b[lf] + a[lf] * b[rt] + dfs(lf + 1, rt - 1);
}
signed main(void)
{
    memset(dp, -1, sizeof(dp));
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &b[i]);
        sum[i] = sum[i - 1] + a[i] * b[i];
    }
    int ans = sum[n];
    //printf("debug:%lld\n", ans);
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int val = dfs(i, j);
            int newval = sum[i - 1] + (sum[n] - sum[j]) + val;
            //printf("debug: %d %d %d\n", i, j, newval);
            if(ans < newval)
                ans = newval;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
