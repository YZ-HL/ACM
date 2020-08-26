#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 3005
#define int long long
using namespace std;
int n, a[maxn], lr[maxn][maxn], rt[maxn][maxn];

signed main(void)
{
    int t;
    scanf("%lld", &t);
    while(t--)
    {
        memset(lr, 0, sizeof(lr));
        memset(rt, 0, sizeof(rt));

        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i - 1; j++)
                lr[i][a[j]]++;
        for (int i = 1; i <= n; i++)
            for (int j = i+1; j <= n; j++)
                rt[i][a[j]]++;
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                ans += lr[i][a[j]] * rt[j][a[i]];
        printf("%lld\n", ans);
    }
    system("pause");
    return 0;
}
