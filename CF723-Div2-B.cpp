#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
const int d[] = {11, 111, 1111, 11111, 111111, 1111111,
                   11111111, 111111111, 1111111111, 11111111111};
int t, n;
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        int cnt = 0, pos = 9, r = n;
        while(d[pos] > r)    pos--;
        while(r > 0 && pos >= 0)
        {
            while(r >= d[pos])    r -= d[pos] * (r / d[pos]);
            pos--;
        }
        printf(r == 0 ? "YES\n" : "NO\n");
    }
    return 0;
}
