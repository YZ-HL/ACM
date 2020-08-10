#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, a[maxn];
int main(void)
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        int flag = 1;
        for (int i = 2; i <= n; i++)
            if (a[i] - a[i - 1] > 1)
            {
                flag = 0;
                break;
            }
        printf(flag ? "YES" : "NO");
        putchar('\n');
    }
    system("pause");
    return 0;
}