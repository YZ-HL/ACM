#include <bits/stdc++.h>
#define maxn 100005
#define maxm 10000005
#define mod 1000000007
#define int long long
using namespace std;
int n, cnt, ans = 1, pri[maxn];
bool isp[maxn];
int qpow(int a, int b){
    if(b == 0)  return 1;
    int tmp = qpow(a, b / 2);
    tmp = (tmp * tmp) % mod;
    if(b & 1)   tmp = (tmp * a) % mod;
    return tmp;
}
int calc(int p, int now){
    if(p == 2)    return qpow(p, (int)log2(1.0 * now / 3));
    return qpow(p, (int)(log2(1.0 * now / 2) / log2(p)));
}
void euler(int lim){
    memset(isp, true, sizeof(isp));
    isp[1] = false;
    for(int i = 2; i <= lim; i++)
    {
        if(isp[i])    
        {
            pri[++cnt] = i;
            ans = (ans * calc(i, n)) % mod;
        }
        for(int j = 1; j <= cnt && i * pri[j] <= lim; j++)
        {
            isp[i * pri[j]] = false;
            if(i % pri[j] == 0)    break;
        }
    }
}
signed main(void)
{
    scanf("%lld", &n);
    euler(n);
    printf("%lld\n", ans);
    return 0;
}
