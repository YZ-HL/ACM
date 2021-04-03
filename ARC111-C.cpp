#include <bits/stdc++.h>
#define maxn 400005
using namespace std;
int n, pcnt, acnt, a[maxn], b[maxn], p[maxn], nx[maxn], vis[maxn];
pair<int, int> ans[maxn];
struct pe{
    int pos;
    int wei;
}np[maxn];
bool cmp(const pe &A, const pe &B){
    return A.wei < B.wei;
}
void dfs(int x){
    if(vis[x])
    {
        sort(np + 1, np + pcnt + 1, cmp);
        for(int i = 1; i <= pcnt; i++)
        {
            int now = np[i].pos, nxt = nx[np[i].pos];
            if(now == nxt)    continue;
            swap(p[now], p[nxt]);
            nx[p[now]] = now;
            nx[p[nxt]] = nxt;
            ans[++acnt] = make_pair(now, nxt);
        }
    }
    else
    {
        vis[x] = 1;
        np[++pcnt] = (pe){x, a[x]};
        dfs(p[x]);
    }
}
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    int flag = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
        nx[p[i]] = i;
        if(a[i] <= b[p[i]] && i != p[i])    flag = 1;
    }
    if(flag)    
    {
        printf("-1\n");
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        pcnt = 0;
        if(!vis[i])    dfs(i);
    }
    printf("%d\n", acnt);
    for(int i = 1; i <= acnt; i++)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}
