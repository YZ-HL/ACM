#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int t, n, m, u[maxn], v[maxn];
int check(int sta){
    int cnt = 0;
    for(int i = 1; i <= m; i++)
    {
        int us = (1 << (u[i] - 1)) & sta ? 1 : 0;
        int uv = (1 << (v[i] - 1)) & sta ? 1 : 0;
        if(us ^ uv)
            cnt++;
    }
    return cnt;
}
int main(void)
{
    int cases = 0;
    scanf("%d", &t);
    while(t--)
    {
        int ans = 0;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++)
            scanf("%d %d", &u[i], &v[i]);
        for(int i = 0; i <= (1 << n) - 1; i++)
        {
            ans = max(ans, check(i));
        }
        printf("Case #%d: %d\n", ++cases, ans);
    }
    return 0;
}
