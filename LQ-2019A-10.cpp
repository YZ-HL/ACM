#include <bits/stdc++.h>
#define maxn 2005
#define mod 1000000007
#define int long long
using namespace std;
int t, n, m, k, ca[maxn][maxn], sum[maxn][maxn];
signed main(void)
{
    scanf("%lld %lld", &t, &k);
    ca[0][0] = 1;
    for(int i = 1; i <= 2000; i++)
    {
        ca[i][0] = 1;
        for(int j = 1; j <= i; j++)
        {
            ca[i][j] = (ca[i - 1][j - 1] + ca[i - 1][j]) % k;
        }
    }
    for(int i = 1; i <= 2000; i++)
    {
        for(int j = 1; j <= 2000; j++)
        {
            sum[i][j] = (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]) % mod;
            if(j <= i && ca[i][j] == 0)
                sum[i][j]++;
        }
    }    
    while(t--)
    {
        scanf("%lld %lld", &n, &m);
        printf("%lld\n", sum[n][m]);
    }
    return 0;
}
