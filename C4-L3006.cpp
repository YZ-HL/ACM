#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, m;
int k, head[maxn];
struct Edge{
    int to;
    int nxt;
}E[maxn];
void Build(int u, int v){
    E[k].to = v;
    E[k].nxt = head[u];
    head[u] = k++;
}
int dp[maxn], vis[maxn];
int dfs(int now, int t){
    vis[now] = 1;
    if(~dp[now])    return dp[now];
    if(now == t)
        return dp[now] = 1;
    int val = 0;
    for(int i = head[now]; ~i; i = E[i].nxt)
        val += dfs(E[i].to, t);
    return dp[now] = val;
}
int main(void)
{
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        Build(u, v);
    }
    int qs, qt, fail = 0;
    scanf("%d %d", &qs, &qt);
    memset(dp, -1, sizeof(dp));
    int ans = dfs(qs, qt);
    for(int i = 1; i <= n; i++)
        if((dp[i] == -1 || dp[i] == 0) && vis[i])
        {
            fail = 1;
            break;
        }
    printf("%d ", ans);
    printf(fail ? "No" : "Yes");
    return 0;
}
