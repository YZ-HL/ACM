#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 500005
#define int long long
using namespace std;
struct Edge{
    int u;
    int v;
    int w;
} E[maxn];
int n, m, uset[maxn];
int find(int x){
    return uset[x] == x ? uset[x] : uset[x] = find(uset[x]);
}
inline void Build(int u, int v, int w, int i){
    E[i].u = u;
    E[i].v = v;
    E[i].w = w;
}
inline bool cmp(const Edge &A, const Edge &B){
    return A.w > B.w;
}
inline int Kruskal(){
    int sum = 0, cnt = 0;
    for (register int i = 1; i <= m; i++)
    {
        int fu = find(E[i].u);
        int fv = find(E[i].v);
        if(fu == fv)
            continue;
        uset[fu] = fv;
        cnt++;
        sum += E[i].w;
        if(cnt == n-1)
            break;
    }
    return sum;
}
signed main(void)
{
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++)    uset[i] = i;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        Build(u, v, w, i);
    }
    sort(E + 1, E + m + 1, cmp);
    printf("%lld\n", Kruskal());
    return 0;
}
