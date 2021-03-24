#include <bits/stdc++.h>
#define maxn 2000005
#define int long long
using namespace std;
int t, l, r, sum[maxn];
signed main(void)
{
    scanf("%lld", &t);
    /*
    sum[0] = 1;
    for(int i = 1; i <= maxn - 5; i++)
        sum[i] = sum[i - 1] + (i + 1);
    */
    while(t--)
    {
        scanf("%lld %lld", &l, &r);
        int de = r - 2 * l + 1;
        if(l == 0 && r == 0)
            printf("1\n");
        else if(de > 0)
            printf("%lld\n", de * (de + 1) / 2);
        else
            printf("%lld\n", 0);

        /*
        if(l != 0)
            printf("%lld\n", sum[r] - sum[l - 1]);
        else
            printf("%lld\n", sum[r]);
        */
    }
    return 0;
}
