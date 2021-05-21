#include <bits/stdc++.h>
#define maxn 1000005
#define int long long
using namespace std;
int t, n, a[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        int ans = 0;
        map<int, int> cnt;
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            if(cnt.count(a[i]))    ans += cnt[a[i]] * (n - i + 1);
            cnt[a[i]] += i;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
