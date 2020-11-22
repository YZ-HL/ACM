#include <bits/stdc++.h>
using namespace std;
long long a, b;
int main(void)
{
    while (~scanf("%lld %lld", &a, &b))
    {
        if(a > b)    swap(a, b);
        long long c = b - a;
        long long ans = c * (1.0 + sqrt(5.0)) / 2;
        printf("%lld\n", ans == a ? 0 : 1);
    }
    return 0;
}