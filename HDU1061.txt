#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll qpow(ll a, ll b, ll mod){
    if(b == 0)  return 1;
    ll tmp = qpow(a, b / 2, mod);
    tmp = (tmp * tmp) % mod;
    if(b & 1)   tmp = (tmp * (a % mod)) % mod;
    return tmp;
}
int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", qpow(n, n, 10));
    }
    return 0;
}