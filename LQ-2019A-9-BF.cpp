#include <bits/stdc++.h>
#define maxn 105
using namespace std;
int n, m, k, ans = 105, t[maxn], used[maxn];
void dfs(int sta, int cost){
    if(sta == (1 << m) - 1)
    {
        ans = min(ans, cost);
        return;
    }
    if(cost > ans)    return;
    for(int i = 1; i <= n; i++)
    {
        if(used[i])    continue;
        used[i] = 1;
        dfs(sta | t[i], cost + 1);
        used[i] = 0;
    }
}
int main(void)
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
    {
        int tmp, sta = 0; 
        for(int j = 1; j <= k; j++)
        {
            scanf("%d", &tmp);
            sta |= (1 << (tmp - 1));
        }
        t[i] = sta;
    }
    dfs(0, 0);
    printf("%d\n", ans == 105 ? -1 : ans);
    return 0;
}
//dp[前n包][状态]=最少数目
//O(n*(2^20))