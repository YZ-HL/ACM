#pragma GCC optimize(3, "Ofast", "inline")

#include <bits/stdc++.h>
const int maxn = 20 + 5;
using namespace std;
int n, k, R, ans, ex[maxn], ey[maxn], er[maxn], over[maxn];
int att[maxn][maxn];
int calc(int nx, int ny){
    int sta = 0;
    for(int i = 1; i <= n; i++)
    {
        double dis = sqrt((1.0 * nx - ex[i]) * (1.0 * nx - ex[i]) +
                          (1.0 * ny - ey[i]) * (1.0 * ny - ey[i]));
        if(dis < R + er[i])
            sta |= (1 << i);
        else if(fabs(dis - R - er[i]) <= 1e-6)
            sta |= (1 << i);
    }
    return sta;
}
void dfs(int now, int num, int st){
    if(now == 0)
    {
        ans = max(ans, num);
        return;
    }
    for(int i = -7; i <= 7; i++)
        for(int j = -7; j <= 7; j++)
        {
            int r = att[i + 10][j + 10], nown = 0;
            for(int i = 1; i <= n; i++)
            {
                if(r & (1 << i))    over[i] = 1;
                if(over[i])    nown++;
            }
            dfs(now - 1, nown, st | r);
            for(int i = 1; i <= n; i++)
                if(r & (1 << i) && !(st & (1 << i)))    
                	over[i] = 0;
        }
}
void inits(){
	for(int i = -7; i <= 7; i++)
        for(int j = -7; j <= 7; j++)
            att[i + 10][j + 10]= calc(i, j);
}
int main(void)
{
    scanf("%d %d %d", &n, &k, &R);
    for(int i = 1; i <= n; i++)
        scanf("%d %d %d", &ex[i], &ey[i], &er[i]);
    inits();
    dfs(k, 0, 0);
    printf("%d\n", ans);
    return 0;
}