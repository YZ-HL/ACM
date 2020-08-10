#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int t, n, a[maxn], b[maxn], m1, m2, div1[maxn], div2[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while (t--)
    {
        m1 = 1LL*1000000000+5;
        m2 = 1LL*1000000000+5;
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]), m1 = min(a[i], m1);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &b[i]), m2 = min(b[i], m2);
        for (int i = 1; i <= n; i++)
            div1[i] = a[i] - m1, div2[i] = b[i] - m2;
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += max(div1[i], div2[i]);
        printf("%lld\n", ans);
    }
    system("pause");
    return 0;
}