#include <bits/stdc++.h>
#define maxn 500005
#define int long long
using namespace std;
int n, m, s[maxn], now[maxn];
const int INF = (1LL << 60);
int ans = INF;
void show(){
    printf("show debug:\n");
    for(int i = 1; i <= n; i++)
        printf(i == n ? "%d\n" : "%d ", now[i]);
}
signed main(void)
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &s[i]);
    sort(s + 1, s + n + 1);
    while(m <= n)
    {
        for(int i = n; i >= n - m + 1; i--)
            now[i] = s[n - i + 1];
        for(int i = 1; i <= n - m; i++)
            now[i] = s[i + m];
        //show();
        int maxx = -INF, minn = INF, sum = 0;
        for(int i = 1; i <= n; i++)
        {
            maxx = max(maxx, now[i]);
            minn = min(minn, now[i]);
            sum += (maxx - minn);
        }
        ans = min(ans, sum);
        m++;
    }
    printf("%lld\n", ans);
    return 0;
}
