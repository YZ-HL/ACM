#include <bits/stdc++.h>
#define maxn 4000005
#define lson(x) (x << 1)
#define rson(x) (x << 1) + 1
using namespace std;
int t, n, q, cases;
struct SegTree{
    int lf;
    int rt;
    int val;
    int lazy;
} tree[maxn];
void Build(int now, int lf, int rt){
    tree[now].lf = lf;
    tree[now].rt = rt;
    tree[now].lazy = 0;
    if (tree[now].lf == tree[now].rt)
    {
        tree[now].val = 1;
        return;
    }
    int mid = (lf + rt) / 2;
    Build(lson(now), lf, mid);
    Build(rson(now), mid + 1, rt);
    tree[now].val = tree[lson(now)].val + tree[rson(now)].val;
}
void Pushdown(int now){
    int mid = (tree[now].lf + tree[now].rt) / 2;
    tree[lson(now)].val = (mid - tree[now].lf + 1) * tree[now].lazy;
    tree[rson(now)].val = (tree[now].rt - mid) * tree[now].lazy;
    tree[lson(now)].lazy = tree[now].lazy;
    tree[rson(now)].lazy = tree[now].lazy;
    tree[now].lazy = 0;
}
void Add(int now, int lf, int rt, int k){
    if(lf <= tree[now].lf && rt >= tree[now].rt)
    {
        tree[now].val = (tree[now].rt - tree[now].lf + 1) * k;
        tree[now].lazy = k;
        return;
    }
    if(lf > tree[now].rt || rt < tree[now].lf)
        return;
    if(tree[now].lazy)    Pushdown(now);
    Add(lson(now), lf, rt, k);
    Add(rson(now), lf, rt, k);
    tree[now].val = tree[lson(now)].val + tree[rson(now)].val;
}
int Query(int now, int lf, int rt){
    if(lf <= tree[now].lf && rt >= tree[now].rt)
        return tree[now].val;
    if(lf > tree[now].rt || rt < tree[now].lf)
        return 0;
    if(tree[now].lazy)    Pushdown(now);
    return Query(lson(now), lf, rt) + Query(rson(now), lf, rt);
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);  Build(1, 1, n);
        scanf("%d", &q);
        for(int i = 1; i <= q; i++)
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            Add(1, x, y, z);
        }
        printf("Case %d: The total value of the hook is %d.\n", ++cases, Query(1, 1, n));
    }
    return 0;
}
