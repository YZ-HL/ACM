#include <bits/stdc++.h>
#define maxn 1005
#define int long long
using namespace std;
int dp[maxn][maxn];
const int mod = 1e9 + 7;
int t, ans[maxn], id[maxn];
struct query{
    int n;
    int k;
    int id;
}Q[maxn];
bool operator < (const query &A, const query &B){
    return A.n == B.n ? A.k > B.k : A.n > B.n;
}
int dfs(int n, int now, int can){
    if(~dp[now][can])    
    {
        //printf("debug: %d %d %d\n", now, can, dp[now][can]);
        return dp[now][can];
    }
    if(now == 0)
        return dp[now][can] = 1;
    int val = 0;
    if(can > 1)
        val = (val + dfs(n, n - now, can - 1)) % mod;
    val = (val + dfs(n, now - 1, can)) % mod;
    return dp[now][can] = val;
}
signed main(void)
{
    memset(dp, -1, sizeof(dp));
    scanf("%lld", &t);
    for(int i = 1; i <= t; i++)
    {
        scanf("%lld %lld", &Q[i].n, &Q[i].k);
        Q[i].id = i;
    }
    sort(Q + 1, Q + t + 1);
    printf("%d %d %d %d\n", Q[1].id, Q[2].id, Q[3].id, Q[4].id);
    for(int i = 1; i <= t; i++)
        ans[Q[i].id] = dfs(Q[i].n, Q[i].n, Q[i].k);
    for(int i = 1; i <= t; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
