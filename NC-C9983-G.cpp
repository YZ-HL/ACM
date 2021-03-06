#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n, m, a[maxn];
int uset[maxn], maxx[maxn];
int find(int x){
    return x == uset[x] ? x : uset[x] = find(uset[x]);
}
void unioon(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy)    return;
    uset[fx] = fy;
}
int main(void)
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        uset[i] = i;
        maxx[i] = a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        int nowmaxx = max(maxx[find(u)], maxx[find(v)]);
        unioon(u, v);
        maxx[find(u)] = nowmaxx;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++)
        ans = ans + maxx[find(i)];
    printf("%lld\n", ans);
    return 0;
}