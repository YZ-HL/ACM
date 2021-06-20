#include <bits/stdc++.h>
#define int long long
#define maxn 1000005
using namespace std;
int n, m, K;
struct Node{
    int n, nowm;
    int g;
};
bool operator < (const Node &A, const Node &B){
    return A.g < B.g;
}
priority_queue<Node> q1;
signed main(void)
{
    scanf("%lld %lld %lld", &n, &m, &K);
    for(int i = 1; i <= n; i++)
        q1.push((Node){i, m, i * m});
    int cnt = 0, now = -1;
    while(cnt < K)
    {
        cnt++;
        Node tmp = q1.top(); q1.pop();
        now = tmp.g;
        q1.push((Node){tmp.n, tmp.nowm - 1, tmp.n * (tmp.nowm - 1)});
    }
    printf("%lld\n", now);
}