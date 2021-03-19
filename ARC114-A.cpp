#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[55], dp[(1 << 15) + 5];
int pri[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int lowbit(int x){
    return x & (-x);
}
int pos(int x){
    return log2(x) + 1;
}
signed main(void)
{
    //printf("%d %d\n", pos(lowbit((1 << 14))), pri[15]);
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    int ans = -1;
    for(int i = 0; i <= (1 << 15) - 1; i++)
    {
        int sta = i, now = 1, flag = 0;
        //printf("debug: %d %d\n", now, lowbit(sta));

        while(sta)  
            now *= pri[pos(lowbit(sta))], sta -= lowbit(sta);
        for (int j = 1; j <= n; j++)
            if(__gcd(now, a[j]) != 1)   flag++;
        if(flag == n)
        {
            if(ans == -1)   ans = now;
            else            ans = min(ans, now);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
