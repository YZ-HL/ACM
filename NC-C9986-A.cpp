#include <bits/stdc++.h>
const int maxn = 105;
using namespace std;
int n, t;
signed main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", n == 0 ? 1 : 0);
    }
    return 0;
}