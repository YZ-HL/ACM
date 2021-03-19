#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
long long n, k, sum, f[maxn];
int calc(int b, int num){
    return b * (num * (num + 1) / 2);
}
signed main(void)
{
    scanf("%lld %lld", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        sum += calc(k, i / k);
    }
    printf("%lld\n", sum);
    return 0;
}
//11 12 13 14 15