#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int used[maxn], cnt = 1;
long long pri[maxn];
long long ans = 1e12+5;
void prime(long long x)
{
    for (long long i = 2; i * i <= x; i++)
    {
        if (!(x % i))
        {
            pri[cnt] = i;
            x /= i;
            while (!(x % i))
                x /= i, pri[cnt] *= i;
            cnt++;
        }
    }
    if (x > 1)
        pri[cnt] = x, cnt++;
}
void dfs(int x, long long now){
    if(x == cnt)
    {
        if(now > ans)
            return;
        long long oth = 1;
        for (int i = 1; i <= cnt - 1; i++)
            if(!used[i])
                oth *= pri[i];
        long long maxx = max(now, oth);
        if(maxx < ans)
            ans = maxx;
        return;
    }
    used[x] = 1;
    dfs(x + 1, now * pri[x]);
    used[x] = 0;
    dfs(x + 1, now);
}
int main(void)
{
    long long n;
    scanf("%lld", &n);
    prime(n);
    dfs(1, 1);
    long long res = n / ans;
    printf("%lld %lld\n", min(res, ans), max(res, ans));
    system("pause");
    return 0;
}