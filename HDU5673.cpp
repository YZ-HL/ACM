#include <bits/stdc++.h>
#define maxn 1000010
#define mod 1000000007
#define int long long
using namespace std;
int h[maxn], sum[maxn], ans[maxn], inv[maxn], cn[maxn], cm[maxn];
int qpow(int a, int b){
    if(b == 1)  return a;
    int tmp = qpow(a, b / 2);
    tmp = (tmp * tmp) % mod;
    if(b & 1)   tmp = (tmp * a) % mod;
    return tmp;
}
int calc(int x){
    if(x < maxn-10)
        return inv[x];
    return (calc(mod % x) * (mod - mod / x)) % mod;
}
int bin(int x, int y){
    return (((cn[y] * cm[x]) % mod) * cm[y-x]) % mod;
}
signed main(void)
{
    ans[1] = 1;
    inv[1] = 1;
    h[0] = h[1] = 1;
    sum[0] = 1; sum[1] = 2;
    for(int i = 2; i <= 1000001; i++)
        inv[i] = ((mod - mod / i) * inv[mod % i]) % mod;
    cn[0] = cm[0] = 1;
    for(int i = 1; i <= 1000000; i++)
    {
        h[i] = ((((4 * i - 2) * inv[i + 1]) % mod) * h[i - 1]) % mod;
        cn[i] = (cn[i-1] * i) % mod;
        cm[i] = calc(cn[i]);
    }
    /*
    cm[1000000] = qpow(cn[1000000], mod-2);
    for(int i = 1000000-1; i >= 0; i--)
        cm[i] = (cm[i + 1] * (i + 1)) % mod;
    */
    int t, n;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        if(ans[n])
        {
            printf("%lld\n", ans[n]);
            continue;
        }
        for(int j = 0; j <= n / 2; j++)
            ans[n] = (ans[n] + bin(2*j, n) * h[j]) % mod;
        printf("%lld\n", ans[n]);
    }
    return 0;
}