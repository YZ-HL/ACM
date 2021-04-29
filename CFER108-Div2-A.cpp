#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int t, r, b, d;
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld %lld", &r, &b, &d);
        int diff = abs(r - b), minn = min(r, b);
        if(minn * (d + 1) >= max(r, b))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
