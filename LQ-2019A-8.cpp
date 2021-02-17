#include <bits/stdc++.h>
#define maxn 1100005
using namespace std;
set<int> s1;
int n, maxx, a[maxn], ans[maxn];
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]), maxx = max(maxx, a[i]);
    for(int i = 1; i <= maxx + n + 5; i++)  s1.insert(i);
    for(int i = 1; i <= n; i++)
    {
        if(s1.count(a[i]))
        {
            ans[i] = a[i];
            s1.erase(a[i]);
        }
        else
        {
            int now = *(s1.upper_bound(a[i]));
            s1.erase(now);
            ans[i] = now;
        }
    }
    for(int i = 1; i <= n; i++)
        printf(i == n ? "%d\n" : "%d ", ans[i]);
    return 0;
}
