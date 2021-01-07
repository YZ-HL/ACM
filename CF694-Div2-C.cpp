#include <bits/stdc++.h>
#define maxn 400005
#define int long long
using namespace std;
int t, n, m, a[maxn], c[maxn], cki[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for(int i = 1; i <= m; i++)
            scanf("%lld", &c[i]);
        for(int i = 1; i <= n; i++)
            cki[i] = c[a[i]];
        
        sort(a + 1, a + n + 1);
        sort(cki + 1, cki + n + 1);
        
        int lf = 1, rt = n, ans = 0, num = 0;
        while(1)
        {
            if(a[rt] >= lf && c[lf] <= cki[rt] && lf <= m && num < n)
            {
                num++;
                ans += c[lf];
                rt--;
                lf++;
            }
            else
                break;
        }
        //printf("%lld %lld %lld\n", lf, rt, ans);
        for(int i = 1; i <= n - num; i++)    ans += cki[i];
        printf("%lld\n", ans);
    }
    return 0;
}