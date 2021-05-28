#include <bits/stdc++.h>
#define maxn 1000005
#define int long long
using namespace std;
int t, n;
int pre[maxn], suf[maxn], sum[maxn];
string str;
signed main(void)
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> str;
        str = "#" + str;
        pre[0] = 0; suf[n + 1] = 0;
        for(int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + (str[i] == '.' ? 0 : 1);
        for(int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + (str[i] == '.' ? sum[i] : 0);
        for(int i = n; i >= 1; i--)
            suf[i] = suf[i + 1] + (str[i] == '.' ? sum[n] - sum[i - 1] : 0);
        int ans = 1e18;
        for(int i = 0; i <= n; i++)
            ans = min(ans, pre[i] + suf[i + 1]);
        printf("%lld\n", ans);
    }
    return 0;
}
