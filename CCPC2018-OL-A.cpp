#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 100005
#define int long long
using namespace std;
int n, a[maxn];
struct Node{
    int val;
    int stu;
};
bool operator < (const Node &A, const Node &B){
    if(A.val != B.val)
        return A.val > B.val;
    return A.stu < B.stu; 
}
priority_queue<Node> q1;
signed main(void)
{
    int T;
    scanf("%lld", &T);
    while(T--)
    {
        while(!q1.empty())  q1.pop();
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        int ans = 0, cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!q1.empty() && a[i] > q1.top().val)
            {
                cnt += 2;
                ans += a[i] - q1.top().val;
                if(q1.top().stu)    cnt -= 2;
                q1.pop();
                q1.push((Node){a[i], 1});
            }
            q1.push((Node){a[i], 0});
        }
        printf("%lld %lld\n", ans, cnt);
    }
    system("pause");
    return 0;
}
