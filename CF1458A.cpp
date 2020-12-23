#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
long long gcd(long long a, long long b){
    return b == 0 ? a : gcd(b, a % b);
}
long long n, m;
long long a[maxn], b[maxn];
signed main(void)
{
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(int i = 1; i <= m; i++)
        scanf("%lld", &b[i]);
    if(n == 1)
    {
        for(int i = 1; i <= m; i++)
        {
            long long ans = a[1] + b[i];
            printf(i == m ? "%lld" : "%lld ", ans);
        }
        return 0;
    }
    sort(a + 1, a + n + 1);
    long long res = a[2] - a[1];
    for(int i = 3; i <= n; i++)
        res = gcd(res, a[i] - a[i - 1]);
    for(int i = 1; i <= m; i++)
    {
        long long ans = a[1] + b[i];
        printf(i == m ? "%lld" : "%lld ", gcd(ans, res));
    }
    return 0;
}
