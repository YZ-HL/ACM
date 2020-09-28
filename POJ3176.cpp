#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1005
using namespace std;
int n, ans, board[maxn][maxn], dp[maxn][maxn];
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            scanf("%d", &board[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + board[i][j];
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[n][i]);
    printf("%d\n", ans);
    system("pause");
    return 0;
}
