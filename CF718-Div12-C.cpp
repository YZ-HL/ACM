#include <bits/stdc++.h>
#define maxn 505
using namespace std;
int n, p[maxn], board[maxn][maxn];
bool dfs(int x, int y, int cnt, int r){
    if(cnt == 0)    return true;
    if(x + 1 <= n && board[x + 1][y] == 0)
    {
        board[x + 1][y] = r;
        return dfs(x + 1, y, cnt - 1, r);
    }
    else if(y - 1 >= 1 && board[x][y - 1] == 0)
    {
        board[x][y - 1] = r;
        return dfs(x, y - 1, cnt - 1, r);
    }
    else    return false;
}
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)    
    {
        scanf("%d", &p[i]);
        board[i][i] = p[i];
    }
    bool fail = false;
    for(int i = n; i >= 1; i--)
    {
        bool flag = dfs(i, i, p[i] - 1, p[i]);
        if(flag == false)
        {
            fail = true;
            break;
        }
    }
    if(fail)
        printf("-1\n");
    else
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i; j++)
                printf(j == i ? "%d\n" : "%d ", board[i][j]);
    }
    return 0;
}
