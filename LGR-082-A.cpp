#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, m, ty, t[maxn], q[maxn];
int main(void)
{
    scanf("%d %d %d", &n, &m, &ty);
    for(int i = 1; i <= n; i++)
        scanf("%d", &t[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &q[i]);
    int bo = 0;
    for(int i = 1; i <= n; i++)
        if(t[i] && q[i])    bo++;
    if(bo >= m)
        printf("%d\n", m + n - bo);
    else
        printf("%d\n", n);
    return 0;
}
