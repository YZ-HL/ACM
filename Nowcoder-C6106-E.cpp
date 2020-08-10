//https://ac.nowcoder.com/acm/contest/6106/E
#include <bits/stdc++.h>
#define maxn 10000005
using namespace std;
int newc, newt[maxn], newv[maxn];
int n, t, q, s, sec, dp[maxn];
int e1, s1, e2, s2;
int main(void)
{

    scanf("%d:%d %d:%d %d", &e1, &s1, &e2, &s2, &n);
    sec = (e2 - e1) * 60 + s2 - s1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &t, &q, &s);
        if (!s)
            for (int j = t; j <= sec; j++)
                dp[j] = max(dp[j], dp[j - t] + q);
        else
        {
            for (int j = 1; j <= s; j *= 2)
                newt[++newc] = t * j, newv[newc] = q * j, s -= j;
            if (s)
                newt[++newc] = t * s, newv[newc] = q * s;
        }
    }
    for (int i = 1; i <= newc; i++)
        for (int j = sec; j >= newt[i]; j--)
            dp[j] = max(dp[j], dp[j - newt[i]] + newv[i]);
    printf("%d\n", dp[sec]);
    system("pause");
    return 0;
}