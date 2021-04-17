#include <bits/stdc++.h>
#define maxn 2000005
using namespace std;
int t, n, m, uset[maxn];
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
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        int cnt = 0;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n + n; i++)    uset[i] = i;
        for(int i = 1; i <= m; i++)
        {
            int tx, ty;
            scanf("%d %d", &tx, &ty);
            if(tx == ty)    
            {
                cnt--;
                continue;
            }
            else
            {
                int nd1 = tx + n, nd2 = ty + n;
                bool flag = (unioon(nd1, i) && unioon(nd2, i));
                if(flag == false)    cnt++;
            }
        }
        printf("%d\n", cnt + m);
    }
    return 0;
}
