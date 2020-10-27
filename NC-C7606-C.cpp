#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1000005
#define int long long
#define mod 1000000007
using namespace std;
int n, m, x, y, a[maxn];
namespace solve1{
    int qpow(int x, int p){
        if(p == 0) return 1;
        int tmp = qpow(x, p / 2);
        tmp = (tmp * tmp) % mod;
        if(p & 1)    tmp = (tmp * x) % mod;
        return tmp % mod;
    }
    void solve(){
        sort(a+1, a+n+1);
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 1; i <= y; i++)    
            sum1 = (sum1 % mod + a[i] % mod) % mod;
        for(int i = y+1; i <= n; i++)
            sum2 = (sum2 % mod + a[i] % mod) % mod;
        
        sum1 = (sum1 * qpow(2, m)) % mod;
        sum2 = (sum2 * qpow(3, m)) % mod;
        
        printf("%lld\n", (sum1 + sum2) % mod);
    }
}
signed main(void)
{
    scanf("%lld %lld %lld %lld", &n, &m, &x, &y);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    if(x + y == n)
    {
        solve1::solve();
        system("pause");
        return 0;
    }
    system("pause");
    return 0;
}
