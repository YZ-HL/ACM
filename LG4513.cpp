#include <bits/stdc++.h>
#define maxn 4000005
#define lson(x) (x << 1)
#define rson(x) (x << 1) + 1
#define INF (1 << 30)
using namespace std;
int n, m, k, a[maxn];
struct SegTree{
    int lf;
    int rt;
    int val;
    int mx, lmax, rmax;
    SegTree() : lf(), rt(), val(), mx(), lmax(), rmax() {}
    SegTree(int lf, int rt, int val, int mx, int lmax, int rmax) : lf(lf), rt(rt), val(val), mx(mx), lmax(lmax), rmax(rmax) {}
} tree[maxn];
void Pushup(int now, SegTree t[]){
    t[now].val = t[lson(now)].val + t[rson(now)].val;
    t[now].lmax = max(t[lson(now)].lmax, t[lson(now)].val + t[rson(now)].lmax);
    t[now].rmax = max(t[rson(now)].rmax, t[rson(now)].val + t[lson(now)].rmax);
    t[now].mx = max(max(t[lson(now)].mx, t[rson(now)].mx), t[lson(now)].rmax + t[rson(now)].lmax);
}
void Build(int now, int lf, int rt, SegTree t[]){
    t[now].lf = lf;
    t[now].rt = rt;
    if (lf == rt)
    {
        t[now].val = t[now].lmax = t[now].rmax = t[now].mx = a[lf];
        return;
    }
    int mid = (lf + rt) / 2;
    Build(lson(now), lf, mid, t);
    Build(rson(now), mid + 1, rt, t);
    Pushup(now, t);
}
void Update(int now, int pos, int k, SegTree t[]){
    if (t[now].lf == pos && t[now].rt == pos)
    {
        t[now].val = t[now].lmax = t[now].rmax = t[now].mx = k;
        return;
    }
    if (t[now].rt < pos || t[now].lf > pos)
    {
        return;
    }
    Update(lson(now), pos, k, t);
    Update(rson(now), pos, k, t);
    Pushup(now, t);
}
SegTree Query(int now, int lf, int rt, SegTree t[]){
    if (lf <= t[now].lf && rt >= t[now].rt)
    {
        return t[now];
    }
    if (lf > t[now].rt || rt < t[now].lf)
    {
        return SegTree(lf, rt, 0, -INF, -INF, -INF);
    }
    SegTree res = SegTree(lf, rt, 0, -INF, -INF, -INF);
    SegTree tmpl = Query(lson(now), lf, rt, t);
    SegTree tmpr = Query(rson(now), lf, rt, t);
    res.val = tmpl.val + tmpr.val;
    res.lmax = max(tmpl.lmax, tmpl.val + tmpr.lmax);
    res.rmax = max(tmpr.rmax, tmpr.val + tmpl.rmax);
    res.mx = max(max(tmpl.mx, tmpr.mx), tmpl.rmax + tmpr.lmax);
    return res;
}
int main(void)
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Build(1, 1, n, tree);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &k);
        if (k == 1)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            if (a > b)
                swap(a, b);
            printf("%d\n", Query(1, a, b, tree).mx);
        }
        else
        {
            int p, s;
            scanf("%d %d", &p, &s);
            Update(1, p, s, tree);
        }
    }
    return 0;
}