#include <bits/stdc++.h>
#define maxn 2005
#define int long long
using namespace std;
int n, a[maxn];
int dp[maxn][maxn];
signed main(void)
{
    memset(dp, 0xce, sizeof(dp));
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);   
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= i; j++)
        {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if(j && dp[i - 1][j - 1] + a[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i]);
        }
    int maxx = 0;
    for(int i = 0; i <= n; i++)
        if(dp[n][i] >= 0)
            maxx = max(maxx, i);
    printf("%lld\n", maxx);
    return 0;
}