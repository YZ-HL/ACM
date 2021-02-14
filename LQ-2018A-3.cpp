#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int num[maxn];
void calc(int x){
    int r = x;
    for(int i = 2; i <= r; i++)
        while(x % i == 0)   
        {
            x /= i;
            num[i]++;
            //printf("debug: %d, %d\n", i, num[i]);
        }
}
signed main(void)
{
    srand(time(NULL));
    int res = 1;
    for(int i = 1; i <= 100; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        calc(tmp);
        res *= tmp;
    }
    printf("%lld %lld %lld\n", num[2], num[5], min(num[2], num[5]));
}