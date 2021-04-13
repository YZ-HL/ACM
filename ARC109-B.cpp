#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
long long n;
signed main(void)
{
    scanf("%lld", &n);
    printf("%lld\n", n - (long long)((long double)sqrt((long double)2 * (n + 1) + 0.25) - 0.5) + 1);
    return 0;
}
