#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int t, n, a[maxn];
const int INF = 1e14;
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        int minn = INF, cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            if(a[i] > 0)    minn = min(minn, a[i]);
            else            cnt++;
        }
        sort(a + 1, a + n + 1);
        int flag = (minn != INF);
        for(int i = 2; i <= n; i++)
            if(a[i] <= 0)
                flag &= (a[i] - a[i - 1] >= minn);
        printf("%lld\n", flag + cnt);
    }
    return 0;
}
