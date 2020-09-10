#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
#define int long long
using namespace std;
int t, n, a[maxn], sum[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        int n;
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        sum[0] = 0;
        for(int i = 1; i <= n; i++)
            sum[i] = sum[i-1] + a[i];
        int minn = (int)1e15;
        for(int i = 1; i <= n; i++)
            minn = min(minn, sum[i]);
        printf("%lld\n", abs(minn));
    }
    system("pause");
    return 0;
}
