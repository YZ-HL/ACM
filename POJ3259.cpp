#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 100005
using namespace std;
int n, m, w;
int k, head[maxn];
int flag, cnt[maxn], dis[maxn], inq[maxn];
struct Edge{
    int to;
    int nxt;
    int weight;
} E[maxn];
void Build(int u, int v, int w){
    E[k].to = v;
    E[k].nxt = head[u];
    E[k].weight = w;
    head[u] = k++;
}
void spfa(int x){
    memset(inq, 0, sizeof(inq));
    memset(dis, 0x3f, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));

    queue<int> q1;
    q1.push(x);
    inq[x] = 1;
    dis[x] = 0;
    while(!q1.empty())
    {
        int tmp = q1.front();
        q1.pop();
        inq[tmp] = 0;
        if(cnt[tmp] >= n)
        {
            flag = 1;
            break;
        }
        for (int i = head[tmp]; ~i; i = E[i].nxt)
        {
            if(dis[E[i].to] > dis[tmp]+E[i].weight)
            {
                dis[E[i].to] = dis[tmp] + E[i].weight;
                if(!inq[E[i].to])
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
    int T;
    scanf("%d", &T);
    while(T--)
    {
        k = 0;
        flag = 0;
        memset(head, -1, sizeof(head));

        scanf("%d %d %d", &n, &m, &w);
        
        int u, v, d;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &u, &v, &d);
            Build(u, v, d);
            Build(v, u, d);
        }
        for (int i = 1; i <= w; i++)
        {
            scanf("%d %d %d", &u, &v, &d);
            Build(u, v, (-1) * d);
        }

        spfa(1);
        printf(flag ? "YES\n" : "NO\n");
    }
    system("pause");
    return 0;
}
