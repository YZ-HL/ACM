#include <bits/stdc++.h>
#define maxn 105
#define maxm 10005
using namespace std;
int n, g, a[maxn], dp[maxm];
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    g = a[1];
    for(int i = 2; i <= n; i++)
        g = __gcd(g, a[i]);
    if(g != 1)
    {
        printf("INF\n");
        return 0;
    }
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = a[i]; j <= maxm - 5; j++)
            dp[j] |= dp[j - a[i]];
    int cnt = 0;
    for(int i = 1; i <= maxm - 5; i++)
        if(!dp[i])   cnt++;
    printf("%d\n", cnt);
    return 0;
}