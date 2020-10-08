#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 5005
using namespace std;
short n, dp[maxn][maxn];
char str[maxn], str_r[maxn];
short LCS_DP(int l1, int l2){
    if(l1 < 1 || l2 < 1)
        return dp[l1][l2] = 0;
    if(dp[l1][l2] >= 0)
        return dp[l1][l2];
    if(str[l1] == str_r[l2])
        dp[l1][l2] = LCS_DP(l1 - 1, l2 - 1) + 1;
    else
        dp[l1][l2] = max(dp[l1][l2], max(LCS_DP(l1-1, l2), LCS_DP(l1, l2-1)));
    return dp[l1][l2];
}
int main(void)
{
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    scanf("%s", str+1);
    for(int i = n; i >= 1; i--)
        str_r[n - i + 1] = str[i];
    printf("%d\n", n - LCS_DP(n, n));
    system("pause");
    return 0;
}
