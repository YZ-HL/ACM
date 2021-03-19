#include <bits/stdc++.h>
const int maxn = 25;
using namespace std;
int n, x, a[maxn], b[maxn];
__int128 dp[(1 << 20)];
__int128 dfs(int sta){
    if(sta == (1 << n) - 1)    return 0;
    if(dp[(1 << n) - 1])       return dp[(1 << n) - 1];
    __int128 val = 0;
    for(int i = 1; i <= n; i++)
    {
        if(sta & (1 << (i - 1)))    continue;
        val = max(val, a[i] * val + b[i] + dfs(sta | (1 << (i - 1))));
    }
    return dp[sta] = val;
}
void print(__int128 now){
    if(now > 10)    print(now / 10);
    putchar(now % 10 + '0');
}
int main(void)
{
    scanf("%d %d", &n, &x);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &a[i], &b[i]);
    dfs(0);
    print(dp[(1 << n) - 1]);
    return 0;
}