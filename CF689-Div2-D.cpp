#include <bits/stdc++.h>
#define maxn 400005
#define INF (1 << 30)
#define int long long
using namespace std;
int t, n, q, a[maxn];
int tmp1[maxn], tmp2[maxn];
set<int> vis;
void solve(int lf, int rt){
    //printf("de: %lld %lld\n", lf, rt);
    int maxx = -INF, minn = INF, sum = 0, flag = 1;
    
    for(int i = lf; i <= rt; i++)
    {
        maxx = max(a[i], maxx);
        minn = min(a[i], minn);
        sum += a[i];
    }
    if(!vis.count(sum))    vis.insert(sum);
    
    if(maxx == minn)     return;
    
    int mid = (maxx + minn) / 2;
    int cnt1 = 0, cnt2 = 0;
    for(int i = lf; i <= rt; i++)
    {
        if(a[i] <= mid)
            tmp1[++cnt1] = a[i];
        else
            tmp2[++cnt2] = a[i];
    }
    //printf("%lld %lld %lld %lld %lld\n", lf, rt, cnt1, cnt2, mid);
    for(int i = lf; i <= lf + cnt1 - 1; i++)
        a[i] = tmp1[i - lf + 1];
    for(int i = lf + cnt1; i <= rt; i++)
        a[i] = tmp2[i - lf - cnt1 + 1];
    solve(lf, lf + cnt1 - 1);
    solve(lf + cnt1, rt);
}
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        vis.clear();
        scanf("%lld %lld", &n, &q);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        solve(1, n);
        for(int i = 1; i <= q; i++)
        {
            int tmpq;
            scanf("%lld", &tmpq);
            printf(vis.count(tmpq) ? "Yes\n" : "No\n");
        }
    }
    return 0;
}