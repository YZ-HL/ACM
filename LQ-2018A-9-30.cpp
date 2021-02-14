#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, r, maxx, a[maxn];
int main(void)
{
    scanf("%d %d", &n, &r);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            for(int k = j + 1; k <= n; k++)
            {
                if((a[i] + a[j] + a[k]) % r == 0)
                {
                    maxx = max(maxx, a[i] + a[j] + a[k]);
                }
            }   
    printf("%d\n", maxx);
    return 0;
}