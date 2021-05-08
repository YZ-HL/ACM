#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int t, n, ans;
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        ans = 0;
        unordered_map<int, int> mp;
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%lld", &tmp);
            ans += mp[tmp - i];
            mp[tmp - i]++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
