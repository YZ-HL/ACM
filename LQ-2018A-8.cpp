#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int n, vis[maxn][maxn];
int c, color[maxn][maxn];
int used[maxn * maxn], ans;

char board[maxn][maxn];

char get_read(){
    char ch = getchar();
    while(ch != '.' && ch != '#')    ch = getchar();
    return ch;
}

int fx[] = {0, 1, -1, 0, 0};
int fy[] = {0, 0, 0, 1, -1};

void dfs(int x, int y, int c){
    color[x][y] = c;
    for(int i = 1; i <= 4; i++)
        if(board[x + fx[i]][y + fy[i]] == '#' && !color[x + fx[i]][y + fy[i]])
            dfs(x + fx[i], y + fy[i], c);
}

int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            board[i][j] = get_read();

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(!color[i][j] && board[i][j] == '#')    dfs(i, j, ++c);
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(board[i + 1][j] == '#' && board[i - 1][j] == '#' && 
               board[i][j + 1] == '#' && board[i][j - 1] == '#'  )    vis[i][j] = 1;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(board[i][j] == '#' && !used[color[i][j]] && vis[i][j])   used[color[i][j]] = 1, ans++;
    
    printf("%d\n", ans);
}