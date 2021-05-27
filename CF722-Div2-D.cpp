#include <bits/stdc++.h>
#define maxn 4000005
#define mod 998244353
#define int long long
using namespace std;
int n, sum, dp[maxn];
int cnt, d[maxn], num[maxn], pri[maxn];
bool isp[maxn];
void euler(int lim){
    d[1] = 1;
    memset(isp, true, sizeof(isp));
    for(int i = 2; i <= lim; i++)
    {
        if(isp[i])
        {
            pri[++cnt] = i;
            num[i] = 1; d[i] = 2;
        }
        for(int j = 1; j <= cnt && i * pri[j] <= lim; j++)
        {
            isp[i * pri[j]] = false;
            if(i % pri[j] == 0)
            {
                num[i * pri[j]] = num[i] + 1;
                d[i * pri[j]] = d[i] / (num[i] + 1) * (num[i] + 2);
                break;
            }
            d[i * pri[j]] = d[i] * 2;
            num[i * pri[j]] = 1;
        }
    }
}
signed main(void)
{
    //memset(dp, 0, sizeof(dp));
    euler(1000000);
    scanf("%lld", &n);
    dp[1] = 1; sum = 1;
    for(int i = 2; i <= n; i++)
    {
        //printf("debug: %d, %d\n", 2 * i, d[2 * i]);
        dp[i] = (sum + d[i]) % mod;
        sum = (sum + dp[i]) % mod;
    }
    printf("%lld\n", dp[n]);
    return 0;
}
