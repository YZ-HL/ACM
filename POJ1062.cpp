#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 1005
using namespace std;
int m, n, qzl, ans = (1 << 30);
int k, head[maxn * maxn];
int inq[maxn], dis[maxn];
int p[maxn], l[maxn], x[maxn], t[maxn][maxn], v[maxn][maxn];
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
void Build(int u, int v, int w)
{
    E[k].to = v;
    E[k].nxt = head[u];
    E[k].weight = w;
    head[u] = k++;
}
void spfa()
{
    memset(inq, 0, sizeof(inq));
    memset(dis, 0x3f, sizeof(dis));

    queue<int> q1;
    q1.push(n + 1);
    inq[n + 1] = 1;
    dis[n + 1] = 0;

    while (!q1.empty())
    {
        int tmp = q1.front();
        q1.pop();
        inq[tmp] = 0;
        for (int i = head[tmp]; ~i; i = E[i].nxt)
        {
            if (dis[E[i].to] > dis[tmp] + E[i].weight)
            {
                dis[E[i].to] = dis[tmp] + E[i].weight;
                if (!inq[E[i].to])
                {
                    q1.push(E[i].to);
                    inq[E[i].to] = 1;
                }
            }
        }
    }
}
void Dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));

    priority_queue<Node> q1;
    q1.push((Node){n + 1, 0});
    dis[n + 1] = 0;

    while (!q1.empty())
    {
        Node tmp = q1.top();
        q1.pop();
        int now = tmp.now, dist = tmp.dis;
        if (dist != dis[now])
            continue;
        for (int i = head[now]; ~i; i = E[i].nxt)
        {
            if (dis[E[i].to] > dis[now] + E[i].weight)
            {
                dis[E[i].to] = dis[now] + E[i].weight;
                q1.push((Node){E[i].to, dis[E[i].to]});
            }
        }
    }
}
bool check(int x, int vv)
{
    return (x >= qzl - m + vv && x <= qzl + vv);
}
int main(void)
{
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &p[i], &l[i], &x[i]);
        for (int j = 1; j <= x[i]; j++)
            scanf("%d %d", &t[i][j], &v[i][j]);
    }
    for (int vv = 0; vv <= m; vv++)
    {
        k = 0;
        memset(head, -1, sizeof(head));

        Build(n + 1, 1, p[1]);

        qzl = l[1];

        for (int j = 1; j <= x[1]; j++)
            if (check(l[1], vv) && check(l[t[1][j]], vv))
                Build(t[1][j], 1, v[1][j]);

        for (int i = 2; i <= n; i++)
        {
            if (check(l[i], vv))
                Build(n + 1, i, p[i]);

            for (int j = 1; j <= x[i]; j++)
                if (check(l[i], vv) && check(l[t[i][j]], vv))
                    Build(t[i][j], i, v[i][j]);
        }

        //spfa();
        Dijkstra();
        ans = min(ans, dis[1]);
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}
