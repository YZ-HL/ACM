#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 105
using namespace std;
int n, dis[maxn][maxn];
int main(void)
{
    while(scanf("%d", &n), n)
    {
        memset(dis, 0x3f, sizeof(dis));
        for (int i = 1; i <= n; i++)
            dis[i][i] = 0;
        
        for (int i = 1; i <= n; i++)
        {
            int m;
            scanf("%d", &m);
            for (int j = 1; j <= m; j++)
            {
                int a, b;
                scanf("%d %d", &a, &b);
                dis[i][a] = b;
            }
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

        int pos = -1, posans = (int)1e9;
        for (int i = 1; i <= n; i++)
        {
            int maxx = -1;
            for (int j = 1; j <= n; j++)
                maxx = max(maxx, dis[i][j]);
            if(posans > maxx)
                pos = i, posans = maxx;
        }
        pos == -1 ? printf("disjoint\n") : printf("%d %d\n", pos, posans);
    }
    system("pause");
    return 0;
}
