#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int t, n, m, p[maxn], h[maxn];
int siz[maxn];
int k, head[maxn];
struct Edge{
    int to;
    int nxt;
} Edge[maxn*2];
void Build(int x, int y){
    Edge[k].to = y;
    Edge[k].nxt = head[x];
    head[x] = k++;
}
int dfs(int now, int fa){
    int hps = 0;
    siz[now] = p[now];
    for (int i = head[now]; ~i; i = Edge[i].nxt)
    {
        if(Edge[i].to == fa)    continue;
        int tmp = dfs(Edge[i].to, now);
        if(!~tmp)    return -1;
        hps += tmp;
        siz[now] += siz[Edge[i].to];
    }
    if((h[now]+siz[now]) & 1)   return -1;
    if(abs(h[now]) > siz[now])  return -1;
    int xx = (h[now]+siz[now])>>1;
    int yy = siz[now] - xx;
    //if(xx > siz[now])   return -1;
    if(xx < hps)        return -1;
    return xx;
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        k = 0;
        memset(head, -1, sizeof(head));
        
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &p[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &h[i]);
        for (int i = 1; i <= n-1; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            Build(u, v); Build(v, u);
        }
        //printf("DEBUG: %d\n", dfs(1, 0));
        printf(~dfs(1, 0) ? "YES" : "NO");
        putchar('\n');
    }   
    system("pause");
    return 0;
}