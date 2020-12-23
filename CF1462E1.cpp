#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int t, n, ans, a[maxn], b[maxn], fac[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        ans = 0;
        //memset(b, 0, sizeof(b));
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            //3: a-2,a-1,a; a-1,a+1,a; a+2,a+1,a;
            ans += b[a[i] - 1] * b[a[i] + 1];
            ans += b[a[i] - 2] * b[a[i] - 1];
            ans += b[a[i] + 1] * b[a[i] + 2];
            //1: a,a,a
            if(b[a[i]] >= 2)
                ans += b[a[i]] * (b[a[i]] - 1) / 2;
            //4: a,a,(a-2,a-1,a+1,a+2)
            if(b[a[i]] >= 1)
                ans += b[a[i]] * b[a[i] - 1] + 
                       b[a[i]] * b[a[i] + 1] + 
                       b[a[i]] * b[a[i] - 2] + 
                       b[a[i]] * b[a[i] + 2] ; 
            //1: a-1,a-1,a
            if(b[a[i] - 1] >= 2)
                ans += b[a[i] - 1] * (b[a[i] - 1] - 1) / 2;
            //1: a+1,a+1,a
            if(b[a[i] + 1] >= 2)
                ans += b[a[i] + 1] * (b[a[i] + 1] - 1) / 2;
            //1: a-2,a-2,a
            if(b[a[i] - 2] >= 2)
                ans += b[a[i] - 2] * (b[a[i] - 2] - 1) / 2;
            //1: a+2,a+2,a
            if(b[a[i] + 2] >= 2)
                ans += b[a[i] + 2] * (b[a[i] + 2] - 1) / 2;
            b[a[i]]++;
        }
        for(int i = 1; i <= n; i++)    b[a[i]] = 0;
        printf("%lld\n", ans);
    }
    return 0;
}
