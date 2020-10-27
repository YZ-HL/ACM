#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 2050
using namespace std;
int n, bas[maxn];
double mar[maxn][maxn], dp[maxn][maxn];
int main(void)
{
    //freopen("football.in", "r", stdin);
    //freopen("my.out", "w", stdout);
    bas[1] = 2;
    for (int i = 2; i <= 8; i++)    bas[i] = bas[i - 1] * 2;
    while (scanf("%d", &n), ~n)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= bas[n]; i++)
            for (int j = 1; j <= bas[n]; j++)
                scanf("%lf", &mar[i][j]);
        for (int j = 1; j <= bas[n]; j++)
            dp[1][j] = j & 1 ? mar[j][j + 1] : mar[j][j - 1];
        for (int i = 2; i <= n; i++)
        {
            int cnt = 0, flag = 0;
            for (int j = 1; j <= bas[n]; j++)
            {
                cnt++;
                if (!flag)
                {
                    for (int k = j + bas[i - 1] - cnt + 1; k <= j + 2 * bas[i - 1] - cnt; k++)
                        dp[i][j] += dp[i - 1][j] * dp[i - 1][k] * mar[j][k];
                    if (cnt == bas[i - 1])
                        cnt = 0, flag = 1;
                    continue;
                }
                if (flag)
                {
                    for (int k = j - bas[i - 1] - cnt + 1; k <= j - cnt; k++)
                        dp[i][j] += dp[i - 1][j] * dp[i - 1][k] * mar[j][k];
                    if (cnt == bas[i - 1])
                        cnt = 0, flag = 0;
                    continue;
                }
            }
            /*
            for(int l = 1; l <= bas[n]; l++)
                printf("dp[%d][%d]=%lf\n", i, l, dp[i][l]);
            */
        }
        int pos = 0;
        double maxx = 0;
        for (int j = 1; j <= bas[n]; j++)
            if (dp[n][j] > maxx)
                maxx = dp[n][j], pos = j;
        printf("%d\n", pos);
    }
    //system("pause");
    return 0;
}