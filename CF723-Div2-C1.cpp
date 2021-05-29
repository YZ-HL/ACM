#include <bits/stdc++.h>
#define maxn 2005
#define int long long
using namespace std;
int n, a[maxn];
int maxx;
void dfs(int nowh, int pos, int cnt){
    if(nowh < 0)
        return;
    if(pos == n + 1)
    {
        maxx = max(maxx, cnt);
        return;
    }
    if(cnt + (n - pos + 1) <= maxx)    return;
    dfs(nowh + a[pos], pos + 1, cnt + 1);
    dfs(nowh, pos + 1, cnt);
}
signed main(void)
{  
    //freopen("debut.txt", "w", stdout);
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);   
    dfs(0, 1, 0);
    printf("%lld\n", maxx);
    return 0;
}