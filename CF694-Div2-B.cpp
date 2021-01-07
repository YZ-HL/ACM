#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int t, n, x, a[maxn];
struct Node{
    int x;
    int cnt;
};
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &x);
        int sum = 0;
        queue<Node> q1;
        for(int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%lld", &tmp);
            q1.push((Node){tmp, 1});
        }
        while(!q1.empty())
        {
            Node now = q1.front();
            q1.pop();
            
            //printf("debug: %lld %lld\n", now.x, now.cnt);
            
            if(now.cnt == -1)
                break;

            sum += now.x * now.cnt;
            
            if(now.x % x == 0)
                q1.push((Node){now.x / x, now.cnt *x});
            else
                q1.push((Node){0, -1});
        }
        printf("%lld\n", sum);
    }
    return 0;
}
