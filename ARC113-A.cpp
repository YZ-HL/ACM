#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int k, sum[maxn], res[maxn];
int cnt, pri[maxn];
bool isp[maxn];
void euler(int lim){
    memset(isp, true, sizeof(isp));
    isp[1] = false;
    for(int i = 2; i <= lim; i++)
    {
        if(isp[i])    pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= lim; j++)
        {
            isp[i * pri[j]] = false;
            if(i % pri[j] == 0)    break;
        }
    }
}
signed main(void)
{
    scanf("%lld", &k);
    euler(k);
    for(int i = 1; i <= k; i++)
    {
        if(i == 1)    
            res[i] = 1;
        else if(isp[i])
            res[i] = 2;
        else
        {
            for(int j = 1; j * j <= i; j++)
            {
                if(j * j == i)  
                    res[i]++;
                else if(i % j == 0)
                    res[i] += 2;
            }
        }        
    }
    /*
    for(int i = 1; i <= k; i++)
        printf("%lld ", res[i]);
    putchar('\n');
    */
    for(int i = 1; i <= k; i++)
        sum[i] = sum[i - 1] + res[i];
    int ans = 0;
    for(int i = 1; i <= k; i++)
        ans += sum[k / i];
    printf("%lld\n", ans);
    return 0;
}
