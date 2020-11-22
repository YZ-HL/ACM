#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, m;
int euler(int n){
    if(n == 1)  return 1;
    int ans = n;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
        {
            ans = ans / i * (i - 1);
            while(n % i == 0)   n /= i;
        }
    if(n > 1)   ans = ans / n * (n - 1);
    return ans;
}
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        int res = 0;
        scanf("%lld %lld", &n, &m);
        for(int i = 1; i * i <= n; i++)
        {
            if(n % i)   continue;
            if(i * i != n && i >= m)
                res += euler(n / i);
            if(n / i >= m)
                res += euler(i);
            //printf("%lld:%lld\n", i, res);
        }
        printf("%lld\n", res);
    }
    return 0;
}