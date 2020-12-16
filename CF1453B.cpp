#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int t, n, a[maxn], d[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for(int i = 1; i <= n - 1; i++)
            d[i] = a[i + 1] - a[i];
        int ans = 0, maxx = max(abs(d[1]), abs(d[n - 1]));
        for(int i = 2; i <= n - 1; i++)
            maxx = max(maxx, abs(d[i]) + abs(d[i - 1]) - abs(d[i - 1] + d[i]));
        for(int i = 1; i <= n - 1; i++)
            ans += abs(d[i]);
        printf("%lld\n", ans - maxx);

        /*
        printf("de:\n");
        for(int i = 1; i <= n; i++)
            printf("%lld ", d[i]);
        */
    }   
    return 0;
}
