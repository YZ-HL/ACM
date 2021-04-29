#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int t, minn = 1e8, maxx = -1;
int n, m, k, flag;
void dfs(int x, int y, int cost){
    //printf("%d %d %d\n", x, y, cost);
    if(flag)        return;
    if(cost > k)    return;
    if(x > n || y > m)    return;
    if(x == n && y == m)
    {
        //printf("debug: %d\n", cost);
        //minn = min(minn, cost);
        //maxx = max(maxx, cost);
        //if(cost == k)    flag = 1;
        return;
    }
    dfs(x, y + 1, cost + x);
    dfs(x + 1, y, cost + y);
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &m, &k);
        //dfs(1, 1, 0);
        //printf("%d %d\n", minn, maxx);
        printf(n - 1 + (m - 1) * n == k ? "YES\n" : "NO\n");
    }
    return 0;
}
