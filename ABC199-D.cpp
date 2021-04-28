#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int n, m, ans, col[maxn], vis[maxn];
vector<int> G[maxn], N;
void subset(int now){
    vis[now] = 1;
    N.push_back(now);
    for(int i = 0; i < G[now].size(); i++)
        if(!vis[G[now][i]])    subset(G[now][i]);
}
int dfs(int now, int cnt){
    //printf("debug: %lld %lld\n", now, cnt);
    for(int i = 0; i < G[now].size(); i++)
        if(col[now] == col[G[now][i]])    return 0;
    if(cnt == N.size() - 1)    return 1;
    int val = 0;
    col[N[cnt + 1]] = 1; val += dfs(N[cnt + 1], cnt + 1);
    col[N[cnt + 1]] = 2; val += dfs(N[cnt + 1], cnt + 1);
    col[N[cnt + 1]] = 3; val += dfs(N[cnt + 1], cnt + 1);
    col[N[cnt + 1]] = 0;
    return val;
}
signed main(void)
{
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%lld %lld", &u, &v);
        G[u].push_back(v); G[v].push_back(u);
    }
    int ans = 1;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            N.clear();
            subset(i);
            col[N[0]] = 1;
            ans = ans * dfs(N[0], 0) * 3;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
