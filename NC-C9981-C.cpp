#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int n, k, cnt, flag = 1, rel[maxn], col[maxn], head[maxn];
struct Edge{
    int to;
    int nxt;
} E[maxn];
void Build(int u, int v){
    E[k].to = v;
    E[k].nxt = head[u];
    head[u] = k++; 
}
void dfs1(int now, int f){
    int siz = 0;
    for(int i = head[now]; ~i; i = E[i].nxt)
    {
        if(E[i].to == f)    continue;
        siz++;
        dfs1(E[i].to, now);
    }
    if(siz == 0 || rel[now] == 0)
    {
        if(rel[f] != 0)
        {
            flag = 0;
            return;
        }
        rel[f] = rel[now] = ++cnt; 
    }
}
void dfs2(int now, int f){
    for(int i = head[now]; ~i; i = E[i].nxt)
    {
        if(E[i].to == f)        continue;
        if(rel[E[i].to] == rel[now])  col[E[i].to] = col[now];
        else                          col[E[i].to] = col[now] ^ 1;
        dfs2(E[i].to, now);
    }
}
int main(void)
{
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        Build(u, v); Build(v, u);
    }
    dfs1(1, 0); dfs2(1, 0);
    if(!flag || rel[0])
    {
        printf("-1");
        return 0;
    }
    for(int i = 1; i <= n; i++)
        printf("%c", col[i] ? 'R' : 'B');
    putchar('\n');
    return 0;
}
