#include <bits/stdc++.h>
#define maxn 1000005
#define int long long
using namespace std;
int a[maxn];
signed main(void)
{
    //freopen("data.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    a[1] = 2; a[2] = 3;
    for(int i = 3; i <= 40; i++)
        a[i] = a[i - 1] + a[i - 2];
    for(int i = 41; i <= n; i++)
        a[i] = 1;
    //printf("%d\n", n);
    for(int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}