#include <bits/stdc++.h>
const int maxn = 105;
using namespace std;
int n, m, flag;
int sx, sy, tx, ty;
char board[maxn][maxn];
char gread(){
    char ch = getchar();
    while(ch != '.' && ch != '#')    ch = getchar();
    return ch;
}
struct pos{
    int x;
    int y;
    int st;
}p[maxn];
int ans, vis[maxn][maxn];
int fx[] = {0, 1, -1, 0, 0};
int fy[] = {0, 0, 0, 1, -1};
void bfs(){
    queue<pos> q1;
    q1.push((pos){sx, sy, 0});
    while(!q1.empty())
    {
        int nx = q1.front().x, ny = q1.front().y, ns = q1.front().st;
        q1.pop();
        if(nx == tx && ny == ty)
        {
            ans = ns;
            flag = 1;
            return;
        }
        for(int i = 1; i <= 4; i++)
        {
            int npx = nx + fx[i], npy = ny + fy[i];
            if(board[npx][npy] == '#')    continue;
            if(vis[npx][npy])    continue;
            if(npx < 1 || npy < 1 || npx > n || npy > m)    continue;
            vis[npx][npy] = 1;
            q1.push((pos){npx, npy, ns + 1});
        }
    }
}
signed main(void)
{
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            board[i][j] = gread();
    bfs();
    if(!flag)
        printf("-1\n");
    else
        printf("%d\n", ans * 100);
    return 0;
}