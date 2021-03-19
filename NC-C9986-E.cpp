#include <bits/stdc++.h>
const int maxn = 1e4 + 5;
using namespace std;
int n, m, b[maxn][maxn], cnt[maxn];
int dp1[maxn][2], dp2[maxn][2];
int calc(int x){
    return x + cnt[x];
}
int cnt_it(int x){
    int now = 0;
    while(x)
    {
        int tmp = x & (-x);
        x -= tmp;
        now++;
    }
    return now;
}
int main(void)
{
    for(int i = 0; i <= 1024; i++)    cnt[i] = cnt_it(i);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &b[i][j]);
    int ans1 = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(dp1, 0, sizeof(dp1));
        for(int j = 2; j <= m; j++)
        {
            dp1[j][0] = max(dp1[j - 1][0], dp1[j - 1][1] + calc(b[i][j - 1] ^ b[i][j]));
            dp1[j][1] = max(dp1[j - 1][0], dp1[j - 1][1]);
        }
        ans1 += max(dp1[m][0], dp1[m][1]);
    }
    int ans2 = 0;
    for(int i = 1; i <= m; i++)
    {
        memset(dp2, 0, sizeof(dp2));
        for(int j = 2; j <= n; j++)
        {
            dp2[j][0] = max(dp2[j - 1][0], dp2[j - 1][1] + calc(b[j - 1][i] ^ b[j][i]));
            dp2[j][1] = max(dp2[j - 1][0], dp2[j - 1][1]);
        }
        ans2 += max(dp2[m][0], dp2[m][1]);
    }
    printf("%d\n", ans1 + ans2);
}