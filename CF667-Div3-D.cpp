#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int check_sum(long long x){
    int sum = 0;
    while(x)
    {
        sum += x%10;
        x /= 10;
    }
    return sum;
}
int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        long long n, s, ans = 0, bas = 10;
        scanf("%lld %lld", &n, &s);
        while(check_sum(n) > s)
        {
            ans += bas-(n % bas);
            n += bas-(n % bas);
            bas *= 10;
        }
        printf("%lld\n", ans);
    }
    system("pause");
    return 0;
}
