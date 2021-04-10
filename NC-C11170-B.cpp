#include <bits/stdc++.h>
#define maxn 100005
#define mod 998244353
#define int long long
using namespace std;
int n, a[maxn], b[maxn], c[maxn], suma[maxn], sumb[maxn];
signed main(void)
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &b[i]);
    for(int i = n; i >= 1; i--)
    {
        suma[i] = (suma[i + 1] + a[i]) % mod;
        sumb[i] = (sumb[i + 1] + b[i]) % mod;
    }
    for(int i = 2; i <= n; i++)
        c[0] = (((a[i] * sumb[2]) % mod) + c[0]) % mod;
    c[1] = (c[1] + ((a[1] * sumb[3]) % mod));
    c[1] = (c[1] + ((b[1] * suma[3]) % mod));
    c[1] = (c[1] + (a[1] * b[1]) % mod);
    c[2] = (c[2] + (a[1] * b[2]) % mod) % mod;
    c[2] = (c[2] + (a[2] * b[1]) % mod) % mod;
    for(int i = 0; i <= n - 1; i++)
        printf("%lld ", c[i]);
    return 0;
}
