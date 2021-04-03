#include <bits/stdc++.h>
#define maxn 505
using namespace std;
int n, board[maxn][maxn], dp[maxn][maxn];
int dfs(int lf, int rt){
    //printf("debug: %d %d\n", lf, rt);
    if(~dp[lf][rt])
        return dp[lf][rt];
    if(lf >= rt)        return dp[lf][rt] = 0;
    if(lf == rt - 1)    return dp[lf][rt] = board[lf][rt];
    int ans = 0;
    for(int k = lf + 1; k <= rt; k++)
        ans = max(ans, dfs(lf + 1, k - 1) + dfs(k + 1, rt) + board[lf][k]);
    ans = max(ans, dfs(lf + 1, rt));
    dp[lf][rt] = ans;
    //printf("debug: %d %d %d\n", lf, rt, dp[lf][rt]);
    return dp[lf][rt];
}
int main(void)
{
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    //printf("%d\n", dp[2][4]);
    printf("%d\n", dfs(1, n));
    return 0;
}