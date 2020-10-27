#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, p[maxn], ans[maxn];
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    int lim = 1, pre = 1;
    for(int i = 1; i <= n + 1; i++)
    {
        if(lim < i)
        {
            ans[++ans[0]] = pre;
            lim = i;
            pre = i;
        }
        if(i + p[i] > lim)
        {
            lim = i + p[i];
            pre = i;
        }
    }
    printf("%d\n", ans[0]);
    for(int i = 1; i <= ans[0]; i++)
        printf("%d ", ans[i]);
    return 0;
}