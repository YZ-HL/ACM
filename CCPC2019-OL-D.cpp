#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#define maxn 100005
#define int long long
using namespace std;
int que[maxn], ans[maxn];
struct Edge
{
    int u;
    int v;
    int w;
    int rk;
};
bool operator<(const Edge &A, const Edge &B)
{
    return A.w > B.w;
}
bool cmp(const Edge &A, const Edge &B)
{
    return A.w < B.w;
}
vector<Edge> E[maxn];
priority_queue<Edge> q1;

signed main(void)
{
    int T;
    scanf("%lld", &T);
    while (T--)
    {
        int n, m, q;
        scanf("%lld %lld %lld", &n, &m, &q);
        while (!q1.empty())
            q1.pop();
        for (int i = 1; i <= n; i++)
            E[i].clear();

        memset(que, 0, sizeof(que));

        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            scanf("%lld %lld %lld", &u, &v, &w);
            E[u].push_back((Edge){u, v, w});
        }
        for (int i = 1; i <= q; i++)
            scanf("%lld", &que[i]);

        for (int i = 1; i <= n; i++)
        {
            sort(E[i].begin(), E[i].end(), cmp);
            for (int j = 0; j < E[i].size(); j++)
            {
                E[i][j].rk = j;
                if(!j)
                    q1.push(E[i][j]);
            }
        }
        int nowpos = 0, cnt = 0;
        while (!q1.empty())
        {
            nowpos++;
            Edge tmp = q1.top();
            //printf("%lld %lld %lld %lld\n", tmp.u, tmp.v, tmp.w, tmp.rk);
            q1.pop();

            ans[nowpos] = tmp.w;

            if (nowpos == 50000)
                break;

            if (tmp.rk + 1 < E[tmp.u].size())
                q1.push((Edge){tmp.u, E[tmp.u][tmp.rk + 1].v, tmp.w - E[tmp.u][tmp.rk].w + E[tmp.u][tmp.rk + 1].w, tmp.rk + 1});
            if (!E[tmp.v].empty())
                q1.push((Edge){tmp.v, E[tmp.v][0].v, tmp.w + E[tmp.v][0].w, 0});
        }
        for (int i = 1; i <= q; i++)
            printf("%lld\n", ans[que[i]]);
    }
    system("pause");
    return 0;
}
