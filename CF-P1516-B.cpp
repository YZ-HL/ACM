#include <bits/stdc++.h>
#define maxn 2005
using namespace std;
int t, n, a[maxn], sum[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] ^ a[i];
        }
        int flag = (sum[n] == 0);
        for(int i = 1; i <= n && !flag; i++)
        {
            for(int j = i + 1; j < n && !flag; j++)
            {
                flag |= (sum[i] == (sum[j] ^ sum[i])) &&
                        (sum[i] == (sum[n] ^ sum[j]));
            }
        }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}
