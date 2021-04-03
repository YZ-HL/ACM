#include <bits/stdc++.h>
#define maxn 200005
#define mod 998244353
#define int long long
using namespace std;
int n, ans, a[maxn];
int qpow(int a, int b, int p){
    if(!b)  return 1;
    int tmp = qpow(a, b / 2, p);
    tmp = (tmp * tmp) % p;
    if(b & 1)   tmp = (tmp * a) % p;
    return tmp;
}
signed main(void)
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)    scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    int t = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = (ans + a[i] * a[i]) % mod;
        ans = (ans + t * a[i]) % mod;
        t = (2 * t + a[i]) % mod;
    }
    printf("%lld\n", ans % mod);
    return 0;
}
