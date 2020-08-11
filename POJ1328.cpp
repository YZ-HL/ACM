#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define maxn 1005
#define eps 1e-8
using namespace std;
int n, d, cnt;
double xx[maxn], yy[maxn];
struct coordinate{
    double lf;
    double rt;
}p[maxn];
bool cmp(const coordinate &A, const coordinate &B){
    return A.rt < B.rt;
}
void solve(){
    int flag = 1;
    for (int i = 1; i <= n; i++)
    {
        if(d < yy[i] || d < 0)
        {
            flag = 0;
            break;
        }
        double nxl = xx[i] - sqrt(d * d - yy[i] * yy[i]);
        double nxr = xx[i] + sqrt(d * d - yy[i] * yy[i]);
        p[i].lf = nxl;
        p[i].rt = nxr;
    }
    if(flag)
    {
        sort(p + 1, p + n + 1, cmp);
        int pos = 1, ans = 0;
        while(pos <= n)
        {
            double mrt = p[pos].rt;
            while(p[pos].lf <= mrt && pos <= n)
                pos++;
            ans++;
        }
        printf("Case %d: %d", ++cnt, ans);
    }
    else
        printf("Case %d: %d", ++cnt, -1);
}
int main(void)
{
    while(1)
    {
        scanf("%d %d", &n, &d);
        if(!n)
            break;
        for (int i = 1; i <= n; i++)
            scanf("%lf %lf", &xx[i], &yy[i]);
        if(cnt) putchar('\n');
        solve();
    }
    //system("pause");
    return 0;
}