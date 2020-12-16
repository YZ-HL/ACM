#include <bits/stdc++.h>
#define maxn 200005
#define mod 998244353
#define int long long
using namespace std;
int n, fib[maxn];
int quickpow(int a, int b){
    if(b == 1)
        return a;
    int tmp = quickpow(a, b / 2);
    tmp = (tmp * tmp) % mod;
    if(b & 1)
        tmp = (tmp * a) % mod;
    return tmp;
}   
signed main(void)
{
    scanf("%lld", &n);
    fib[1] = fib[2] = 1;
    for(int i = 3; i <= n; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    if(n == 1)
        printf("%lld", quickpow(2, mod - 2));
    else if(n <= 3)
        printf("%d", 748683265);
    else
        printf("%lld", (fib[n] * quickpow(quickpow(2, n), mod - 2)) % mod);
    return 0;
}
