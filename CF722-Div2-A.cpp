#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, a[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        int minn = a[1], cnt = 0;
        for(int i = 1; a[i] == minn && i <= n; i++)    cnt++;
        printf("%d\n", n - cnt);
    }
    return 0;
}
