#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int t, n, a[maxn], sum, mx;
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        sum = mx = 0;
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]), sum += a[i], mx = max(mx, a[i]);
        int add = mx * (n - 1) - sum;
        printf("%lld\n", add < 0 ? ((add % (n - 1)) + (n - 1)) % (n - 1) : add);
    }
    return 0;
}
