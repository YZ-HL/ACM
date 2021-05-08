#include <bits/stdc++.h>
#define maxn 205
using namespace std;
int t, n;
int board[maxn][maxn];
int main(void)
{
    //freopen("tmp.txt", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        memset(board, 0, sizeof(board));

        scanf("%d", &n);
        
        if(n == 2)
        {
            printf("-1\n");
            continue;
        }
        
        if(n % 2 == 0)
        {
            for(int i = 1; i <= n; i++)
                board[1][i] = 1 + 2 * (i - 1);
        
            for(int i = 2; i <= n / 2; i++)
                for(int j = 1; j <= n; j++)
                    board[i][j] = board[i - 1][j] + n * 2;

            for(int i = 1; i <= n; i++)
                board[n / 2 + 1][i] = 2 + 2 * (i - 1);

            for(int i = n / 2 + 2; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    board[i][j] = board[i - 1][j] + n * 2;
        }
        else
        {
            int mod = n * n;
            
            for(int i = 1; i <= n; i++)
                board[1][i] = 1 + 2 * (i - 1);
            
            for(int i = 2; i <= n; i++)
                for(int j = 1; j <= n; j++)
                {
                    board[i][j] = (board[i - 1][j] + n) % mod;
                    if(board[i][j] == 0)    board[i][j] = mod;
                }
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                printf(j == n ? "%d\n" : "%d ", board[i][j]);
    }
    return 0;
}
