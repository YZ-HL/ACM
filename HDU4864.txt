#include <bits/stdc++.h>
#define maxn 300005
using namespace std;
int n, m, c[maxn];
struct des{
    int maxt;
    int level;
} a[maxn], t[maxn];
bool cmp(const des &A, const des &B){
    if(A.maxt != B.maxt)    return A.maxt > B.maxt;
    return A.level > B.level;
}
int main(void)
{
    while(~scanf("%d %d", &n, &m))
    {
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= n; i++)
            scanf("%d %d", &a[i].maxt, &a[i].level);
        for(int i = 1; i <= m; i++)
            scanf("%d %d", &t[i].maxt, &t[i].level);
        sort(a+1, a+n+1, cmp);
        sort(t+1, t+m+1, cmp);
        long long ans = 0, num = 0;
        for(int i = 1, j = 1; i <= m; i++)
        {
            while(a[j].maxt >= t[i].maxt && j <= n)
            {
                c[a[j].level]++;
                j++;
            }
            for(int k = t[i].level; k <= 100; k++)
            {
                if(c[k])
                {
                    c[k]--;
                    ans += 500 * t[i].maxt + 2 * t[i].level;
                    num++;
                    break;
                }
            }
        }
        printf("%lld %lld\n", num, ans);
    }
    return 0;
}