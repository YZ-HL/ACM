#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n, m;
int a[maxn], c[maxn], dp[maxn];
int nn, nc[maxn], nv[maxn];
int main(void)
{
    while(scanf("%d %d", &n, &m), n)
    {
        nn = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++)
            scanf("%d", &c[i]);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            if(c[i] * a[i] >= m)
            {
                for(int j = a[i]; j <= m; j++)    dp[j] |= dp[j - a[i]];
                continue;
            }
            int now = c[i], bas = 1;
            while(now >= bas)
            {
                nn++;
                nc[nn] = bas;
                nv[nn] = bas * a[i];
                now -= bas; 
                bas *= 2;
            }
            if(now)
            {
                nn++;
                nc[nn] = now;
                nv[nn] = now * a[i];
            }
            for(int k = 1; k <= nn; k++)
                for(int j = m; j >= nv[k]; j--) dp[j] |= dp[j - nv[k]];   
            nn = 0;
        }
        int cnt = 0;
        for(int i = 1; i <= m; i++)
            if(dp[i])    cnt++;
        printf("%d\n", cnt);
    }
    //system("pause");
    return 0;
}
