#include <bits/stdc++.h>
#define maxn 105
using namespace std;
int n;
double res, ans, p[maxn], dp[maxn][maxn];
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)    
    {
        scanf("%lf", &p[i]);
        p[i] *= 0.01;
    }
    sort(p + 1, p + n + 1, greater<double>());
    
    //dp[1][0] = 1.0 - p[1];
    //dp[1][1] = p[1];
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        res = 0;
        for(int j = 0; j <= i; j++)
        {
            if(j == 0)    
                dp[i][j] = dp[i - 1][j] * (1.0 - p[i]);
            else if(j == i)
                dp[i][j] = dp[i - 1][j - 1] * p[i];
            else
                dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1.0 - p[i]);
            if(j)
                res += dp[i][j] * pow(j, 1.0 * j / i);
        }
        ans = max(ans, res);
    }
    printf("%.9lf\n", ans);
    return 0;
}
