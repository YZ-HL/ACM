#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 205
#define eps 1e-5
using namespace std;
int n, xx[maxn], yy[maxn];
int k, flag, used[maxn], head[maxn * maxn];
struct Edge{
    int to;
    int nxt;
    double weight;
} E[maxn*maxn];
void Build(int u, int v, double w){
    E[k].to = v;
    E[k].nxt = head[u];
    E[k].weight = w;
    head[u] = k++;
}
double calc(int x1, int y1, int x2, int y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void dfs(int x, double lim){
    if(x == 2)
    {
        flag = 1;
        return;
    }
    used[x] = 1;
    for (int i = head[x]; ~i; i = E[i].nxt)
        if(!used[E[i].to])
            dfs(E[i].to, lim);
    used[x] = 0;
}
bool check(double lim){
    flag = 0;
    dfs(1, lim);
    return flag;
}
int main(void)
{
    int cnt = 0;
    while (scanf("%d", &n), n)
    {
        k = 0;
        memset(head, -1, sizeof(head));
        
        for (int i = 1; i <= n; i++)
            scanf("%d %d", &xx[i], &yy[i]);

        double lf = 1, rt = 1500, ans = -1;
        while(rt - lf >= eps)
        {
            double mid = (lf + rt) / 2;

            k = 0;
            memset(head, -1, sizeof(head));
            
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if(i == j)
                        continue;
                    double dis = calc(xx[i], yy[i], xx[j], yy[j]);
                    
                    if(mid - dis >= eps)
                        Build(i, j, dis);
                }
            }
            //printf("debug: %lf %lf\n", lf, rt);
            check(mid) ? rt = mid : lf = mid;
        }
        printf("Scenario #%d\nFrog Distance = %.3lf\n", ++cnt, lf);
    }
    system("pause");
    return 0;
}
