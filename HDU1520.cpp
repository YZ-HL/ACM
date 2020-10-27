#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int dp[maxn][2];
int n, rt, fa[maxn], val[maxn];
int k, head[maxn];
struct Edge{
    int to;
    int nxt;
} E[maxn];
void Build(int u, int v){
    E[k].to = v;
    E[k].nxt = head[u];
    head[u] = k++;
};
void dfs(int x, int fa){
    dp[x][1] = val[x];
    for(int i = head[x]; ~i; i = E[i].nxt)
    {
        if(E[i].to == fa)    continue;
        dfs(E[i].to, x);
        dp[x][1] += dp[E[i].to][0];
        dp[x][0] += max(dp[E[i].to][0], dp[E[i].to][1]);
    }
}
int main(void)
{
    while(~scanf("%d", &n))
    {
        k = 0;
        memset(dp, 0, sizeof(dp));
        memset(head, -1, sizeof(head));

        for(int i = 1; i <= n; i++)
            scanf("%d", &val[i]);
        while(1)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            if(!u)    break;
            Build(u, v); Build(v, u);
            fa[u] = v;
        }    
        rt = 1;
        while(fa[rt])    rt = fa[rt];
        dfs(rt, 0);
        printf("%d\n", max(dp[rt][1], dp[rt][0]));
    }
    system("pause");
    return 0;
}
