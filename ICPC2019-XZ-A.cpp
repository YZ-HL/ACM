#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1000005
#define int long long
using namespace std;
int t, l, r, s, cnt, ans, dp[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        cnt = 0; dp[0] = 0;
        scanf("%lld %lld %lld", &l, &r, &s);
        /*
        if(l % 2)  
        {
            ++cnt;
            dp[cnt] = dp[cnt - 1] ^ l, l++;
        }
        */
        if((r - l + 1) % 4)
            for(int i = l + (r - l + 1) / 4 * 4; i <= r; i++)
            {
                ++cnt;
                dp[cnt] = dp[cnt - 1] ^ i;
            }
        ans = (r - l + 1) / 4 * 4;
        int tmp = ans;
        for(int i = 0; i <= cnt; i++)
            for(int j = i + 1; j <= cnt; j++)
                if((dp[i] ^ dp[j]) <= s)
                    ans = max(ans, tmp + (j - i));
        printf("%lld\n", ans ? ans : -1);
    }
    return 0;
}
