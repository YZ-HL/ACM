#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, a[maxn], ans[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= 2 * n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + 2 * n + 1);
        for(int i = 1, j = 1; i <= 2 * n; i += 2, j++)
            ans[i] = a[j];
        for(int i = 2 * n, j = n + 1; i >= 1; i -= 2, j++)
            ans[i] = a[j];
        for(int i = 1; i <= 2 * n; i++)
            printf(i == 2 * n ? "%d\n" : "%d ", ans[i]);
    }
    return 0;
}
