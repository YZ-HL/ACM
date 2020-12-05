#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1005
using namespace std;
int t, n, m, sr, sc, tr, tc, cases;
int seq[maxn * maxn], val[maxn][maxn], dp[maxn][maxn], a, b, c, p;
int main(void)
{
    scanf("%d", &t);
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        scanf("%d %d %d %d %d %d", &n, &m, &sr, &sc, &tr, &tc);
        scanf("%d %d %d %d %d %d", &seq[1], &seq[2], &a, &b, &c, &p);
        for (int i = 3; i <= n * m; i++)
            seq[i] = (a * seq[i - 1] + b * seq[i - 2] + c) % p;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                val[i][j] = seq[(i - 1) * m + j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = max(dp[i-1][j] + val[i][j] * val[i-1][j], dp[i][j-1] + val[i][j] * val[i][j-1]);
        printf("Case #%d: %d\n", ++cases, dp[n][m]);
    }
    return 0;
}
