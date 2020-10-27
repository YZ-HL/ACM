#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1005
using namespace std;
int n, m, dis[maxn];
int dp[maxn][15];
int dfs(int x, int las, int lim){
    if(x <= 0)    return (las == 4 ? 0 : 1);
    if(!lim && dp[x][las] >= 0)    return dp[x][las];
    int res = 0;
    int limm = lim ? dis[x] : 9;
    for(int i = 0; i <= limm; i++)
    {
        if(i == 4)
            continue;
        if(las == 6 && i == 2)
            continue;
        res += dfs(x - 1, i, i == limm && lim);
    }
    return lim ? res : dp[x][las] = res;
}
int calc(int x){
    dis[0] = 0;
    while(x)
        dis[++dis[0]] = x % 10, x /= 10;
    return dfs(dis[0], 0, 1);
}
int main(void)
{
    memset(dp, -1, sizeof(dp));
    while(scanf("%d %d", &n, &m), n)
        printf("%d\n", calc(m) - calc(n-1));        
    system("pause");
    return 0;
}
