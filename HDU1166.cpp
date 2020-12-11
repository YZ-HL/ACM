#include <bits/stdc++.h>
#define maxn 400005
#define lson(x) (x << 1)
#define rson(x) (x << 1) + 1
using namespace std;
int t, n, cases, a[maxn];
struct SegTree{
    int lf;
    int rt;
    int val;
} tree[maxn];
void Build(int now, int lf, int rt){
    tree[now].lf = lf;
    tree[now].rt = rt;
    if (tree[now].lf == tree[now].rt)
    {
        tree[now].val = a[tree[now].lf];
        return;
    }
    int mid = (lf + rt) / 2;
    Build(lson(now), lf, mid);
    Build(rson(now), mid + 1, rt);
    tree[now].val = tree[lson(now)].val + tree[rson(now)].val;
}
int Query(int now, int lf, int rt){
    if (lf <= tree[now].lf && rt >= tree[now].rt)
        return tree[now].val;
    if (lf > tree[now].rt || rt < tree[now].lf)
        return 0;
    return Query(lson(now), lf, rt) + Query(rson(now), lf, rt);
}
void Update(int now, int lf, int rt, int k){
    if (lf > tree[now].rt || rt < tree[now].lf)     return;
    if (lf >= tree[now].lf && rt <= tree[now].rt)   tree[now].val += k;
    Update(lson(now), lf, rt, k); 
    Update(rson(now), lf, rt, k);
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        printf("Case %d:\n", ++cases);
        Build(1, 1, n);
        string str;
        while(cin >> str)
        {
            if(str == "End")    break;
            int x, k;
            scanf("%d %d", &x, &k);
            if(str == "Add")
                Update(1, x, x, k);
            else if(str == "Sub")
                Update(1, x, x, -k);
            else
                printf("%d\n", Query(1, x, k));
        }
    }
    return 0;
}
