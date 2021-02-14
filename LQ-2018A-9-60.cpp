#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int n, r, maxx, a[maxn];
vector<int> bl[maxn];
signed main(void)
{
    scanf("%lld %lld", &n, &r);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        bl[a[i] % r].push_back(a[i]);
    }
    for(int i = 0; i <= r - 1; i++)    sort(bl[i].begin(), bl[i].end());
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int need = (r - (((a[i] % r) + (a[j] % r)) % r)) % r;
            int flag1 = a[i], flag2 = a[j];
            for(int k = bl[need].size() - 1; k >= 0; k--)
            {
                if(bl[need][k] == flag1)        flag1 = -1;
                else if(bl[need][k] == flag2)   flag2 = -1;
                else
                {
                    maxx = max(maxx, bl[need][k] + a[i] + a[j]);
                    break;
                }
            }
        }
    }
    printf("%lld\n", maxx);
    return 0;
}