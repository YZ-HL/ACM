#include <bits/stdc++.h>
#define maxn 1000005
#define int long long
using namespace std;
int n;
int cnt, pri[maxn];
bool isp[maxn];
int sum[maxn], psum[maxn];
void euler(int lim){
	sum[1] = 1;
	memset(isp, true, sizeof(isp));
	isp[1] = false;
	for(int i = 2; i <= lim; i++)
	{
		if(isp[i])    
		{
			pri[++cnt] = i;
			psum[i] = sum[i] = i + 1;
		}
		for(int j = 1; j <= cnt && i * pri[j] <= lim; j++)
		{
			isp[i * pri[j]] = false;
			if(i % pri[j] == 0)
			{
				psum[i * pri[j]] = psum[i] * pri[j] + 1;
				sum[i * pri[j]] = sum[i] / psum[i] * psum[i * pri[j]];
				break;
			}
			psum[i * pri[j]] = pri[j] + 1;
			sum[i * pri[j]] = sum[i] * (pri[j] + 1);
		}
	}
}
#define LL long long
LL get_sum(LL n){
	LL ans = 0;
	for(LL l = 1, r; l <= n; l = r + 1)
	{
		r = n / (n / l);
		ans += (n / l) * (l + r) * (r - l + 1) / 2;
	}
	return ans;
}
int G[maxn];
signed main(void)
{
	scanf("%lld", &n);
	euler(n);
    for(int i = 1; i <= n; i++)
        G[i] = G[i - 1] + sum[i];
    printf("%lld\n", get_sum(G[n]));
    return 0;
}
//2056198403