#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int t, n, m, x;
int ans[maxn];
struct Node{
    int pos;
    int hei;
};
bool operator < (const Node &A, const Node &B){
    return A.hei > B.hei;
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        priority_queue<Node> q1;
        scanf("%d %d %d", &n, &m, &x);
        for(int i = 1; i <= m; i++)    q1.push((Node){i, 0});
        for(int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            Node now = q1.top(); q1.pop();
            ans[i] = now.pos;
            q1.push((Node){now.pos, now.hei + tmp});
        }
        printf("YES\n");
        for(int i = 1; i <= n; i++)
            printf(i == n ? "%d\n" : "%d ", ans[i]);
    }
    return 0;
}
