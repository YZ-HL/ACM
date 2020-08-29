#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 1005
using namespace std;
int T;
int n, m;
char board[maxn][maxn];
int cnt, sn[maxn][maxn], nx[maxn], ny[maxn];
int vis[maxn][maxn], dis[maxn][maxn];
int flag[maxn], minn[maxn];
int posx[] = {0, 0, 0, 1, -1};
int posy[] = {0, 1, -1, 0, 0};
struct Node{
    int x;
    int y;
    int dis;
};
void inits(){
    cnt = 0;
    memset(sn, 0, sizeof(sn));
    memset(flag, 0, sizeof(flag));
    memset(minn, 0x3f, sizeof(minn));
    minn[1] = 0;
}
bool check(int x, int y){
    if(x < 1 || x > m || y < 1 || y > n)    return false;
    return board[x][y] != '#';
}
void bfs(int x, int y){
    memset(vis, 0, sizeof(vis));
    
    queue<Node> q1;
    q1.push((Node){x, y, 0});
    vis[x][y] = 1;
    while(!q1.empty())
    {
        Node tmp = q1.front(); q1.pop();

        if(sn[tmp.x][tmp.y])
        {
            //printf("debug: %d %d\n", sn[tmp.x][tmp.y], sn[x][y]);
            dis[sn[tmp.x][tmp.y]][sn[x][y]] = tmp.dis;
            dis[sn[x][y]][sn[tmp.x][tmp.y]] = tmp.dis;
        }
        for(int i = 1; i <= 4; i++)
            if(check(tmp.x+posx[i], tmp.y+posy[i]) && !vis[tmp.x+posx[i]][tmp.y+posy[i]])
            {
                //printf("debug: %d %d\n", tmp.x+posx[i], tmp.y+posy[i]);
                q1.push((Node){tmp.x+posx[i], tmp.y+posy[i], tmp.dis+1});
                vis[tmp.x+posx[i]][tmp.y+posy[i]] = 1;
            }
    }
    //system("pause");
}
int main(void)
{
    //freopen("output.txt", "w", stdout);
    
    scanf("%d", &T);
    while (T--)
    {
        inits();
        
        scanf("%d %d", &n, &m);
        gets(board[0]+1);
        for (register int i = 1; i <= m; i++)
        {
            gets(board[i]+1);
            for (register int j = 1; j <= n; j++)
            {
                if(board[i][j] == 'A' || board[i][j] == 'S')
                {
                    sn[i][j] = ++cnt;
                    nx[cnt] = i;
                    ny[cnt] = j;
                }
            }
        }
        
        for (int i = 1; i <= cnt; i++)
            bfs(nx[i], ny[i]);
        
        for (int i = 1; i <= cnt; i++)  
        {
            int k = 0;
            for (int j = 1; j <= cnt; j++)
                if (!flag[j] && minn[j] < minn[k])  k = j; 
            flag[k] = 1;
            for (int j = 1; j <= cnt; j++)
            {
                if (!flag[j] && dis[k][j] < minn[j])
                    minn[j] = dis[k][j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= cnt; i++)  ans += minn[i];
        printf("%d\n", ans);
    }
    //system("pause");
    return 0;
}