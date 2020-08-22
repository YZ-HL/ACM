#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1005
using namespace std;
int n, m, s;
int used[maxn][maxn];
char board[maxn][maxn];
int posx[maxn], posy[maxn];
void inits(){
    posx['N'] = -1;
    posx['E'] = 0;
    posx['S'] = 1;
    posx['W'] = 0;
    posy['N'] = 0;
    posy['E'] = 1;
    posy['S'] = 0;
    posy['W'] = -1;
}
void carry(int x, int y){
    int step = 0, loop = 0;
    while(x > 0 && y > 0 && x < n+1 && y < m+1)
    {
        used[x][y] = ++step;
        int nx = x + posx[board[x][y]];
        int ny = y + posy[board[x][y]];
        if(used[nx][ny])
        {
            step = used[nx][ny] - 1;
            loop = used[x][y] - used[nx][ny] + 1;
            break;
        }
        x = nx;
        y = ny;
    }
    if(loop)
        printf("%d step(s) before a loop of %d step(s)\n", step, loop);
    else
        printf("%d step(s) to exit\n", step);
}
int main(void)
{
    inits();
    while(scanf("%d %d %d", &n, &m, &s), n)
    {
        memset(used, 0, sizeof(used));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> board[i][j];
        int sx = 1, sy = s;
        carry(sx, sy);
    }  
    system("pause");
    return 0;
}
