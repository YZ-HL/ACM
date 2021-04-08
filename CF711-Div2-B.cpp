#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int t, n, w, ans, maxx, pows[maxn], val[maxn], now[maxn];
struct Node{
    int wid;
    int maxh;
    int pien;
};
bool operator < (const Node &A, const Node &B){
    if(A.maxh == B.maxh)
        return A.wid > B.wid;
    return A.maxh < B.maxh;
}
int main(void)
{
    scanf("%d", &t);
    for(int i = 1, j = 0; i <= (int)1e6; i *= 2, j++)    
        pows[i] = j, val[j] = i;
    while(t--)
    {
        priority_queue<Node> q1;
        scanf("%d %d", &n, &w);
        maxx = log2(w) + 1;
        for(int i = 1; i <= maxx; i++)    now[i] = 0;
        for(int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            now[pows[tmp]]++;
        }
        for(int i = 0; i <= maxx; i++)
        {
            if(now[i])  
            {
                q1.push((Node){val[i], now[i], 1});
                w -= val[i];
            }
        }
        while(1)
        {
            //printf("%d %d\n", q1.top().num, q1.top().wid);
            Node maxh = q1.top();
            if(maxh.wid > w)    break;
            q1.pop();

            int cand = maxh.pien + w / maxh.wid;
        
            int second_val;

            if(q1.empty())
                second_val = 1;
            else
                second_val = q1.top().maxh;

            int neard = (now[pows[maxh.wid]] + second_val - 1) / second_val;

            int nowd = min(cand, max(maxh.pien + 1, neard));
            
            int nowval = (now[pows[maxh.wid]] + nowd - 1) / nowd;

            int rval = now[pows[maxh.wid]] - nowval * (nowd - 1);

            if(nowd == 1)   rval = 0;

            q1.push((Node){maxh.wid, max(nowval, rval), nowd});

            //Node tmp = (Node){maxh.wid, max(nowval, rval), nowd};
            //printf("debug: %d %d %d\n", tmp.wid, tmp.maxh, tmp.pien);
            //printf("debug: %d %d %d\n", q1.top().wid, q1.top().maxh, q1.top().pien);
            /*
            printf("debug: %d %d %d %d\n", w, (nowd - maxh.pien) * maxh.wid, nowval, rval);

            printf("debug: %d %d\n", q1.top().wid, q1.top().maxh);
            */

            w -= (nowd - maxh.pien) * maxh.wid;
        }
        printf("%d\n", q1.top().maxh);
    }
    return 0;
}
