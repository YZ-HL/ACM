#include <bits/stdc++.h>
#define maxn 1000005
#define int long long
using namespace std;
int n, m, p;
double score[maxn];
signed main(void)
{
    scanf("%lld %lld %lld", &n, &m, &p);
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        score[i] = 0.85 * a + 0.15 * b;
    }
    sort(score+1, score+n+1);
    double res = score[n - m + 1];
    double ans = (res - p * 0.15) / 0.85;
    printf("%lld\n", (int)ceil(max(0.0, ans)));
    return 0;   
}