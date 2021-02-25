#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, x;
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &x);
        if(x * x <= n)
            printf("%lld\n", x);
        else
        {
            int le = sqrt(n);
            int rt = n / le - n / x;
            //试出(x-1)*(x+1)的位置
            le++; while(le * le > n) le--;
            if(le * (le + 2) == n)    rt--;
            printf("%lld\n", le + rt);
        }
    }
    return 0;
}