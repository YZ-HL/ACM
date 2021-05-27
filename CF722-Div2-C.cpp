#include <bits/stdc++.h>
#define maxn 800005
#define int long long
using namespace std;
int t, n;
int k, head[maxn];
int lf[maxn], rt[maxn], dp[maxn][2], leaves[maxn];
struct Edge{
    int to;
    int nxt;
} E[maxn];
void Build(int u, int v){
    E[k].to = v;
    E[k].nxt = head[u];
    head[u] = k++;
}
void inits(){
    k = 0;
    for(int i = 0; i <= 2 * n; i++)
        head[i] = -1;
    for(int i = 1; i <= n; i++)
    {
        dp[i][1] = dp[i][2] = -1;
        leaves[i] = 1;
    }
}
void predfs(int now, int fa){
    int flag = 1;
    for(int i = head[now]; ~i; i = E[i].nxt)
    {
        if(E[i].to == fa)    continue;
        flag = 0;
        predfs(E[i].to, now);
    }
    leaves[now] = flag;
}
int dfs(int now, int fa, int sta){
    if(leaves[now])    return 0;
    if(~dp[now][sta])   
        return dp[now][sta];
    int val = 0;
    for(int i = head[now]; ~i; i = E[i].nxt)
    {
        if(E[i].to == fa)    continue;
        int nowval = (sta == 1 ? lf[now] : rt[now]);
        val += max(dfs(E[i].to, now, 1) + abs(lf[E[i].to] - nowval),
                   dfs(E[i].to, now, 2) + abs(rt[E[i].to] - nowval));
    }
    dp[now][sta] = val;
    return val;
}
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld %lld", &lf[i], &rt[i]);
        inits();
        for(int i = 1; i <= n - 1; i++)
        {
            int u, v;
            scanf("%lld %lld", &u, &v);
            Build(u, v); Build(v, u);
        }
        predfs(1, 0);
        dfs(1, 0, 1); dfs(1, 0, 2);
        printf("%lld\n", max(dp[1][1], dp[1][2]));
    }
    return 0;
}
