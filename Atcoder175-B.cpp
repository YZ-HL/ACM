#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n, ans, a[maxn];
int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
                if(a[i]+a[j] > a[k] && a[i] != a[j] && a[j] != a[k] && a[i] != a[k])
                    ans++;
    printf("%d\n", ans);
    system("pause");
    return 0;
}
