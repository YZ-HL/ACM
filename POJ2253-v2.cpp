#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 205
#define eps 1e-10
using namespace std;
int n, xx[maxn], yy[maxn];
int uset[maxn];
double calc(int x1, int y1, int x2, int y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int find(int x){
    return uset[x] == x ? x : uset[x] = find(uset[x]);
}
void Union(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy)
        return;
    uset[fx] = fy;
} 
bool check(double lim){
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
        {
            if(i == j)
                continue;
            if(lim - calc(xx[i], yy[i], xx[j], yy[j]) >= eps)
                Union(i, j);
        }
    return find(1) == find(2);
}
int main(void)
{
    freopen("output.txt", "w", stdout);

    int cnt = 0;
    while (scanf("%d", &n), n)
    { 
        if(cnt)
            putchar('\n');

        for (int i = 1; i <= n; i++)
            scanf("%d %d", &xx[i], &yy[i]);
        double lf = 1, rt = 1500;
        while (rt - lf >= eps)
        {
            for (int i = 1; i <= n; i++)
                uset[i] = i;
            
            double mid = (lf + rt) / 2;
            check(mid) ? rt = mid : lf = mid;
        }
        printf("Scenario #%d\nFrog Distance = %.3lf\n", ++cnt, rt);
    }
    //system("pause");
    return 0;
}