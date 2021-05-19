#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int t, n, l, r, tmp;
int lc[maxn], rc[maxn];
int lcnt, rcnt, cost;
void solve1(){
    for(int i = 1; i <= n; i++)
    {
        int val = min(lc[i], rc[i]);
        if(lc[i] && rc[i])    lc[i] -= val, rc[i] -= val;
        lcnt += lc[i]; rcnt += rc[i];
    }
}
void solve2(){
    int diff = abs(lcnt - rcnt), flag = lcnt > rcnt;
    for(int i = 1; i <= n; i++)
    {
        if(flag && lc[i] >= 2)
        {
            int maxx = (lc[i] / 2) * 2;
            if(diff >= maxx)
                diff -= maxx, lc[i] -= maxx / 2, rc[i] += maxx / 2, cost += maxx / 2;
            else
                lc[i] -= diff / 2, rc[i] += diff / 2, cost += diff / 2, diff = 0;
        }
        else if(!flag && rc[i] >= 2)
        {
            int maxx = (rc[i] / 2) * 2;
            if(diff >= maxx)
                diff -= maxx, rc[i] -= maxx / 2, lc[i] += maxx / 2, cost += maxx / 2;
            else
                rc[i] -= diff / 2, lc[i] += diff / 2, cost += diff / 2, diff = 0;
        }
    }
}
void solve3(){
    int diff = abs(lcnt - rcnt);
    for(int i = 1; i <= n && diff; i++)
    {
        if(lcnt > rcnt && lc[i])
        {
            //printf("debug8: %d %d %d\n", lc[i], rc[i], i);
            int maxx = lc[i] * 2;
            if(diff >= maxx)    {lc[i] -= maxx / 2; rc[i] += maxx / 2; cost += maxx / 2; diff -= maxx;}
            else                {lc[i] -= diff / 2; rc[i] += diff / 2; cost += diff / 2; diff = 0;}
            //printf("debug7: %d %d %d\n", lc[i], rc[i], i);
        }
        else if(rcnt > lcnt && rc[i])
        {
            int maxx = rc[i] * 2;
            if(diff >= maxx)    {rc[i] -= maxx / 2; lc[i] += maxx / 2; cost += maxx / 2; diff -= maxx;}
            else                {rc[i] -= diff / 2; lc[i] += diff / 2; cost += diff / 2; diff = 0;}
            //printf("debug8: %d %d %d\n", lc[i], rc[i], i);
        }
    }
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &l, &r);
        lcnt = rcnt = cost = 0;
        for(int i = 1; i <= n; i++)    lc[i] = rc[i] = 0;
        for(int i = 1; i <= l; i++)
            scanf("%d", &tmp), lc[tmp]++;
        for(int i = 1; i <= r; i++)
            scanf("%d", &tmp), rc[tmp]++;
        solve1();
        //printf("debug1: %d %d %d\n", lcnt, rcnt, cost);
        if(lcnt != rcnt)    solve2();
        //printf("debug2: %d %d %d\n", lcnt, rcnt, cost);
        lcnt = rcnt = 0;
        solve1();
        //printf("debug3: %d %d %d\n", lcnt, rcnt, cost);
        if(lcnt != rcnt)    solve3();
        //printf("debug4: %d %d %d\n", lcnt, rcnt, cost);
        lcnt = rcnt = 0;
        solve1();
        //printf("debug5: %d %d %d\n", lcnt, rcnt, cost);
        printf("%d\n", cost + lcnt);        
    }
    return 0;
}
