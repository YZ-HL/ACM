#include <bits/stdc++.h>
#define maxn 1000005
#define int long long
using namespace std;
int t, n, a[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        int cnt1 = 0, cnt2 = 0, op1 = 0, op2 = 0;
        for(int i = 1; i <= n; i++)    
        {
            scanf("%lld", &a[i]);
            if(a[i] == 1)         cnt1++;
            else if(a[i] == 2)    cnt2 += 0;
            else if(a[i] & 1)     cnt1 += a[i] / 2 + 1;
            else                  cnt2 += a[i] / 2 - 1;
        }
        if(cnt1 > cnt2)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
}