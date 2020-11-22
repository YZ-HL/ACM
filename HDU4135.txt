#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int lowbit(int x){
    return x & (-x);
}
int cnt_one(int x){
    int cnt = 0;
    while(x)    x -= lowbit(x), cnt++;
    return cnt;
}
int bas[maxn];
int calc(int n, int m){
    bas[0] = 0; int f = 0;
    
    for(int i = 2; i * i <= m; i++)
    {
        if(m % i)   continue;
        while(m % i == 0)   m /= i;
        bas[++bas[0]] = i;  
    }
    if(m > 1)   bas[++bas[0]] = m;

    for(int i = 1; i <= (1 << bas[0]) - 1; i++)
    {
        int flag = cnt_one(i) & 1 ? 1 : -1;
        int now = 1, tmp = i;
        while(tmp)  
        {
            now *= bas[(int)log2(lowbit(tmp)) + 1];
            tmp -= lowbit(tmp);
        }
        //printf("%d %d\n", f, n / now);
        f += flag * (n / now);
    }
    return n - f;
}
signed main(void)
{   
    int t, cases = 0;
    scanf("%lld", &t);
    while(t--)
    {
        int a, b, m;
        scanf("%lld %lld %lld", &a, &b, &m);
        printf("Case #%lld: %lld\n", ++cases, calc(b, m) - calc(a-1, m));
    }
    return 0;
}