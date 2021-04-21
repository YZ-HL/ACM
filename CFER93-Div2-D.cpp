#include <bits/stdc++.h>
#define maxn 205
using namespace std;
int rr[maxn], gg[maxn], bb[maxn];
int dp[maxn][maxn][maxn];
int dfs(int r, int g, int b){
    if(~dp[r][g][b])
        return dp[r][g][b];
    int maxx = 0;
    if(r && g)
        maxx = max(maxx, dfs(r - 1, g - 1, b) + rr[r] * gg[g]);
    if(r && b)
        maxx = max(maxx, dfs(r - 1, g, b - 1) + rr[r] * bb[b]);
    if(b && g)
        maxx = max(maxx, dfs(r, g - 1, b - 1) + gg[g] * bb[b]);
    return dp[r][g][b] = maxx;
}
int main(void)
{
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    for(int i = 1; i <= a; i++)
        scanf("%d", &rr[i]);
    for(int i = 1; i <= b; i++)
        scanf("%d", &gg[i]);
    for(int i = 1; i <= c; i++)
        scanf("%d", &bb[i]);
    sort(rr + 1, rr + a + 1);
    sort(gg + 1, gg + b + 1);
    sort(bb + 1, bb + c + 1);
    printf("%d\n", dfs(a, b, c));
    return 0;
}
