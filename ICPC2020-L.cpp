#include <bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int t;
int n, m;
int a[maxn], b[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        a[n + 1] = (1 << 30) + 5;
        b[1] = -1; b[m + 2] = (1 << 30);
        for(int i = 2; i <= m + 1; i++)
            scanf("%lld", &b[i]);
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        int ans = 0;
        for(int i = 1; i <= m + 1; i++)
        {
            if(b[i] == b[i + 1])    continue;
            int pos1 = upper_bound(a + 1, a + n + 1, b[i]) - a;
            int pos2 = lower_bound(a + 1, a + n + 1, b[i + 1]) - a;
            //printf("%lld %lld\n", pos1, pos2);
            if(a[pos1] <= b[i] || a[pos2] < b[i + 1])    continue;
            ans = max(ans, pos2 - pos1);
        }
        if(ans == 0)
            printf("Impossible\n");
        else
            printf("%lld\n", ans);
    }
    return 0;
}