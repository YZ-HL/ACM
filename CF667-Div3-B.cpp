#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
#define int long long
using namespace std;
int solve(int a, int b, int x, int y, int n, int dec1){
    if(dec1)
        if(b-n < y)
        {
            n -= (b-y);
            b = y;
        }
        else
        {
            b -= n;
            n = 0;
        }
    if(!dec1)
        if(a-n < x)
        {
            n -= (a-x);
            a = x;
        }
        else
        {
            a -= n;
            n = 0;
        }
    if(dec1 && n)
        a = max(a-n, x);
    if(!dec1 && n)
        b = max(b-n, y);
    return a*b;
}
signed main(void)
{
    int T;
    scanf("%lld", &T);
    while(T--)
    {
        int a, b, x, y, n;
        scanf("%lld %lld %lld %lld %lld", &a, &b, &x, &y, &n);
        //int dec1 = ((a == b && y < x) || a > b) ? 1 : 0;
        printf("%lld\n", min(solve(a, b, x, y, n, 0), solve(a, b, x, y, n, 1)));
    }
    system("pause");
    return 0;
}
