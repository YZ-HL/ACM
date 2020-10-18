#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 1000005
#define int long long
using namespace std;
int m, n, a[maxn];
int dp[maxn][2];
signed main(void)
{
	while(~scanf("%lld %lld", &m, &n))
	{
		memset(dp, 0xce, sizeof(dp));
		dp[0][0] = dp[0][1] = 0;
		
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		
		int flag = 0;
		for(int i = 1; i <= m; i++)
		{
			int maxx = -(1<<30);
			for(int j = i; j <= n; j++)
			{
				maxx = max(maxx, dp[j-1][flag^1]);
				if(j - 1 < i)
					dp[j][flag] = maxx + a[j];
				else
					dp[j][flag] = max(dp[j-1][flag], maxx) + a[j];
				//printf("%d %d %d\n", j, i, dp[j][flag]);
			}
			flag ^= 1;
		}
		int ans = -(1<<30);
		for(int i = m; i <= n; i++)
		{
			ans = max(ans, dp[i][flag^1]);
			//if(dp[i][flag^1] == 30)
			//	printf("%d %d\n", i, dp[i][flag^1]);
		}
		printf("%lld\n", ans);
	}
    return 0;
}
/*
dp[0][0] = 0;
dp[4][4] = dp[4-1][4-1]+a[4]
dp[4][3] = max(dp[3][3], max(dp[2][2], dp[3][2]))+a[4]
dp[6][3] = max(dp[5][3], max(dp[5][2], dp[4][2], dp[3][2], dp[2][2]));
case 1: dp[i-1][j]
case 2: max(dp[i-1][j-1], dp[i-2][j-1], ..., dp[j-1][j-1])
*/