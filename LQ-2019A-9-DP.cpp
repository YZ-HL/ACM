#include <bits/stdc++.h>
#define maxn 105
using namespace std;
int n, m, k, t[maxn], dp[(1 << 22)];
void print(int x){
    vector<int> v1;
    while(x)    v1.push_back(x % 2), x /= 2;
    for(int i = v1.size() - 1; i >= 0; i--)
        printf("%d", v1[i]);
    putchar('\n');
}
int main(void)
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
    {
        int tmp, sta = 0; 
        for(int j = 1; j <= k; j++)
        {
            scanf("%d", &tmp);
            sta |= (1 << (tmp - 1));
        }
        t[i] = sta;
        //print(t[i]);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i <= (1 << m) - 1; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i | t[j]] = min(dp[i | t[j]], dp[i] + 1);
        }
    }
    printf("%d\n", dp[(1 << m) - 1] > 100 ? -1 : dp[(1 << m) - 1]);
    return 0;
}
//O(n*(2^20))