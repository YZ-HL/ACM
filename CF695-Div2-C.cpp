#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n1, n2, n3;
int a[maxn], b[maxn], c[maxn];
int sum1, sum2, sum3, maxx1, maxx2, maxx3;
int main(void)
{
    scanf("%d %d %d", &n1, &n2, &n3);
    for(int i = 1; i <= n1; i++)
    {
        scanf("%d", &a[i]);
        sum1 += a[i];
        maxx1 = max(maxx1, a[i]);
    }
    for(int i = 1; i <= n2; i++)
    {
        scanf("%d", &b[i]);
        sum2 += b[i];
        maxx2 = max(maxx2, b[i]);
    }
    for(int i = 1; i <= n3; i++)
    {
        scanf("%d", &c[i]);
        sum3 += c[i];
        maxx3 = max(maxx3, c[i]);
    }
    if(sum1 <= sum2 && sum1 <= sum3)
    {
        printf("%d\n", sum2 + sum3 - sum1);
    }
    else if(sum2 <= sum1 && sum2 <= sum3)
    {
        printf("%d\n", sum1 + sum3 - sum2);
    }
    else if(sum3 <= sum2 && sum3 <= sum1)
    {
        printf("%d\n", sum1 + sum2 - sum3);
    }
    return 0;
}
