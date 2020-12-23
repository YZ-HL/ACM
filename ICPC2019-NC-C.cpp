#include <bits/stdc++.h>
#define maxn 1000005
#define int long long
#define mod 1000000007
using namespace std;
int t, cnt, s[maxn], ne[maxn], dp[maxn];
string str;
int quickpow(int a, int b, int p){
    if (b == 0)
        return 1;
    int tmp = quickpow(a, b / 2, p);
    tmp = ((tmp % mod) * (tmp % mod)) % p;
    if (b & 1)
        tmp = ((tmp % mod) * (a % mod)) % p;
    return tmp % mod;
}
signed main(void)
{
    scanf("%lld", &t);
    while (t--)
    {
        cnt = 0;
        memset(s, 0, sizeof(s));
        memset(ne, 0, sizeof(ne));
        memset(dp, 0, sizeof(dp));

        cin >> str;
        int len = str.size(), las = -1;
        for (int i = len - 1; i >= 0; i--)
        {
            if (str[i] == '1')
            {
                if (las == -1)
                    ne[i] = len, las = i;
                else
                    ne[i] = las, las = i;
            }
        }
        //s用于统计两个1，或者1和边界之间之间夹了多少个0
        for (int i = len - 1; i >= 0; i--)
        {
            if (str[i] == '1')
                s[++cnt] = ne[i] - i - 1;
        }
        dp[1] = quickpow(2, s[1], mod);
        for (int i = 2; i <= cnt; i++)
            dp[i] = ((dp[i - 1] % mod) * ((quickpow(2, s[i], mod) + quickpow(2, s[i] + 1, mod))) % mod) % mod;
        int ans = 1;
        for (int i = 1; i <= cnt; i++)
            ans = (ans + dp[i]) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}