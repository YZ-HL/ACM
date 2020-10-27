#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1000005
#define int long long
using namespace std;
int n, a[maxn], p[maxn]; 
bool isp[maxn];
namespace solve1{
    int onep[maxn], cnt1 = 0, cnt2 = 0, cnt3 = 0;
    void solve(int x, int y){
        memset(onep, 0, sizeof(onep));
        int pos = 1;
        while(x > 1)
        {
            while(x % p[pos] == 0)    
            {
                cnt1++;
                onep[p[pos]]++;
                x /= p[pos];
            }
            pos++;
        }
        pos = 1;
        while(y > 1)
        {
            while(y % p[pos] == 0)    
            {
                if(onep[p[pos]])
                    onep[p[pos]]--, cnt3++;
                cnt2++;
                y /= p[pos];
            }
            pos++;
        }
        printf("%lld\n", cnt1+cnt2-cnt3*2);
    }
}
void mt(int lim){
    memset(isp, true, sizeof(isp));
    isp[0] = isp[1] = false;
    for(int i = 2; i <= lim; i++)
    {
        if(isp[i])    p[++p[0]] = i;
        for(int j = 1; j <= p[0] && i * p[j] <= lim; j++)
        {
            isp[i * p[j]] = false;
            if(i % p[j] == 0)    break;
        }
    }
}
signed main(void)
{
    mt(maxn - 5);
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    if(n == 2)
    {
        solve1::solve(a[1], a[2]);
        system("pause");
        return 0;
    }    
    system("pause");
    return 0;
}
