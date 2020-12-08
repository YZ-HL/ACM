#include <bits/stdc++.h>
#define maxn 1005
#define int long long
using namespace std;
int n, m, l[maxn], r[maxn], h[maxn][maxn];
char board[maxn][maxn];
char read(){
    char ch = getchar();
    while(ch != 'R' && ch != 'F')   ch = getchar();
    return ch;
}
signed main(void)
{
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            board[i][j] = read();
            h[i][j] = board[i][j] == 'F' ? h[i-1][j] + 1 : 0;
        }
    int ans = 0;
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= m; i++)
        {
            l[i] = i;
            while(l[i] > 1 && h[k][i] <= h[k][l[i]-1])    l[i] = l[l[i]-1];
        }
        for(int i = m; i >= 1; i--)   
        {
            r[i] = i;
            while(r[i] < m && h[k][i] <= h[k][r[i]+1])    r[i] = r[r[i]+1];
        }
        for(int i = 1; i <= m; i++)
            ans = max(ans, h[k][i] * (r[i] - l[i] + 1));
    }
    printf("%lld\n", ans * 3);
    return 0;
}