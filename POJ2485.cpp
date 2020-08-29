#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 505
using namespace std;
int vis[maxn], dis[maxn];
int k, head[maxn*maxn];
struct Edge{
    int to;
    int nxt;
    int weight;
} E[maxn*maxn];
struct Node{
    int now;
    int dis;
};
bool operator < (const Node &A, const Node &B){
    return A.dis > B.dis;
}
void Build(int u, int v, int w){
    E[k].to = v;
    E[k].nxt = head[u];
    E[k].weight = w;
    head[u] = k++;
}
int Prim(int s){
    int cnt = 0, maxx = -1;

    priority_queue<Node> q1;
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));

    q1.push((Node){s, 0});

    while(!q1.empty())
    {
        Node tmp = q1.top();
        q1.pop();
        int now = tmp.now, dist = tmp.dis;
        if(vis[now])
            continue;
        vis[now] = 1;
        cnt++;
        maxx = max(maxx, dist);
        for (int i = head[now]; ~i; i = E[i].nxt)
        {
            if(!vis[E[i].to] && dis[E[i].to] > E[i].weight)
            {
                dis[E[i].to] = E[i].weight;
                q1.push((Node){E[i].to, dis[E[i].to]});
            }
        }
    }
    return maxx;
}
int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        k = 0;
        memset(head, -1, sizeof(head));

        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                if(i == j)
                    continue;
                Build(i, j, tmp);
            }
        printf("%d\n", Prim(1));
    }
    system("pause");
    return 0;
}
