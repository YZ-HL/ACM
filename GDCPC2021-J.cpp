#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int dp[maxn], bas[maxn], cnt;
void solve2(){
    for(int i = 1; i <= cnt; i++)
        for(int j = 1; j <= cnt; j++)
        {
            int val;
            val = bas[i] + bas[j];
            if(val >= 0 && val <= 100000)
                dp[val] = min(dp[val], 2LL);

            //if(val == 47)    printf("%d %d\n", bas[i], bas[j]);

            val = bas[i] - bas[j];
            if(val >= 0 && val <= 100000)
                dp[val] = min(dp[val], 2LL);

            //if(val == 47)    printf("%d %d\n", bas[i], bas[j]);
        }
}
void solve3(){
    for(int i = 1; i <= cnt; i++)
        for(int j = 1; j <= cnt; j++)
            for(int k = 1; k <= cnt; k++)
            {
                int val;
                val = bas[i] + bas[j] + bas[k];
                if(val >= 0 && val <= 100000)
                    dp[val] = min(dp[val], 3LL);

                val = bas[i] + bas[j] - bas[k];
                if(val >= 0 && val <= 100000)
                    dp[val] = min(dp[val], 3LL);

                val = bas[i] - bas[j] + bas[k];
                if(val >= 0 && val <= 100000)
                    dp[val] = min(dp[val], 3LL);

                val = bas[i] - bas[j] - bas[k];
                if(val >= 0 && val <= 100000)
                    dp[val] = min(dp[val], 3LL);
            }
}
int q, n;
signed main(void)
{
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i * i <= 100000; i++)    
    {
        bas[++cnt] = i * i;
        dp[i * i] = 1;
    }
    solve2(); solve3();

    scanf("%lld", &q);
    while(q--)
    {
        scanf("%lld", &n);
        printf("%lld\n", dp[n]);
    }
    return 0;
}