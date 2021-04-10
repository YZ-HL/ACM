#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int t, n, w;
int po[maxn], lg[maxn], now[maxn];
struct Node{
    int h;
    int wid;
    int pie;
};
bool operator < (const Node &A, const Node &B){
    if(A.h == B.h)
        return A.wid > B.wid;
    return A.h < B.h;
}
int main(void)
{
    for(int i = 1, j = 0; i <= (int)1e6; i *= 2, j++)    po[j] = i, lg[i] = j;
    scanf("%d", &t);
    while(t--)
    {
        priority_queue<Node> q1;
        scanf("%d %d", &n, &w);
        for(int i = 0; i <= log2(w) + 1; i++)    now[i] = 0;
        for(int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            now[lg[tmp]]++;
        }
        for(int i = 0; i <= log2(w) + 1; i++)
        {
            if(now[i])
            {
                q1.push((Node){now[i], po[i], 1});
                w -= po[i];
            }
        }
        while(1)
        {
            Node tmp = q1.top();
            if(tmp.wid > w || tmp.h == 1)    break;
            q1.pop();
            int nowp = tmp.pie + 1;
            int nowv = (now[lg[tmp.wid]] + nowp - 1) / nowp;
            int rv = now[lg[tmp.wid]] - nowv * (nowp - 1);
            q1.push((Node){max(nowv, rv), tmp.wid, nowp});
            w -= tmp.wid;
        }
        printf("%d\n", q1.top().h);
    }
    return 0;
}
