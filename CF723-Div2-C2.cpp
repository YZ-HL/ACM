#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int n, sum, a[maxn];
priority_queue<int, vector<int>, greater<int> > q1;
signed main(void)
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++)
    {
        q1.push(a[i]);
        sum += a[i];
        while(sum < 0)
        {
            sum -= q1.top();
            q1.pop();
            //printf("%d\n", sum);
        }
    }
    printf("%lld\n", q1.size());
    return 0;
}