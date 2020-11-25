#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1000005
using namespace std;
int n;
int k, head[maxn];
double z, r, sum, val[maxn], getf[maxn];
struct Edge{
    int to;
    int nxt;
} E[maxn];
void Build(int u, int v){
    E[k].to = v;
    E[k].nxt = head[u];
    head[u] = k++;
}
void dfs(int x, double nowz, int fa){
    //printf("%d %lf %d\n", x, nowz, fa);
    val[x] = nowz;
    if(getf[x])
    {
        //printf("%d %lf\n", x, getf[x]);
        sum += nowz * getf[x];
        return;
    }
    for(int i = head[x]; ~i; i = E[i].nxt)
    {
        if(E[i].to == fa)   continue;
        dfs(E[i].to, nowz * (100.0 - r) / 100, x);
    }
}
int main(void)
{
    memset(head, -1, sizeof(head));
    scanf("%d %lf %lf", &n, &z, &r);
    for(int i = 0; i <= n - 1; i++)
    {
        int ki;
        scanf("%d", &ki);
        if(!ki)
        {
            scanf("%d", &ki);
            getf[i] = ki;
            continue;
        }
        for(int j = 1; j <= ki; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            Build(i, tmp);    Build(tmp, i);
        }
    }
    dfs(0, z, 0);
    printf("%.0lf\n", floor(sum));
    return 0;
}
