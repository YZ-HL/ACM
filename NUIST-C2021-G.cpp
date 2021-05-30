#include <bits/stdc++.h>
#define maxn 500005
using namespace std;
int n, m, q, uu[maxn], vv[maxn], cant[maxn];
int q1[maxn], q2[maxn], ans[maxn];
int uset[maxn];
int find(int x){
    return x == uset[x] ? x : uset[x] = find(uset[x]);
}
bool unioon(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy)    return false;
    uset[fx] = fy;
    return true;
}
int rebuild(){
    for(int i = 1; i <= n; i++)    uset[i] = i;
    for(int i = 1; i <= m; i++)
        if(cant[i] == 0)    unioon(uu[i], vv[i]);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(find(i) == i)    cnt++;
    return cnt;
}
int main(void)
{
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; i++)    uset[i] = i;
    for(int i = 1; i <= m; i++)
        scanf("%d %d", &uu[i], &vv[i]);
    for(int i = 1; i <= q; i++)
    {
        scanf("%d %d", &q1[i], &q2[i]);
        if(q1[i] == 0)    cant[q2[i]] = 1;
        if(q1[i] == 1)    cant[q2[i]] = 0;
    }
    for(int i = 1; i <= m; i++)
        if(cant[i] == 0)    unioon(uu[i], vv[i]);
    int number = 0;
    for(int i = 1; i <= n; i++)
        if(find(i) == i)    number++;
    for(int i = q; i >= 1; i--)
    {
        ans[i] = number;
        if(q1[i] == 0)
        {
            if(unioon(uu[q2[i]], vv[q2[i]]))
                number--;
            cant[q2[i]] = 0;
        }
        else if(q1[i] == 1)
        {
            cant[q2[i]] = 1;
            number = rebuild();
        }
    }
    for(int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
    return 0;
}