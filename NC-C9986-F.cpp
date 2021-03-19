#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int qpow(int a, int b, int p){
    if(b == 0)    return 1;
    int tmp = qpow(a, b / 2, p);
    tmp = (tmp * tmp) % p;
    if(b & 1)    tmp = (tmp * a) % p;
    return tmp;
}
signed main(void)
{
    int n;
    scanf("%lld", &n);
    int tmp = qpow(4, n / 4, mod);
    if((n / 4) & 1)    tmp = ((-tmp) % mod + mod) % mod;
    int ans = (((qpow(2, n - 1, mod) + tmp) % mod) * qpow(2, mod - 2, mod)) % mod;
    printf("%lld\n", ans);
    return 0;
}