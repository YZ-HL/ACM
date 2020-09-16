#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1000005
using namespace std;
int m, n, nk[maxn], dk[maxn], num, c[maxn], v[maxn], dp[maxn+5];
int main(void)
{
    while(~scanf("%d %d", &m, &n))
    {
        num = 0;
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d", &nk[i], &dk[i]);
            for(int bas = 1; bas <= nk[i]; bas *= 2)
            {
                c[++num] = bas*dk[i];
                nk[i] -= bas;
            }
            if(nk[i])
                c[++num] = nk[i]*dk[i];
        }
        for(int i = 1; i <= num; i++)
            for(int j = m; j >= c[i]; j--)
                dp[j] = max(dp[j], dp[j-c[i]]+c[i]);
        printf("%d\n", dp[m]);
    }
    system("pause");
    return 0;
}
