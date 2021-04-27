#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int t, n;
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        if(n % 2050 != 0)
        {
            printf("-1\n");
            continue;
        }
        int cnt = 0, k = n / 2050;
        while(k)
        {
            cnt += k % 10;
            k /= 10;
        }
        printf("%lld\n", cnt);
    }
    return 0;
}
