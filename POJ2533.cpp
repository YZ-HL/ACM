#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n, a[maxn], f[maxn];
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    f[++f[0]] = a[1];
    for(int i = 2; i <= n; i++)
    {
        if(a[i] > f[f[0]])
            f[++f[0]] = a[i];
        else
            f[(lower_bound(f+1, f+f[0]+1, a[i]) - f)] = a[i];
    }
    printf("%d\n", f[0]);
    system("pause");
    return 0;
}
