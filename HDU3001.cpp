#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
#define int long long
using namespace std;
int n, m;
int dp[15][maxn], bas[maxn];
int k, head[maxn];
struct Edge{
    int to;
    int nxt;
    int weight;
} E[maxn];
void Build(int u, int v, int w){
    E[k].to = v;
    E[k].nxt = head[u];
    E[k].weight = w;
    head[u] = k++;
}
int check(int x){
    int flag = 1;
    for(int i = 1; i <= n; i++)
        if((x / bas[i]) % 3 < 1)    flag = 0;
    return flag;
}
int dfs(int x, int sta){
    //printf("%d %d\n", x, sta);
    if(dp[x][sta] >= 0)
        return dp[x][sta];
    if(check(sta))
        return 0;
    int minn = (1 << 30);
    for(int i = head[x]; ~i; i = E[i].nxt)
    {
        if((sta / bas[E[i].to]) % 3 == 2)    continue;
        minn = min(minn, dfs(E[i].to, sta + bas[E[i].to]) + E[i].weight);
    }
    return dp[x][sta] = minn;
}
signed main(void)
{
    bas[1] = 1;
    for(int i = 2; i <= 11; i++)    bas[i] = 3 * bas[i-1];
    while(~scanf("%lld %lld", &n, &m))
    {
        k = 0;
        memset(dp, -1, sizeof(dp));
        memset(head, -1, sizeof(head));
        for(int i = 1; i <= m; i++)
        {
            int u, v, w;
            scanf("%lld %lld %lld", &u, &v, &w);
            Build(u, v, w);
            Build(v, u, w);
        }
        for(int i = 1; i <= n; i++)    Build(0, i, 0);
        int ans = -1;
        printf("%lld\n", (ans = dfs(0, 0)) > 1e9 ? -1 : ans);
    }
    system("pause");
    return 0;
}
