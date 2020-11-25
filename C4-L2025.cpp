#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n, m, k, uu[maxn], vv[maxn], ban[maxn], uset[maxn];
int find(int x){
    return x == uset[x] ? x : uset[x] = find(uset[x]);
}
void unioon(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy)    return;
    uset[fx] = fy;
}
int main(void)
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
        scanf("%d %d", &uu[i], &vv[i]);
    scanf("%d", &k);
    for(int l = 1; l <= k; l++)
    {
        for(int i = 1; i <= n; i++)    
            ban[i] = 0, uset[i] = i;
        int np;    
        scanf("%d", &np);
        for(int i = 1; i <= np; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            ban[tmp] = 1;
        }
        for(int i = 1; i <= m; i++)
        {
            if(ban[uu[i]] || ban[vv[i]])
                continue;
            unioon(uu[i], vv[i]);
        }
        int flag = 1;
        for(int i = 1; i <= n; i++)
        {
            if(ban[i])    continue;
            if(uset[i] != i)    
            {
                flag = 0;
                break;
            }
        }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}
