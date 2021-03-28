#include <bits/stdc++.h>
#define maxn 505
#define int long long
using namespace std;
int n, m, t, d;
int cnt, oil[maxn], g[maxn][maxn], ng[maxn][maxn];
const int INF = 1e16;
signed main(void)
{
    scanf("%lld %lld %lld %lld", &n, &m, &t, &d);
    for(int i = 1; i <= t; i++)
    {
        int tmp; scanf("%lld", &tmp);
        oil[tmp] = 1;
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                g[i][j] = ng[i][j] = 0;
            else
                g[i][j] = ng[i][j] = INF; 
        }
    }
    
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        g[u][v] = g[v][u] = w;
    }
    
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if((i == 1 || i == n || oil[i]) && (j == 1 || j == n || oil[j]))    
                if(g[i][j] <= d)
                    ng[i][j] = g[i][j];
    
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                ng[i][j] = min(ng[i][j], ng[i][k] + ng[k][j]);
                
    if(ng[1][n] >= INF)
        printf("stuck\n");
    else
        printf("%lld\n", ng[1][n]);

    //printf("%d %d %d %d\n", d, ng[2][4], ng[1][2], ng[4][6]);
    return 0;
}
