#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
using namespace std;
int n, a[maxn], dp[maxn], las[maxn];
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        dp[i] = dp[i - 1] + (a[i] == a[i - 1] ? 1 : 0);
        if(las[a[i]])
            dp[i] = max(dp[i], dp[las[a[i]]] + 1);
        las[a[i]] = i;
    }
    printf("%d\n", dp[n]);
    return 0;
}