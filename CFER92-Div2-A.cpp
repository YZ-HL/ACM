#include <bits/stdc++.h>
using namespace std;
long long lf, rt;
int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld %lld", &lf, &rt);
        //printf("%lld %lld\n", lf, rt);
        if(lf*2 > rt)
            printf("%d %d\n", -1, -1);
        else
            printf("%lld %lld\n", lf, 2 * lf);
    }
    //system("pause");
    return 0;
}