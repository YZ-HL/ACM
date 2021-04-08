#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int t, n;
int sum(int x){
    int res = 0;
    while(x)
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}
int get_min(int x){
    for(int i = x; i; i++)
        if(__gcd(i, sum(i)) > 1)
            return i;
}
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", get_min(n));        
    }
    return 0;
}
