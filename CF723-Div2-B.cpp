#include <bits/stdc++.h>
#define maxn 2005
#define int long long
using namespace std;
int t, n, dp[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        if(n > 11 * 111)
        {
            printf("YES\n");
            continue;
        }
        memset(dp, 0, sizeof(dp));    dp[0] = 1;
        for(int i = 0; i <= 1500; i++)
            if(i - 11 >= 0)    dp[i] |= dp[i - 11];
        for(int i = 0; i <= 1500; i++)
            if(i - 111 >= 0)   dp[i] |= dp[i - 111];
        printf(dp[n] ? "YES\n" : "NO\n");        
    }
    return 0;
}
