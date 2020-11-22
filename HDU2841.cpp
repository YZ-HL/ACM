#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int t, n, m;
int cnt, mu[maxn], pri[maxn], sum[maxn];
bool isp[maxn];
void euler(int lim){
    memset(isp, true, sizeof(isp));
    isp[1] = false;
    mu[1] = 1;    sum[1] = 1;
    for (int i = 2; i <= lim; i++)
    {
        if (isp[i])
        {
            pri[++cnt] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= cnt && pri[j] * i <= lim; j++)
        {   
            isp[pri[j] * i] = false;
            if(i % pri[j] == 0)    break;
            mu[pri[j] * i] = -mu[i];
        }
        sum[i] = sum[i-1] + mu[i];
    }
}
signed main(void)
{
    euler(100000);

    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld %lld", &n, &m);
        if (n > m)
            swap(n, m);
        
        int ans = 0, r;
        
        for(int i = 1; i <= n; i = r + 1)
        {
            r = min(n / (n / i), m / (m / i));
            //printf("%lld %lld %lld\n", i, r, sum[r]-sum[i-1]);
            ans += (sum[r]-sum[i-1])*(n/i)*(m/i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}