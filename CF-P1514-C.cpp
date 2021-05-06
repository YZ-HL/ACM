#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int res = 1, flag = -1;
int n, cnt, ans[maxn];
signed main(void)
{
    //freopen("tmp.txt", "w", stdout);
    scanf("%lld", &n);
    for(int i = 1; i <= n - 1; i++)
    {
        if(__gcd(i, n) == 1)
            ans[++cnt] = i, res = (res * i) % n;
    }
    if(res != 1)    flag = res;
    printf("%lld\n", (~flag) ? cnt - 1 : cnt);
    for(int i = 1; i <= cnt; i++)
    {
        if(ans[i] == flag)    continue;
        printf("%lld ", ans[i]);
    }
    return 0;
}
