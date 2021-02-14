#include <bits/stdc++.h>
#define maxn 500005
#define int long long
using namespace std;
int n, S, a[maxn];
signed main(void)
{
    scanf("%lld %lld", &n, &S);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    double r = S, sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] < r / (n - i + 1))
        {
            sum += (a[i] - 1.0 * S / n) * (a[i] - 1.0 * S / n);
            r -= a[i];
        }
        else
        {
            sum += (n - i + 1) * (r / (n - i + 1) - 1.0 * S / n) * (r / (n - i + 1) - 1.0 * S / n);
            break;
        } 
    }
    printf("%.4lf", sqrt(sum / n));
    return 0;
}