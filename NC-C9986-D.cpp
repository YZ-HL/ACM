#include <bits/stdc++.h>
#define int long long
const int maxn = 1000005;
using namespace std;
int n, cnt, sum, num[maxn];
signed main(void)
{
    while(~scanf("%lld %lld", &n, &cnt))
    {
        sum = 0;
        for(int i = 1; i <= n; i++)
            scanf("%lld", &num[i]), sum += num[i];
        sum -= cnt;
        printf("%lld\n", n == 2 ? sum : sum % 11);;
    }
    return 0;
}