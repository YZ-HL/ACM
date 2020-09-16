#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n, dp1[maxn], dp2[maxn], ans = (1<<30);
double high[maxn];
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lf", &high[i]);
    for(int i = 1; i <= n; i++)
    {
        dp1[i] = 1;
        for(int j = 1; j <= i - 1; j++)
        {
            if(high[i] > high[j])
                dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }
    for(int i = n; i >= 1; i--)
    {
        dp2[i] = 1;
        for(int j = n; j >= i + 1; j--)
        {
            if(high[i] > high[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            ans = min(ans, n-(dp1[i]+dp2[j]));
    printf("%d\n", ans);
    system("pause");
    return 0;
}
