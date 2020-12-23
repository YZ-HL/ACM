#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int t, n, maxa[maxn], sumb[maxn];
struct T{
    int a;
    int b;
} order[maxn];
bool operator < (const T &A, const T &B){
    if(A.a == B.a)
        return A.b < B.b;
    return A.a < B.a;
}
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        int ans = (int)1e16;
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &order[i].a);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &order[i].b);
        sort(order+1, order+n+1);
        for(int i = 1; i <= n; i++)
            maxa[i] = max(order[i].a, maxa[i - 1]);
        for(int i = 1; i <= n; i++)
            sumb[i] = order[i].b + sumb[i - 1];
        for(int i = 0; i <= n; i++)
            ans = min(ans, max(maxa[i], sumb[n] - sumb[i]));
        printf("%lld\n", ans);
    }
    return 0;
}
