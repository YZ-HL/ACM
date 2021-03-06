#include <bits/stdc++.h>
#define int long long
const int maxn = 1e4 + 5;
const int mod = 1e9 + 7;
using namespace std;
int n, xi[maxn], pi[maxn], bl[maxn], isc[maxn];
int qpow(int a, int b){
    if(b == 0)
        return 1;
    int tmp = qpow(a, b / 2);
    tmp = (tmp * tmp) % mod;
    if(b & 1)    tmp = (tmp * a) % mod;
    return tmp;
}
signed main(void)
{
    memset(bl, 0x3f, sizeof(bl));
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &xi[i]);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &pi[i]);
    if(n == 1)
    {
        printf("%lld\n", qpow(xi[1], pi[1]));
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        int r = xi[i];
        for(int j = 2; j * j <= xi[i]; j++)
        {
            int cnt = 0;
            while(xi[i] % j == 0)
            {
                xi[i] /= j;
                cnt++;
            }
            if(cnt)
                bl[j] = min(bl[j], cnt * pi[i]), isc[j]++;
        }
        if(xi[i] == r)
            bl[r] = min(bl[r], pi[i]), isc[r]++;
        else if(xi[i] != 1)
            bl[xi[i]] = min(bl[xi[i]], pi[i]), isc[xi[i]]++;
    }
    int ans = 1;
    for(int i = 1; i <= maxn - 5; i++)
        if(isc[i] == n)
            ans = (ans * qpow(i, bl[i])) % mod;
    printf("%lld\n", ans);
    return 0;
}