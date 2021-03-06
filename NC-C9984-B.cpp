#include <bits/stdc++.h>
#define int long long
const int maxn = 1e5 + 5;
using namespace std;
const int p1 = 233, mod1 = 998244353;
const int p2 = 131, mod2 = 1e9 + 7;
struct strhash{
    int hash1;
    int hash2;
}h1[maxn], h2[maxn];
int len1, len2, pow1[maxn], pow2[maxn];
char s[maxn], t[maxn];
inline int qpow(int a, int b, int p){
    if(b == 0)    return 1;
    int tmp = qpow(a, b / 2, p);
    tmp = (tmp * tmp) % p;
    if(b & 1)    tmp = (tmp * a) % p;
    return tmp;
}
inline bool check(int lf, int rt){
    int len = rt - lf + 1;
    if(len > len1)    return false;
    int sh1 = h1[len - 1].hash1, sh2 = h1[len - 1].hash2;
    int th1 = (((h2[rt].hash1 - (h2[lf - 1].hash1 * pow1[rt - lf + 1])) % mod1) + mod1) % mod1;
    int th2 = (((h2[rt].hash2 - (h2[lf - 1].hash2 * pow2[rt - lf + 1])) % mod2) + mod2) % mod2;
    return sh1 == th1 && sh2 == th2;
}
signed main(void)
{
    scanf("%s", s);
    scanf("%s", t);
    
    len1 = strlen(s), len2 = strlen(t);
    
    h1[0].hash1 = h1[0].hash2 = s[0];
    h2[0].hash1 = h2[0].hash2 = t[0];
    
    for(int i = 1; i <= len1 - 1; i++)
        h1[i].hash1 = (h1[i - 1].hash1 * p1 + s[i]) % mod1,
        h1[i].hash2 = (h1[i - 1].hash2 * p2 + s[i]) % mod2;
    
    for(int i = 1; i <= len2 - 1; i++)
        h2[i].hash1 = (h2[i - 1].hash1 * p1 + t[i]) % mod1,
        h2[i].hash2 = (h2[i - 1].hash2 * p2 + t[i]) % mod2;
    
    pow1[0] = pow2[0] = 1;
    for(int i = 1; i <= maxn - 5; i++)
        pow1[i] = (pow1[i - 1] * p1) % mod1,
        pow2[i] = (pow2[i - 1] * p2) % mod2;
    
    int ans = 0;
    for(int i = 1; i <= len1; i++)
    {
        if(h1[i - 1].hash1 == h2[i - 1].hash1 && h1[i - 1].hash2 == h2[i - 1].hash2)
        {
            int lf = i, rt = len2 - 1, nans = -1;
            while(lf <= rt)
            {
                int mid = (lf + rt) / 2;
                check(i, mid) ? nans = mid, lf = mid + 1 : rt = mid - 1;
            }
            if(nans != -1)
                ans += nans - i + 1;
        }
    }
    
    printf("%lld\n", ans);
    return 0;
}