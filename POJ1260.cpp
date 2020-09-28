#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int t, n, a[maxn], p[maxn], sum[maxn], dp[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        sum[0] = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d", &a[i], &p[i]);
            sum[i] = sum[i-1] + a[i];
        }
        for(int i = 1; i <= n; i++)
        {
            dp[i] = dp[i-1] + (a[i] + 10) * p[i];
            for(int j = i-1; j >= 0; j--)
                dp[i] = min(dp[i], dp[j] + (sum[i] - sum[j] + 10) * p[i]);
        }
        printf("%d\n", dp[n]);
    }
    system("pause");
    return 0;
}
