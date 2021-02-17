#include <bits/stdc++.h>
#define lson(x) (x << 1)
#define rson(x) (x << 1) + 1
#define int long long
#define maxn 1000005
using namespace std;
int n, maxx = -(1 << 30), pos, a[maxn], dep[maxn], vis[maxn];
void dfs(int x, int d){
    if(x > n)   return;
    dep[d] += a[x];
    dfs(lson(x), d + 1);
    dfs(rson(x), d + 1);
}
signed main(void)
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    dfs(1, 1);
    for(int i = 1; i <= log2(n) + 1; i++)
        if(maxx < dep[i])
        {
            maxx = dep[i];
            pos = i;
        }
    printf("%lld\n", pos);
    return 0;
}
