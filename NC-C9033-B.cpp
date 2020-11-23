#include <bits/stdc++.h>
#define maxn 1000005
#define int long long
using namespace std;
int n, c[maxn], uset[maxn];
int find(int x){
    return x == uset[x] ? x : uset[x] = find(uset[x]);
}
void unionn(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy)
        return;
    uset[fx] = fy;
}
signed main(void)
{
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)    uset[i] = i;        
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
        if(c[i] == 0 && i > 1)    unionn(i, i - 1);
        if(c[i] == 1 && i < n)    unionn(i, i + 1);
    }
    for(int i = 1; i <= n; i++)
        if(uset[i] == i)
            ans++;
    printf("%d\n", ans);
    return 0;    
}