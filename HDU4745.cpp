#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1005
using namespace std;
int n, w[maxn], dp[maxn][maxn];
int dfs(int lf, int rt){
    if(lf > rt)
        return 0;
    if(dp[lf][rt] >= 0)
        return dp[lf][rt];
    int maxx = -1;
    if(w[lf] == w[rt])
        maxx = max(maxx, dfs(lf+1, rt-1) + 2);
    maxx = max(maxx, max(dfs(lf+1, rt), dfs(lf, rt-1)));
    return dp[lf][rt] = maxx;
}
int main(void)
{
    while(scanf("%d", &n), n)
    {
        memset(dp, -1, sizeof(dp));
        for(int i = 1; i <= n; i++)
            scanf("%d", &w[i]), dp[i][i] = 1;
        dfs(1, n);
        int ans = 1;
        for(int i = 1; i <= n - 1; i++)
            ans = max(ans, dp[1][i] + dp[i + 1][n]);
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}
