//HDU1521 搜索再练
//由于种类不定，无优秀的记忆化思路
//或许可以用奇怪的HASH来完成
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, m, ans, used[maxn];
void dfs(int now){
    if(now == 0)
    {
        ans++;
        return;
    }
    for(int i = 1; i <= n; i++)
        if(used[i])
        {
            used[i]--;
            dfs(now - 1);
            used[i]++;
        }
}
int main(void)
{
    while(~scanf("%d %d", &n, &m))
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &used[i]);
        ans = 0;
        dfs(m);
        printf("%d\n", ans);
    }
    return 0;
}
