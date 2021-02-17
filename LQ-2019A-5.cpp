#include <bits/stdc++.h>
#define int unsigned long long
#define ull unsigned long long
using namespace std;
unsigned long long now = 1001733993063167141;
void exgcd(int a, int b, int &x, int &y){
    if(b == 0)
    {
        x = 1; y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    int tmp = x;
    x = y;
    y = tmp - a / b * x;
}
__int128 a;
__int128 qpow(__int128 a, __int128 b, __int128 p){
    if(b == 0)
    {
        return 1;
    }
    __int128 tmp = qpow(a, b / 2, p);
    tmp = ((tmp % p) * (tmp % p)) % p;
    if(b & 1)   tmp = (tmp * a) % p;
    return tmp;
}
void print(__int128 now){
    if(now > 9)    print(now / 10);
    putchar(now % 10 + '0');
}
signed main(void)
{
    //int x = 0, y = 0;
    //exgcd(212353, 1001733991047948000, x, y);
    //printf("%lld %lld %lld\n", x, y, 1001733991047948000);
    __int128 ans = qpow(20190324, 823816093931522017, 1001733993063167141);
    print(ans);
    return 0;
}

//p = 891234941, q = 1123984201
//e = 823816093931522017‬