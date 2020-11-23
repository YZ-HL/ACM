#include <bits/stdc++.h>
#define maxn 2000005
using namespace std;
int n, k, ans, maxdep = -1, in[maxn], head[maxn];
struct Edge{
    int to;
    int nxt;
} E[maxn];
void Build(int u, int v){
    E[k].to = v;
    E[k].nxt = head[u];
    head[u] = k++;
}
void dfs(int x, int dep){
    //printf("Debug: %d %d\n", x, dep);
    if(dep > maxdep)
    {
        maxdep = dep;
        ans = x;
    }
    for(int i = head[x]; ~i; i = E[i].nxt)  dfs(E[i].to, dep+1);
}
int main(void)
{
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    for(int i = 1; i <= n; i++)
    {
        int kk;
        scanf("%d", &kk);
        for(int j = 1; j <= kk; j++)
        {
            int v;
            scanf("%d", &v);
            Build(i, v);    ++in[v];
        }
    }
    int s = -1;
    for(int i = 1; i <= n; i++)
        if(!in[i]) 
        {
            s = i;
            break;
        }
    dfs(s, 0);  
    printf("%d\n", ans); 
    return 0;
}
