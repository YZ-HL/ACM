#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 2005
using namespace std;
int n;
int k, dis[maxn], vis[maxn], head[maxn * maxn];
char str[maxn][8];
struct Edge
{
    int to;
    int nxt;
    int weight;
} E[maxn * maxn];
struct Node
{
    int now;
    int dis;
};
bool operator<(const Node &A, const Node &B)
{
    return A.dis > B.dis;
}
inline void Build(int u, int v, int w)
{
    E[k].to = v;
    E[k].nxt = head[u];
    E[k].weight = w;
    head[u] = k++;
}
inline int Prim(int s)
{
    int cnt = 0, sum = 0;

    memset(dis, 0x3f, sizeof(dis));
    priority_queue<Node> q1;
    q1.push((Node){s, 0});
    dis[s] = 0;
    while (!q1.empty() && cnt < n)
    {
        Node tmp = q1.top();
        q1.pop();
        int now = tmp.now, dist = tmp.dis;
        if (vis[now])
            continue;
        cnt++;
        sum += dist;
        vis[now] = 1;

        for (register int i = head[now]; ~i; i = E[i].nxt)
        {
            if (dis[E[i].to] > E[i].weight)
            {
                dis[E[i].to] = E[i].weight;
                q1.push((Node){E[i].to, dis[E[i].to]});
            }
        }
    }
    return sum;
}
inline int calc(int pos1, int pos2)
{
    int len = 7;
    int cnt = 0;
    for (register int i = 0; i <= len - 1; i++)
        if (str[pos1][i] != str[pos2][i])
            cnt++;
    return cnt;
}
int main(void)
{
    while (scanf("%d", &n), n)
    {
        k = 0;
        memset(head, -1, sizeof(head));
        memset(vis, 0, sizeof(vis));

        for (register int i = 1; i <= n; i++)
            scanf("%s", str[i]);
        for (register int i = 1; i <= n; i++)
            for (register int j = i + 1; j <= n; j++)
            {
                int val = calc(i, j);
                Build(i, j, val);
                Build(j, i, val);
            }
        printf("The highest possible quality is 1/%d.\n", Prim(1));
    }
    system("pause");
    return 0;
}
