#include <bits/stdc++.h>
#define int long long
const int maxn = 2e5 + 5;
const int mop = 1e16;
using namespace std;
int n, p[maxn];
int k, head[maxn * 2];
int siz[maxn], dp[maxn], res[maxn];
bool isl[maxn];
struct Edge{
    int to;
    int nxt;
}E[maxn * 2];
void Build(int u, int v){
    E[k].to = v;
    E[k].nxt = head[u];
    head[u] = k++;
}
void dfs1(int x, int fa){
    int mx1 = mop * -1, mx2 = mop * -1;
    siz[x] = p[x];
    for(int i = head[x]; ~i; i = E[i].nxt)
    {
        if(E[i].to == fa)    continue;
        dfs1(E[i].to, x);
        siz[x] += siz[E[i].to];
        /*
        if(siz[E[i].to] > mx1)
            mx2 = mx1, mx1 = siz[E[i].to];
        else if(siz[E[i].to] > mx2)
            mx2 = siz[E[i].to];
        */
    }
    //mxp[x] = mx1 + mx2;
}
void dfs2(int x, int fa){
    int flag = 0;
    int mx1 = mop * -1, mx2 = mop * -1;
    //res[x] = mxp[x];
    for(int i = head[x]; ~i; i = E[i].nxt)
    {
        if(E[i].to == fa)    continue;
        flag = 1;
        dfs2(E[i].to, x);
        res[x] = max(res[x], max(res[E[i].to], siz[E[i].to]));
        if(max(res[E[i].to], siz[E[i].to]) > mx1)
            mx2 = mx1, mx1 = max(res[E[i].to], siz[E[i].to]);
        else if(max(res[E[i].to], siz[E[i].to]) > mx2)
            mx2 = max(res[E[i].to], siz[E[i].to]);
    }
    if(!flag)
        res[x] = p[x], isl[x] = 1;
    dp[x] = mx1 + mx2;
}
bool checkChain(int x, int fa){
    int cnt = 0, flag = 0;
    for(int i = head[x]; ~i; i = E[i].nxt)
    {
        if(E[i].to == fa)    continue;
        cnt++;
        flag = checkChain(E[i].to, x);
    }
    return (cnt == 1 && flag == 1) || (cnt == 0);
}
signed main(void)
{
    memset(head, -1, sizeof(head));
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &p[i]), dp[i] = mop * -1, res[i] = mop * -1;
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%lld %lld", &u, &v);
        Build(u, v); Build(v, u);
    }
    if(checkChain(1, 0))
    {
        printf("Error\n");
        return 0;
    }
    dfs1(1, 0);
    dfs2(1, 0);
    int ans = mop * -1;
    for(int i = 1; i <= n; i++)
        //if(!isl[i])
        ans = max(ans, dp[i]);
    printf("%lld\n", ans);
    return 0;
}