#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, k, n, ans[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        int cnt = 0;
        scanf("%d %d", &n, &k);
        for(int i = n; i > k; i--)
            ans[++cnt] = i;
        for(int i = k - 1; i >= (k + 2 - 1) / 2; i--)
            ans[++cnt] = i;
        printf("%d\n", cnt);
        for(int i = 1; i <= cnt; i++)
            printf("%d ", ans[i]);
        putchar('\n');
    }
    return 0;
}
