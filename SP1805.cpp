#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int n, h[maxn], l[maxn], r[maxn];
int main(void)
{
    while(scanf("%lld", &n) && n)
    {
        int ans = 0;
        for(int i = 1; i <= n; i++)
            scanf("%lld", &h[i]), l[i] = r[i] = i;
        for(int i = 1; i <= n; i++)
            while(l[i] > 1 && h[i] <= h[l[i]-1])    l[i] = l[l[i]-1];
        for(int i = n; i >= 1; i--)
            while(r[i] < n && h[i] <= h[r[i]+1])    r[i] = r[r[i]+1];
        for(int i = 1; i <= n; i++)
            ans = max(ans, h[i] * (r[i] - l[i] + 1));
        printf("%lld\n", ans);
    }
}