#include <bits/stdc++.h>
#define mod 9973
using namespace std;
void exgcd(int a, int b, int &x, int &y){
    if(!b)
    {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    int t = x;
    x = y; y = t - (a / b) * y;
}
int main(void)
{
    int t, n, b, x, y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &b);
        exgcd(b, mod, x, y);
        printf("%d\n", (n * (((x % mod) + mod) % mod)) % mod);
    }
    return 0;
}