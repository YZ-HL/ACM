#include <bits/stdc++.h>
#define maxn 505
using namespace std;
int n, m, k;
int dis1[maxn][maxn], dis2[maxn][maxn];
int dp[maxn][maxn][55];
int dfs(int nowx, int nowy, int k){
    if(~dp[nowx][nowy][k])
        return dp[nowx][nowy][k];
    if(k == 0)
        return dp[nowx][nowy][k] = 0;
    int val = (1 << 30);
    if(nowx < n)
        val = min(val, dfs(nowx + 1, nowy, k - 2) + dis2[nowx][nowy] * 2);
    if(nowy < m)
        val = min(val, dfs(nowx, nowy + 1, k - 2) + dis1[nowx][nowy] * 2);
    if(nowx > 1)
        val = min(val, dfs(nowx - 1, nowy, k - 2) + dis2[nowx - 1][nowy] * 2);
    if(nowy > 1)
        val = min(val, dfs(nowx, nowy - 1, k - 2) + dis1[nowx][nowy - 1] * 2);
    return dp[nowx][nowy][k] = val;
}
int main(void)
{
    memset(dp, -1, sizeof(dp));
    memset(dis1, 0x3f, sizeof(dis1));
    memset(dis2, 0x3f, sizeof(dis2));
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m - 1; j++)
            scanf("%d", &dis1[i][j]);
    for(int i = 1; i <= n - 1; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &dis2[i][j]);
    if(k & 1)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                printf(j == m ? "%d\n" : "%d ", -1);
            }
        }
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                dfs(i, j, k);
                printf(j == m ? "%d\n" : "%d ", dp[i][j][k]);
            }
        }
    }
    return 0;
}
