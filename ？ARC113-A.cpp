#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int k, ans, cp[maxn], sum[maxn];
int main(void)
{
    scanf("%d", &k);
    for(int i = 1; i * i <= k; i++)    cp[i * i] = 1; 
    for(int i = 1; i <= k; i++)
    {
        int num = 0;
        for(int j = 1; j * j <= k / i; j++)
            if(i % j == 0)    num++;
        num *= 2;
        if(cp[k / i])   num--;
        printf("%d %d\n", i, num);
        sum[i] = sum[i - 1] + num;
    }
    int ans = 0;
    for(int i = 1; i <= k; i++)
        ans += sum[k / i], printf("%d %d\n", i, ans);
    printf("%d\n", ans);
    return 0;
}
