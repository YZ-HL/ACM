#include <bits/stdc++.h>
#define maxn 2000005
#define int long long
using namespace std;
int n, m, ans[maxn], vis[maxn];
int dp[maxn];
struct op{
    int t;
    int val;
    int cnt;
}o[maxn];
int Ceil(int val){
    return ((val + 100000 - 1) / 100000);
}
signed main(void)
{
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%lld %lld %lld", &o[i].t, &o[i].val, &o[i].cnt);
    //memset(dp, 0x3f, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= 0; j--)
        {
            if(!dp[j])    continue;
            int val = j;
            for(int k = 1; k <= o[i].cnt; k++)
            {
                val = (o[i].t == 1 ? val + Ceil(o[i].val) : Ceil(val * o[i].val));
                if(val > m)    break;
                dp[val] |= dp[j];
                //key
                if(!ans[val])               ans[val] = i;
                else                        break;
                //printf("debug: %lld %lld %lld %lld\n", i, j, k, val);
            }
        }
    }
    for(int i = 1; i <= m; i++)
        printf("%lld ", !ans[i] ? -1 : ans[i]);
    return 0;
}
