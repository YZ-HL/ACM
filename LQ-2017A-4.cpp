#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int fx[] = {0, 1, -1, 0, 0};
int fy[] = {0, 0, 0, 1, -1};
int ans, vis[maxn][maxn];
void dfs(int x, int y){
    if(x == 1 || y == 1 || x == 7 || y == 7)
    {
        ans++;
        return;
    }
    for(int i = 1; i <= 4; i++)
    {
        int nx = x + fx[i], ny = y + fy[i];
        if(!vis[nx][ny] && !vis[8 - nx][8 - ny])
        {
            vis[nx][ny] = 1;
            vis[8 - nx][8 - ny] = 1;
            dfs(nx, ny);
            vis[nx][ny] = 0;
            vis[8 - nx][8 - ny] = 0;
        }
    }
}
int main(void)
{
    vis[4][4] = 1;
    dfs(4, 4);
    printf("%d\n", ans / 4);
    return 0;
}
