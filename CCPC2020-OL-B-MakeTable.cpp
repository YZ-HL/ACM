#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 5000005
#define int long long
#define BLOCK_LENGTH (int)5e6
using namespace std;
int ans[maxn];
bool isp_s[maxn], isp_l[maxn];
int Prime_Cnt(int s, int lim){
    memset(isp_l, true, sizeof(isp_l));
    for(int i = 2; i * i <= lim; i++)
    {
        if(isp_s[i])
        {
            int nows = max(2*i, i * (s % i ? s / i + 1 : s / i));
            for(int j = nows; j <= lim; j += i)
                isp_l[j - s] = false;
        }
    }
    int sum = 0;
    for(int i = s; i <= lim; i++)
        if(isp_l[i - s])    sum += i;
    return sum;
}
void inits(int lim){
    memset(isp_s, true, sizeof(isp_s));
    for(int i = 2; i <= lim; i++)
    {
        if(isp_s[i])
        {
            for(int j = i*2; j <= lim; j += i)
            {
                isp_s[j] = false;
            }
        }
    }
}
signed main(void)
{
    int s = 1;
    inits(100000);
    while(1)
    {
        if(s > 1e10) break;
        ans[0]++;
        ans[ans[0]] = Prime_Cnt(s, s+BLOCK_LENGTH-1);
        s += BLOCK_LENGTH;
        //printf("%lld\n", ans[ans[0]]);
    }
    ans[1]--;
    for(int i = 1; i <= ans[0]; i++)
        printf("%lld,", ans[i]);
    system("pause");
    return 0;
}
