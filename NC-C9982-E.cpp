#include <bits/stdc++.h>
#define maxn 2000005
#define int long long
using namespace std;
int n, k, maxx, dis[maxn], head[maxn];
vector<int> v1[maxn];
struct pos{
    int num;
    int y, l, r;
}p[maxn];
struct Edge{
    int to;
    int nxt;
    int weight;
}E[maxn];
void Build(int u, int v, int w){
    E[k].to = v;
    E[k].nxt = head[u];
    E[k].weight = w;
    head[u] = k++;
}
bool cmp(const pos &A, const pos &B){
    if(A.y != B.y)
        return A.y < B.y;
    return A.l < B.l;
}
queue<int> q1; bool vis[maxn];
void SPFA(int num){
    memset(dis, 0x3f, sizeof(dis));
    q1.push(num);
    vis[num] = true;
    dis[num] = 0;
    while(!q1.empty())
    {
        int now = q1.front(); q1.pop();
        vis[now] = false;
        for(int i = head[now]; ~i; i = E[i].nxt)
        {
            int v = E[i].to;
            if(dis[v] > dis[now] + E[i].weight)
            {
                dis[v] = dis[now] + E[i].weight;
                if(!vis[v])
                {
                    vis[v] = true;
                    q1.push(v);
                }
            }
        }
    }
}
signed main(void)
{
    memset(head, -1, sizeof(head));
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
    {
        int ty, tl, tr;
        scanf("%lld %lld %lld", &ty, &tl, &tr);
        p[i].num = i;
        p[i].y = ty; p[i].l = tl; p[i].r = tr;
        maxx = max(maxx, ty);
    }
    sort(p + 1, p + n + 1, cmp);
    for(int i = 1; i <= n; i++)    v1[p[i].y].push_back(i);
    for(int i = 0; i <= maxn - 5; i++)
    {
        for(int j = 0; j < v1[i].size(); j++)
        {
            if(j && p[v1[i][j]].l == p[v1[i][j - 1]].r)
            {
                Build(v1[i][j], v1[i][j - 1], 1);
                Build(v1[i][j - 1], v1[i][j], 1);
            }
        }
        if(!v1[i + 1].size() || !v1[i].size())    continue;
        int pos = 0;
        for(int j = 0; j < v1[i].size(); j++)
        {
            while(pos < v1[i + 1].size() && p[v1[i + 1][pos]].r <= p[v1[i][j]].l)    pos++;
            while(pos < v1[i + 1].size() && max(p[v1[i + 1][pos]].l, p[v1[i][j]].l) < min(p[v1[i + 1][pos]].r, p[v1[i][j]].r))
            {
                Build(v1[i + 1][pos], v1[i][j], 1);
                Build(v1[i][j], v1[i + 1][pos], 1);
                pos++;
            }
            pos--;
        }
    }
    int s = -1, t = -1;
    for(int i = 1; i <= n; i++)    
    {
        if(p[i].num == 1)    s = i;
        if(p[i].num == n)    t = i;
        if(s != -1 && t != -1)    break;
    }
    SPFA(s);
    printf("%lld\n", dis[t]);
    return 0;
}