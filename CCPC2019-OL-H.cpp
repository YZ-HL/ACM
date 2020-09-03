#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 100005
using namespace std;
int n, k, a[maxn];
bool cmp(const int &A, const int &B){
    return A > B;
}
int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        long long bas = 1, tim = 0;
        scanf("%d %d", &n, &k);
        tim += k;
        for(int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            tim += tmp;
            bas += tmp / k;
            a[i] = tmp % k;
        }
        sort(a+1, a+n+1, cmp);
        if(bas >= n)
            printf("%lld\n", tim);
        else
        {
            int cnt = n-bas;
            for(int i = 1; i <= cnt; i++)
                tim += k-a[i];
            printf("%lld\n", tim);
        }
    }
    system("pause");
    return 0;
}
