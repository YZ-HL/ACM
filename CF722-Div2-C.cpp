
#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int maxn = 100010;
int n, l[maxn], r[maxn];
ll dp[maxn][2];
vector<int> G[maxn];
 
void dfs(int u, int fa)
{
    dp[u][0] = dp[u][1] = 0;
    for(int v : G[u])
        if(v != fa)
        {
            dfs(v, u);
            dp[u][0] += max(dp[v][0]+abs(l[v]-l[u]), dp[v][1]+abs(r[v]-l[u]));
            dp[u][1] += max(dp[v][0]+abs(l[v]-r[u]), dp[v][1]+abs(r[v]-r[u]));
        }
}
signed main()
{
    int T;
    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld", &n);
        for(int i=1; i<=n; i++)
            G[i].clear();
        for(int i=1; i<=n; i++)
            scanf("%lld%lld", &l[i], &r[i]);
        for(int i = 1; i < n; ++i)
        {
            int u, v;
            scanf("%lld%lld", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, -1);
        printf("%lld\n", max(dp[1][0], dp[1][1]));
 
    }
    return 0;
}