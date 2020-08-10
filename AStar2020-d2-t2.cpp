#include <bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int t, n, a[maxn], s[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        int ans = 0;
        sort(a + 1, a + n + 1);
        //printf("%lld\n", a[1]);
        for (int i = 1; i <= n; i++)
        {
            s[i] = s[i - 1] + a[i];
            ans += a[i] * (i-1) - s[i - 1];
        }
        printf("%lld\n", ans);
    }
    system("pause");
    return 0;
}