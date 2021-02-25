#include <bits/stdc++.h>
#define maxn 4000005
#define int long long
using namespace std;
int n, bl[maxn], bit[maxn];
int cnt, pri[maxn]; bool isp[maxn];
const int mod = 1e9 + 7;
int quickpow(int a, int b, int p){
    if(b == 0)    return 1;
    int tmp = quickpow(a, b / 2, p);
    tmp = (tmp * tmp) % p;
    if(b & 1)    tmp = (tmp * a) % p;
    return tmp;
}
int bitc(int x){
    int cnt = 0;
    while(x)    x /= 10, cnt++;
    return cnt;
}
int calc(int nw, int r, int i){
    int cnt = bitc(r);
    return ((nw * quickpow(10, bit[i], mod)) % mod + r) % mod; 
}
void euler(int lim){
    memset(isp, true, sizeof(isp));
    isp[1] = false;
    for(int i = 2; i <= lim; i++)
    {
        if(isp[i])    pri[++cnt] = i, bl[i] = i, bit[i] = bitc(i);
        for(int j = 1; j <= cnt && i * pri[j] <= lim; j++)
        {
            isp[i * pri[j]] = false;
            bl[i * pri[j]] = calc(pri[j], bl[i], i);
            bit[i * pri[j]] = bit[i] + bit[pri[j]];
            if(i % pri[j] == 0)
            {
                break;
            }
        }
    }
}
signed main(void)
{
    scanf("%lld", &n);
    euler(n);   
    int ans = 0;
    for(int i = 2; i <= n; i++)    
    {
        ans = (ans + bl[i]) % mod;
        //printf("%lld %lld\n", i, bit[i]);
    }
    printf("%lld\n", ans);
    return 0;
}