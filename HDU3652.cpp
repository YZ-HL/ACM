#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1005
using namespace std;
int n, dis[15], dp[15][15][15][15];
int dfs(int x, int lim, int isthr, int is1, int las, int mod){
    if(x <= 0)
        return (isthr && mod == 0) ? 1 : 0;
    if(!lim && dp[x][mod][isthr][is1] >= 0)
        return dp[x][mod][isthr][is1];
    int res = 0;
    int limm = lim ? dis[x] : 9;
    for(int i = 0; i <= limm; i++)
        res += dfs(x - 1, lim && i == limm, ((isthr || (las == 1 && i == 3)) ? 1 : 0), i == 1 ? 1 : 0, i, (mod*10+i) % 13);
    return lim ? res : dp[x][mod][isthr][is1] = res;
}
int calc(int x){
    dis[0] = 0;
    while(x)
        dis[++dis[0]] = x % 10, x /= 10;
    return dfs(dis[0], 1, 0, 0, 0, 0);
}
int main(void)
{
    memset(dp, -1, sizeof(dp));
    while(~scanf("%d", &n))
        printf("%d\n", calc(n));
    //system("pause");
    return 0;
}