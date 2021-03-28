#include <bits/stdc++.h>
#define maxn 800005
#define int long long
using namespace std;
int n, a, b, uset[maxn], flag[maxn], vis[maxn];
map<int, int> mp;
int find(int x){
    return x == uset[x] ? x : uset[x] = find(uset[x]);
}
void unioon(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy)    
    {
        flag[fx] = 1;
        return;
    }
    uset[fx] = fy;
    flag[fx] = flag[fy] = (flag[fx] | flag[fy]);
}
signed main(void)
{
    //freopen("1_009.txt", "r", stdin);
    scanf("%lld", &n);
    for(int i = 1; i <= maxn - 5; i++)    uset[i] = i;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld %lld", &a, &b);
        unioon(a, b);
        vis[a] = vis[b] = 1;
    }  
    for(int i = 1; i <= maxn - 5; i++)
    {
        if(vis[i])
        {
            mp[find(i)]++;
        }
    }
    int ans = 0;
    for(map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        if(flag[(*iter).first])
            ans += (*iter).second;
        else
            ans += (*iter).second - 1;
    }
    printf("%lld\n", ans);
    return 0;
}
