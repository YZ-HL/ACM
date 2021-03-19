#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
long long n;
int main(void)
{
    scanf("%lld", &n);
    printf("%lld\n", n + n * (n + 1) / 2);
    return 0;
}
//11 12 13 14 15