#include <bits/stdc++.h>
#define maxn 1005
#define mod 100000007
using namespace std;
long long t, n, a[maxn], num[maxn], g[maxn];
long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}
long long qpow(int a, int b, int p){
    if(b == 0)    return 1;
    if(b == 1)    return a;
    long long tmp = qpow(a, b / 2, p);
    tmp = (tmp * tmp) % p;
    if(b & 1)   tmp = (tmp * a) % p;
    return tmp;
}
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        memset(num, 0, sizeof(num));
        memset(g, 0, sizeof(g));

        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)    scanf("%lld", &a[i]);
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= 1000; j++)
                if(a[i] % j == 0)   num[j]++;
        
        for(int i = 1; i <= 1000; i++)
            g[i] = qpow(2, num[i], mod) - 1;
        
        for(int i = 1000; i >= 1; i--)
            for(int j = 2; j * i <= 1000; j++)
                g[i] = (((g[i] - g[i * j]) % mod) + mod) % mod;
        
        long long ans = 0;

        for(int i = 1; i <= 1000; i++)
            ans = (ans + i * g[i]) % mod;
        
        printf("%lld\n", ans);
    }
    return 0;
}