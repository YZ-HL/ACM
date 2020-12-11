#include <bits/stdc++.h>
#define lson(x) (x << 1)
#define rson(x) (x << 1) + 1
#define maxn 100005
using namespace std;
int n, ans, a[maxn], cnt[maxn];
struct SegTree{
    int lf;
    int rt;
    int val;
} tree[maxn];
void Build(int now, int lf, int rt, SegTree t[])
{
    t[now].lf = lf;
    t[now].rt = rt;
    if (t[now].lf == t[now].rt)
    {
        t[now].val = 0;
        return;
    }
    int mid = (lf + rt) / 2;
    Build(lson(now), lf, mid, t);
    Build(rson(now), mid + 1, rt, t);
}
int Query(int now, int lf, int rt, SegTree t[]){
    if(lf <= t[now].lf && rt >= t[now].rt)
        return t[now].val;
    if(lf > t[now].rt || rt < t[now].lf)
        return 0;
    return Query(lson(now), lf, rt, t) + Query(rson(now), lf, rt, t);
}
void Update(int now, int lf, int rt, int k, SegTree t[]){
    if(lf >= t[now].lf && rt <= t[now].rt)
        t[now].val += k;
    if(lf > t[now].rt || rt < t[now].lf)
        return;
    Update(lson(now), lf, rt, k, t);
    Update(rson(now), lf, rt, k, t);
}
int main(void)
{
    while(~scanf("%d", &n))
    {
        ans = 0;
        memset(tree, 0, sizeof(tree));
        Build(1, 1, n, tree);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]); a[i]++;
            ans += Query(1, a[i], n, tree);
            Update(1, a[i], a[i], 1, tree);
        }
        int minn = ans;
        for(int i = 1; i <= n; i++)
        {
            //printf("%d\n", ans);
            //printf("%d %d %d\n", i, Query(1, 1, a[i] - 1, tree), Query(1, a[i] + 1, n, tree));
            ans = ans - Query(1, 1, a[i] - 1, tree) + Query(1, a[i] + 1, n, tree);
            minn = min(minn, ans);
        }
        printf("%d\n", minn);
    }
    return 0;
}
