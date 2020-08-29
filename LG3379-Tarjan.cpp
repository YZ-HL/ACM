#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define maxn 100005
using namespace std;
int n, m, s;
int k, head[maxn];
int ans[maxn], vis[maxn], uset[maxn];
struct Edge{
    int to;
    int nxt;
} E[maxn];
struct Point{
    int to;
    int num;
};
vector<Point> v1[maxn];
void Build(int u, int v){
    E[k].to = v;
    E[k].nxt = head[u];
    head[u] = k++;
}
int find(int x){
    return x == uset[x] ? x : uset[x] = find(uset[x]);
}
void unionn(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy)
        return;
    uset[fx] = fy;
}
void Tarjan(int now){
    vis[now] = 1;
    for (int i = head[now]; ~i; i = E[i].nxt)
    {
        if(vis[E[i].to])
            continue;
        //printf("debug: %d %d\n", now, E[i].to);
        Tarjan(E[i].to);
        //uset[E[i].to] = now;
        unionn(E[i].to, now);
    }
    for (vector<Point>::iterator i = v1[now].begin(); i != v1[now].end(); i++)
        if(vis[(*i).to] && !ans[(*i).num])
            ans[(*i).num] = find((*i).to);
}
int main(void)
{
    k = 0;
    memset(head, -1, sizeof(head));

    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= n; i++)
        uset[i] = i;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        Build(x, y);
        Build(y, x);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        v1[u].push_back((Point){v, i});
        v1[v].push_back((Point){u, i});
    }
    Tarjan(s);
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    system("pause");
    return 0;
}
