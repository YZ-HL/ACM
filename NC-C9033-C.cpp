#include <bits/stdc++.h>
#define maxn 1000005
#define int long long
#define mod 20000311
using namespace std;
int n, a[maxn], sum[maxn], num[maxn], leq[maxn], mul[maxn];
bool exist[maxn], seqex[maxn];
int quickpow(int a, int b){
    if(b == 0)  return 1;
    int tmp = quickpow(a, b / 2);
    tmp = (tmp * tmp) % mod;
    if(b & 1)
        tmp = (tmp * a) % mod;
    return tmp;
}
signed main(void)
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        if(a[i] <= n + 1)
        {
            exist[a[i]] = 1;
            num[a[i]]++;
        }
    }
    seqex[0] = true;
    for(int i = 1; i <= n + 1; i++)
    {
        seqex[i] = (exist[i] && seqex[i - 1]);
        sum[i] = sum[i - 1] + num[i];
    }  
    for(int i = n; i >= 1; i--)    leq[i + 1] = n - sum[i];
    
    mul[0] = 1;
    for(int i = 1; i <= n; i++)    mul[i] = (mul[i - 1] * (quickpow(2, num[i]) - 1)) % mod;

    /*
    for(int i = 1; i <= n + 1; i++)
        printf("%d %d %d %d %d\n", num[i], sum[i], leq[i], seqex[i], mul[i]);
    */
    
    int ans = 0;
    for(int i = 1; i <= n + 1; i++)
    {
        ans = (ans + (((mul[i - 1] * quickpow(2, leq[i + 1])) % mod) * i) % mod) % mod;
    }
    printf("%lld\n", ans);
    return 0;   
}