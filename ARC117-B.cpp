#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int n, a[maxn];
const int mod = 1e9 + 7;
signed main(void)
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    int sum = 1;
    for(int i = 1; i <= n; i++)
        sum = (sum * ((a[i] - a[i - 1] + 1) % mod)) % mod;
    printf("%lld\n", sum);
    return 0;
}
