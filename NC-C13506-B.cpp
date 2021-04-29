#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, nd, nowx, nowy, ans[maxn];
int maxx, maxy, minx, miny;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main(void)
{
    scanf("%d", &n); nd = 1;
    for(int i = 1; i <= n; i++)
    {
        int l, d;
        scanf("%d %d", &l, &d);
        if(nd == 1)
        {
            int len = maxx + 1 - nowx;
            maxx = nowx + len;
            nowx = nowx + len;
            ans[i] = len;
        }
        if(nd == 2)
        {
            int len = maxy + 1 - nowy;
            maxy = nowy + len;
            nowy = nowy + len;
            ans[i] = len;
        }
        if(nd == 3)
        {
            int len = nowx - (minx - 1);
            minx = nowx - len;
            nowx = nowx - len;
            ans[i] = len;
        }
        if(nd == 4)
        {
            int len = nowy - (miny - 1);
            miny = nowy - len;
            nowy = nowy - len;
            ans[i] = len;
        }
        nd = (nd + d) % 4;
        if(!nd)    nd = 4;
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}
