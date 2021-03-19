#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int n, m, k, vis[maxn], head[maxn];
struct Edge{
    int to;
    int nxt;
} E[maxn];
void Build(int u, int v){
    E[k].to = v;
    E[k].nxt = head[u];
    head[u] = k++;
}
queue<pair<int, int> > q1;
int bfs(int x){
    vis[x] = 1;
    q1.push(make_pair(x, 0));
    while(!q1.empty())
    {
        int npos = q1.front().first;
        int nstp = q1.front().second;
        q1.pop();
        if(npos == n)    return nstp;
        for(int i = head[npos]; ~i; i = E[i].nxt)
        {
            if(!vis[E[i].to])
            {
                vis[E[i].to] = 1;
                q1.push(make_pair(E[i].to, nstp + 1));
            }
        }
    }
    return -1;
}
int main(void)
{
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        Build(u, v); Build(v, u);
    }
    printf("%d\n", bfs(1) - 1);
    return 0;
}
