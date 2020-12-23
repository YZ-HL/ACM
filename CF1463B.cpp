#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
long long t, n, s, now, b[maxn];
struct seq{
    long long val;
    long long pos;
} a[maxn];
bool operator < (const seq &A, const seq &B){
    return A.val < B.val;
}
int main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        now = 1;
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i].val), a[i].pos = i;
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++)
        {
            while(now * 2 < a[i].val)   now *= 2;
            b[a[i].pos] = now;
        }
        for(int i = 1; i <= n; i++)
            printf(i == n ? "%lld\n" : "%lld ", b[i]);
    }
    return 0;
}
