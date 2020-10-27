#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
//#define int long long
using namespace std;
int n, m;
long long dp[15][maxn]; int ch[2050][2050];
bool check(int j, int k){
    if(~ch[j][k] || ~ch[k][j])    return ch[j][k];
    int cnt = 0, x = j | k;
    for(register int i = 0; i <= m - 1; i++)
    {
        if(x & (1 << i))
        {
            if(cnt & 1)    return ch[j][k] = ch[k][j] = 0;
        }
        else    cnt++;
        if(i == m - 1 && cnt & 1)    return ch[j][k] = ch[k][j] = 0;
    }
    return ch[j][k] = ch[k][j] = 1;
}
signed main(void)
{
    while(scanf("%d %d", &n, &m), n)
    {
        memset(ch, -1, sizeof(ch));
        dp[0][0] = 1;
        for(register int i = 1; i <= n; i++)
        {
            for(register int j = 0; j <= (1 << m) - 1; j++)
            {
                dp[i][j] = 0;
                for(register int k = 0; k <= (1 << m) - 1; k++)
                {
                    if(!(j & k) && check(j, k))
                    {
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }
        printf("%lld\n", dp[n][0]);
    }
    system("pause");
    return 0;
}
