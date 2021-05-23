#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int n, m, s[maxn], now[maxn];
int ans = (1 << 30);
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
    while(m != n)
    {
        for(int i = 1; i <= n; i++)
            now[i] = s[(i + m) % n == 0 ? n : (i + m) % n];
        show();
        int maxx = -(1 << 30), minn = (1 << 30), sum = 0;
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
