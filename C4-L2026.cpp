#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n, k, rt, cnt, head[maxn], fa[maxn];
struct Edge{
    int to;
    int nxt;
} E[maxn];
struct Level{
    int num;
    int dep;
} L[maxn];
bool cmp(const Level &A, const Level &B){
    if(A.dep == B.dep)
        return A.num < B.num;
    return A.dep > B.dep;
}
void Build(int u, int v){
    E[k].to = v;
    E[k].nxt = head[u];
    head[u] = k++;
}
void dfs(int x, int fr, int dep){
    cnt++;
    L[cnt].num = x;
    L[cnt].dep = dep;
    for(int i = head[x]; ~i; i = E[i].nxt)
    {
        if(E[i].to == fr)    continue;
        dfs(E[i].to, x, dep + 1);
    }
}
int main(void)
{
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &fa[i]);
        if(fa[i] == -1)    rt = i;
        else
        {
            Build(i, fa[i]);
            Build(fa[i], i);
        }
    }
    dfs(rt, 0, 1);
    sort(L+1, L+cnt+1, cmp);
    int minn = L[1].dep, firs = 1;
    printf("%d\n", minn);
    for(int i = 1; i <= n; i++)
    {
        if(L[i].dep != minn)    break;
        printf(firs ? "%d" : " %d", L[i].num);
        firs = 0;
    }
    return 0;
}
