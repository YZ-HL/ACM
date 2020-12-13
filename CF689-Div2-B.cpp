#include <bits/stdc++.h>
#define maxn 505
using namespace std;
int t, n, m, sum[maxn][maxn];
char board[maxn][maxn];
char read(){
    char ch = getchar();
    while(ch != '.' && ch != '*')   ch = getchar();
    return ch;
}
bool check(int x, int y, int dep){
    if(dep == 1)    return board[x][y] == '*';
    int lf = y - dep + 1, rt = y + dep - 1, c = x + dep - 1;
    if(lf < 1 || rt > m || c > n)    return false;
    return sum[c][rt] - sum[c][lf-1] == (rt - lf + 1);
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                board[i][j] = read();
                sum[i][j] = sum[i][j-1] + (board[i][j] == '*' ? 1 : 0);
            }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                int dep = 1;
                while(check(i, j, dep))
                    ans++, dep++;
            }
        printf("%d\n", ans);
    }
}