#include <bits/stdc++.h>
#define maxn 1005
#define int long long
using namespace std;
int n, c1[maxn], c2[maxn];
signed main(void)
{
    while(~scanf("%lld", &n))
    {
        for(int i = 0; i <= n; i++)    
            c1[i] = 1, c2[i] = 0;
        for(int k = 2; k <= n; k++)
        {
            for(int i = 0; i <= n; i++)
                for(int j = 0; j + i <= n; j += k)
                    c2[i + j] += c1[i];
            for(int i = 0; i <= n; i++)
                c1[i] = c2[i], c2[i] = 0;
        }
        printf("%lld\n", c1[n]);
    }
    return 0;
}