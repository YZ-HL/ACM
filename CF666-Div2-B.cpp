#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
#define int long long
using namespace std;
int n;
int sum;
int a[maxn];
signed main(void)
{    
    scanf("%lld", &n);
    long long minn = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
        minn += (a[i]-1);
    } 
    sort(a+1, a+n+1);
    for(int c = 2; ;c++)
    {
        int cost_s = 0, flag = 0, bas = 1;
        for(int j = 1; j <= n; j++)
        {
            if(bas > 1e16)  flag = 1;
            cost_s += abs(a[j]-bas);
            bas *= c;
        }
        if(minn < cost_s || flag)
            break;
        minn = cost_s;
    }
    printf("%lld\n", minn);
    system("pause");
    return 0;
}
