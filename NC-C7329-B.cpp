#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
#define int long long
using namespace std;
int a[maxn], sum[maxn];
int n, xx, yy;
long long ans;
bool cmp(const int &A, const int &B){
    return A > B;
}
signed main(void)
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    scanf("%lld %lld", &xx, &yy);
    sort(a+1, a+n+1, cmp);
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + a[i];
    for(int i = 1; i <= xx; i++)
        for(int j = 1; j <= yy; j++)
            ans += sum[i*j];
    printf("%lld\n", ans);
    //system("pause");
    return 0;
}
