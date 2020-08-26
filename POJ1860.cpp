#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 100005
using namespace std;
int n, m, s, flag;
int k, head[maxn];
int inq[maxn], cnt[maxn];
double dis[maxn];
double v;
struct Edge
{
    int to;
    int nxt;
    double r;
    double c;
} E[maxn];
void Build(int u, int v, double r, double c)
{
    E[k].to = v;
    E[k].r = r;
    E[k].c = c;
    E[k].nxt = head[u];
    head[u] = k++;
}
void spfa(int x)
{
    queue<int> q1;
    q1.push(x);
    inq[x] = 1;
    dis[x] = v;
    while (!q1.empty() && !flag)
    {
        int tmp = q1.front();
        q1.pop();
        inq[tmp] = 0;
        for (int i = head[tmp]; ~i; i = E[i].nxt)
        {
            if(cnt[E[i].to] >= n)
            {
                flag = 1;
                break;
            }
            if (dis[E[i].to] < (dis[tmp] - E[i].c) * E[i].r)
            {
                dis[E[i].to] = (dis[tmp] - E[i].c) * E[i].r;
                if (!inq[E[i].to])
                {
                    q1.push(E[i].to);
                    inq[E[i].to] = 1;
                    cnt[E[i].to]++;
                }
            }
        }
    }
}
int main(void)
{
    memset(head, -1, sizeof(head));
    scanf("%d %d %d %lf", &n, &m, &s, &v);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        double r1, c1, r2, c2;
        scanf("%d %d %lf %lf %lf %lf", &u, &v, &r1, &c1, &r2, &c2);
        Build(u, v, r1, c1);
        Build(v, u, r2, c2);
    }
    spfa(s);
    printf(flag ? "YES\n" : "NO\n");
    system("pause");
    return 0;
}