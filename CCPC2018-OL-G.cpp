#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 100005
#define int long long
using namespace std;
int n, m, s, k;
int cnt_l, len_l;
int aa[maxn], bb[maxn], sum[maxn];
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
deque<pair<int, int>> q1;
int solve(int m){
    q1.clear();
    int maxx = -1;
    for (int i = 1; i <= 3 * len_l; i++)
    {
        while (!q1.empty() && q1.front().second + m <= i)
            q1.pop_front();
        while (!q1.empty() && q1.back().second + m <= i)
            q1.pop_back();
        
        while(!q1.empty() && sum[i-1] < q1.back().first)
            q1.pop_back();
        q1.push_back(make_pair(sum[i-1], i));
        maxx = max(maxx, sum[i] - q1.front().first);
    }
    return maxx;
}
signed main(void)
{
    int T, number = 0;
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld %lld %lld %lld", &n, &s, &m, &k);
        for (int i = 0; i <= n - 1; i++)
            scanf("%lld", &aa[i]);
        cnt_l = gcd(n, k);
        len_l = n / cnt_l;
        int maxx = 0;
        for (int i = 1; i <= cnt_l; i++)
        {
            sum[0] = 0;
            for (int j = 1, p = i - 1; j <= len_l; j++, p += k)
            {
                if(p >= n)   p %= n;
                bb[j] = aa[p];
                sum[j] = sum[j - 1] + bb[j];
            }
            for (int j = len_l + 1; j <= 3 * len_l; j++)
            {
                bb[j] = bb[j - len_l];
                sum[j] = sum[j - 1] + bb[j];
            }
            int ans = 0;
            if (sum[len_l] <= 0)
                ans = solve(min(m, len_l));
            else
            {
                ans += max(1LL*0, (m / len_l) + (m % len_l ? -1 : -2)) * sum[len_l];
                int nowm = m - max(1LL*0, (m / len_l) + (m % len_l ? -1 : -2)) * len_l;
                ans += solve(nowm);
            }
            maxx = max(ans, maxx);
        }
        printf("Case #%lld: %lld\n", ++number, max(1LL*0, s-maxx));
    }
    system("pause");
    return 0;
}