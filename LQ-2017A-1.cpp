#include <bits/stdc++.h>
#define maxn 105
using namespace std;
int vis[maxn][maxn], can[maxn][maxn];
char board[maxn][maxn];
char read(){
    char ch = getchar();
    while(ch < 'A' || ch > 'Z')    ch = getchar();
    return ch;
}
int dfs(int x, int y){
    if(x < 1 || x > 10 || y < 1 || y > 10)
        return can[x][y] = 1;
    if(vis[x][y])
        return can[x][y] = (can[x][y] == 1 ? 1 : -1);
    vis[x][y] = 1;
    if(board[x][y] == 'U')
        can[x][y] = dfs(x - 1, y);
    if(board[x][y] == 'D')
        can[x][y] = dfs(x + 1, y);
    if(board[x][y] == 'L')
        can[x][y] = dfs(x, y - 1);
    if(board[x][y] == 'R')
        can[x][y] = dfs(x, y + 1);
    return can[x][y];
}
int main(void)
{
    for(int i = 1; i <= 10; i++)
        for(int j = 1; j <= 10; j++)
            board[i][j] = read();
    for(int i = 1; i <= 10; i++)
        for(int j = 1; j <= 10; j++)
            if(!vis[i][j])    dfs(i, j);
    /*
    for(int i = 1; i <= 10; i++)
        for(int j = 1; j <= 10; j++)
            printf(j == 10 ? "%d\n" : "%d ", can[i][j]);
    */
    int ans = 0;
    for(int i = 1; i <= 10; i++)
        for(int j = 1; j <= 10; j++)
            if(can[i][j] == 1)    ans++;
    printf("%d\n", ans);
    return 0;
}
