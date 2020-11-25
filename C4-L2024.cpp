#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n, k, q, sum, ans, vis[maxn], uset[maxn];
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
    for(int i = 1; i <= 10000; i++)    uset[i] = i;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int la, now;
        scanf("%d", &k);
        scanf("%d", &la);
        if(!vis[la])    vis[la] = 1, sum++;
        for(int j = 2; j <= k; j++)
        {
            scanf("%d", &now);
            if(!vis[now])    vis[now] = 1, sum++;
            unioon(la, now);
            la = now;
        }
    }
    for(int i = 1; i <= sum; i++)
        if(uset[i] == i)    ans++;
    printf("%d %d\n", sum, ans);
    scanf("%d", &q);
    while(q--)
    {
        int xx, yy;
        scanf("%d %d", &xx, &yy);
        printf(find(xx) == find(yy) ? "Y\n" : "N\n");
    }    
    return 0;
}
