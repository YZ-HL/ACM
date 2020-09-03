#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", !(a&b) ? 1 : a&b);
    }
    //system("pause");
    return 0;
}
