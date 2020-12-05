#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1005
#define mod 1000000007
#define int long long
using namespace std;
int n, m, board[maxn][maxn], dp[maxn][maxn][5], vis[maxn][maxn];
int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};
bool check(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
bool extended_end(int x, int y){
    for(int i = 1; i <= 4; i++)
    {
        if(!check(x + dx[i], y + dy[i]))    continue;
        if(board[x][y] + 1 == board[x + dx[i]][y + dy[i]])
            return false; 
    }
    return true;
}
bool extended_init(int x, int y){
    for(int i = 1; i <= 4; i++)
    {
        if(!check(x + dx[i], y + dy[i]))    continue;
        if(board[x][y] - 1 == board[x + dx[i]][y + dy[i]])
            return false; 
    }
    return true;
}
int dfs(int x, int y, int len){
    if(len == 1)
        return extended_init(x, y) ? 1 : 0;
    if(~dp[x][y][len])
        return dp[x][y][len];
    int res = 0;
    for(int i = 1; i <= 4; i++)
    {
        if(!check(x + dx[i], y + dy[i]))    continue;
        if(board[x][y] == board[x + dx[i]][y + dy[i]] + 1)
        {
            res = (res + dfs(x + dx[i], y + dy[i], len - 1)) % mod;
            if(len == 4)
                res = (res + dfs(x + dx[i], y + dy[i], len)) % mod;
        }
    }
    return dp[x][y][len] = res % mod;
}
signed main(void)
{
    memset(dp, -1, sizeof(dp));
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%lld", &board[i][j]);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(extended_end(i, j))
                ans = (ans + dfs(i, j, 4)) % mod;
    printf("%lld\n", ans);
    return 0;
}