#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int qpow(int a, int b, int p){
    if(b == 0)    return 1;
    int tmp = qpow(a, b / 2, p);
    tmp = (tmp * tmp) % p;
    if(b & 1)    tmp = (tmp * a) % p;
    return tmp;
}
signed main(void)
{
    while(~scanf("%lld", &n))
    {
        printf("%03lld\n", qpow(5, n, 1000));
    }
    return 0;
}