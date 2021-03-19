#include <bits/stdc++.h>
#define int long long
const int maxn = 2e5 + 5;
using namespace std;
int n, q, cnt, uset[maxn];
string s;
map<string, int> mp;
struct Edge{
    int u;
    int v;
    int w;
}E[maxn];
int find(int x){
    return x == uset[x] ? x : uset[x] = find(uset[x]);
}
void unioon(int x, int y){
    int fx = find(x), fy = find(y);
    if(fx == fy)    return;
    uset[fx] = fy;
}
bool cmp(const Edge &A, const Edge &B){
    return A.w < B.w;
}
int Kruskal(){
    int nlink = 0, sum = 0;
    for(int i = 1; i <= q; i++)
    {
        int nu = E[i].u, nv = E[i].v, nw = E[i].w;
        if(find(nu) == find(nv))    continue;
        unioon(nu, nv);
        sum += nw; nlink++;
        if(nlink == n - 1)    return sum;
    }
    return -1;
}
signed main(void)
{
    while(cin >> n >> q)
    {
        mp.clear(); cnt = 0;
        for(int i = 1; i <= n; i++)    uset[i] = i;
        cin >> s;
        for(int i = 1; i <= q; i++)
        {
            int w; string u, v;
            cin >> u >> v >> w;
            if(!mp.count(u))    mp[u] = ++cnt;
            if(!mp.count(v))    mp[v] = ++cnt;
            E[i].u = mp[u], E[i].v = mp[v], E[i].w = w;
        }
        sort(E + 1, E + q + 1, cmp);
        int res = Kruskal();
        if(res == -1)
            cout << "No!" << '\n';
        else
            cout << res << '\n';
    }
}