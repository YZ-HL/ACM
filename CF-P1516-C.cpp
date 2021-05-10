#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int n, sum, g;
int a[maxn], b[maxn], can[maxn];
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
        g == 0 ? g = a[i] : g = __gcd(g, a[i]);
    }
    if(sum & 1)
    {
        printf("0\n");
        return 0;
    }
    can[0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = sum; j >= a[i]; j--)
            can[j] |= can[j - a[i]];
    if(!can[sum / 2])
    {
        printf("0\n");
        return 0;
    }
    int flag = -1;
    for(int i = 1; i <= n; i++)
    {
        b[i] = a[i] / g;
        if(b[i] & 1)
        {
            flag = i;
            break;
        }
    }
    printf("%d\n%d\n", 1, flag);
    return 0;
}
