/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 500005
using namespace std;

int n, m, q, w[maxn], p[maxn], a[maxn];
int ans[maxn], dis[maxn][105];
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
int vis[maxn];
struct Node{
    int pos;
    int dis;
};
void bfs(int spicy){
    memset(vis, 0, sizeof(vis));
    queue<Node> q1;
    for(int i = 1; i <= n; i++)
        if(w[i] == spicy)
            q1.push((Node){i, 0}), vis[i] = 1;
    while(!q1.empty())
    {
        Node tmp = q1.front(); q1.pop();
        dis[tmp.pos][spicy] = tmp.dis;
        for(int i = head[tmp.pos]; ~i; i = E[i].nxt)
        {
            if(vis[E[i].to] == 0)
            {
                q1.push((Node){E[i].to, tmp.dis + 1});
                vis[E[i].to] = 1;
            }
        }
    }
}
int main(void)
{
    //freopen("out.txt", "w", stdout);
    memset(head, -1, sizeof(head));
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        Build(u, v); Build(v, u);
    }    
    for(int i = 1; i <= q; i++)
        scanf("%d %d", &p[i], &a[i]);
    memset(ans, 0x3f, sizeof(ans));
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= 100; i++)    bfs(i);
    for(int i = 1; i <= q; i++)
        for(int j = 1; j <= a[i]; j++)
        {
            ans[i] = min(ans[i], dis[p[i]][j]);
            //printf("debug: %d %d %d\n", p[i], j, dis[p[i]][j]);
        }
    for(int i = 1; i <= q; i++)
        printf("%d\n", ans[i] > 1e9 ? -1 : ans[i]);
    return 0;
}
