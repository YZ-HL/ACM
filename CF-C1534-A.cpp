/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 105
using namespace std;
int t, n, m, vis[maxn][maxn];
char board[maxn][maxn];
int fx[] = {0, 1, -1, 0, 0};
int fy[] = {0, 0, 0, 1, -1};
char aread(){
    char ch = getchar();
    while(ch != '.' && ch != 'R' && ch != 'W')
        ch = getchar();
    return ch;
}
bool checkb(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
void dfs(int x, int y, char ncolor){
    vis[x][y] = 1;
    for(int i = 1; i <= 4; i++)
    {
        int nx = x + fx[i], ny = y + fy[i];
        if(!checkb(nx, ny))    continue;
        if(vis[nx][ny])    continue;
        board[nx][ny] = ncolor;
        dfs(nx, ny, (ncolor == 'R' ? 'W' : 'R'));
    }
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                board[i][j] = aread();
                if(board[i][j] != '.')    vis[i][j] = 1;
            }
        }
        int gg = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                if(board[i][j] != '.')    dfs(i, j, board[i][j] == 'R' ? 'W' : 'R'), gg = 1;
        }
        if(gg == 0)    
        {
            board[1][1] = 'W';
            dfs(1, 1, 'R');
        }
        bool flag = true;
        for(int i = 1; i <= n && flag; i++)
            for(int j = 1; j <= m && flag; j++)
            {
                if(board[i][j] == '.')    
                {
                    flag = false;
                    break;
                }
                for(int k = 1; k <= 4; k++)
                {
                    int nx = i + fx[k], ny = j + fy[k];
                    if(checkb(nx, ny) && board[nx][ny] == board[i][j])
                    {
                        flag = false;
                        break;
                    }
                }
            }
        if(flag)
        {
            printf("YES\n");
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= m; j++)
                    printf(j == m ? "%c\n" : "%c", board[i][j]);
        }
        else
            printf("NO\n");
    }
    return 0;
}