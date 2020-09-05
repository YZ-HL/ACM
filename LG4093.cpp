#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 200005
#define int long long
using namespace std;
int n;
struct Build{
    int t1;
    int t2;
} B[maxn];
bool operator < (const Build &A, const Build &B){
    return A.t1 < B.t1;
}
priority_queue<Build> q1;
bool cmp(const Build &A, const Build &B){
    return A.t2 < B.t2;
}
signed main(void)
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld %lld", &B[i].t1, &B[i].t2);
    sort(B+1, B+n+1, cmp);
    int tim = 0, ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(tim + B[i].t1 > B[i].t2)
        {
            if(!q1.empty() && B[i].t1 < q1.top().t1)
            {
                if(tim - q1.top().t1 + B[i].t1 <= B[i].t2)
                {
                    tim += B[i].t1-q1.top().t1;
                    q1.pop();
                    q1.push(B[i]);
                }
            }
            continue;
        }
        tim += B[i].t1;
        q1.push(B[i]);
        ans++;
    }
    printf("%lld\n", ans);
    system("pause");
    return 0;
}
