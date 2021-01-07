#include <bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;
int t, n, x, a[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &x);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        int minn = 0, maxx = 0;
        for(int i = 1; i <= n; i++)
            maxx += (int)ceil(1.0 * a[i] / x);
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            sum += a[i];
            if(sum % x == 0)
            {
                minn += sum / x;
                sum = 0;
            }
        }
        if(sum)
            minn += (int)ceil(1.0 * sum / x);
        printf("%lld %lld\n", minn, maxx);
    }
    return 0;
}
