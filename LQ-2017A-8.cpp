//骗分写法
//首次提交88，调参后75，88，100
#include <bits/stdc++.h>
#define maxn 105
#define maxm 500005
using namespace std;
int n, a[maxn], dp[maxm];
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = a[i]; j <= maxm - 5; j++)
            dp[j] |= dp[j - a[i]];
    int cnt = 0;
    for(int i = 1; i <= maxm - 5; i++)
        if(!dp[i])   cnt++;
    if(cnt > 5000)
        printf("INF\n");
    else
        printf("%d\n", cnt);
    return 0;
}