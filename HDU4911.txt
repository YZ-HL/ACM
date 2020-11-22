#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int n, k, ans, a[maxn], tmp[maxn];
void merge_sort(int lf, int rt)
{
    if (lf == rt || lf > rt)
        return;
    int mid = (lf + rt) >> 1;
    merge_sort(lf, mid);
    merge_sort(mid + 1, rt);
    int i = lf, j = mid, n = mid + 1, m = rt, k = 0;
    while (i <= j && n <= m)
    {
        if (a[i] <= a[n])
            tmp[++k] = a[i], i++;
        else
        {
            tmp[++k] = a[n], n++;
            ans += mid - i + 1;
        }
    }
    while (i <= j)
        tmp[++k] = a[i], i++;
    while (n <= m)
        tmp[++k] = a[n], n++;
    for (int l = lf; l <= rt; l++)
        a[l] = tmp[l - lf + 1];
}
signed main(void)
{
    while(~scanf("%lld %lld", &n, &k))
    {
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
        }
        merge_sort(1, n);
        printf("%lld\n", ans > k ? ans - k : 0);
    }
    return 0;
}