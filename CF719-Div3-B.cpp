#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int t, n;
int res[] = {1, 11, 111, 1111, 11111, 111111,
             1111111, 11111111, 111111111, 1111111111};
int pows[] = {1, 10, 100, 1000, 10000, 100000, 1000000,
             10000000, 100000000, 1000000000};
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        int b = -1, r = n;
        while(r)    b++, r /= 10;
        //printf("%d\n", b);
        if(n >= res[b])
            printf("%lld\n", 9 * b + n / res[b]);
        else
            printf("%lld\n", 9 * b + (n - pows[b]) / res[b - 1]);
    }
    return 0;
}
